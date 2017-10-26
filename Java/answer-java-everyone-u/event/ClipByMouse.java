// 練習問題 　マウスドラッグでクリップする円の位置が動く
import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import javax.swing.*;  
import java.io.*;
import javax.imageio.*;  

public class ClipByMouse extends JPanel{
   Image image;
   GeneralPath path;
   Ellipse2D maru ;
   int r = 100; //クリップする円の直径
   int x, y; //円の中心の位置
   public ClipByMouse(){  
      try{ image = ImageIO.read(new File("kame.jpg"));
      }catch(IOException e){}
      setPreferredSize(new Dimension(image.getWidth(this), 
                                     image.getHeight(this)));
      maru = new Ellipse2D.Double(); //円を生成
      path = new GeneralPath(); //空のパスを生成
      addMouseMotionListener(new ClipPosition());
      x = image.getWidth(this)/2;  //最初は中央
      y = image.getHeight(this)/2;
   }

   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      Graphics2D g2 = (Graphics2D) g;
      maru.setFrame(x-r/2, y-r/2, r, r);
      path.reset();    //パスを空にする
      path.append(maru, false);  //円をパスにする
      g2.setClip(path);  //クリッピングパスの設定
      g.drawImage(image, 0, 0, this); //画像を描く
   }

   class ClipPosition extends MouseMotionAdapter {//マウスドラッグの処理
      public void mouseDragged(MouseEvent e){ 
	  x = e.getX();
	  y = e.getY();
	  repaint();     
      }
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Move clip area");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      ClipByMouse h = new ClipByMouse();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }   
}
