// 練習問題  マウスドラッグとキー入力でクリップする円の位置が動く
import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import javax.swing.*;  
import java.io.*;
import javax.imageio.*;  

public class ClipByMouseKey extends JPanel implements ActionListener{
   Image image;
   GeneralPath path;
   Ellipse2D maru ;
   int r = 100; //クリップする円の直径
   int x, y; //円の中心の位置
   public ClipByMouseKey(){  
      try{ image = ImageIO.read(new File("kame.jpg"));
      }catch(IOException e){}
      setPreferredSize(new Dimension(image.getWidth(this), 
                                     image.getHeight(this)));
      maru = new Ellipse2D.Double(); //円を生成
      path = new GeneralPath(); //空のパスを生成
      addMouseMotionListener(new ClipPosition());
      x = image.getWidth(this)/2;  //最初は中央
      y = image.getHeight(this)/2;
      setKeyboard();
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

   public void actionPerformed(ActionEvent e) {
      String com = e.getActionCommand();
      if (com.equals("up")) { y -= 10; }
      else if (com.equals("down")) { y += 10; }
      else if (com.equals("right")) { x += 10; }
      else if (com.equals("left")) { x -= 10; }
      repaint();
   }

   void setKeyboard(){ //キーにコマンド名を指定
      registerKeyboardAction(this, "up", KeyStroke.getKeyStroke('u'),
				 JComponent.WHEN_IN_FOCUSED_WINDOW);
      registerKeyboardAction(this, "down", KeyStroke.getKeyStroke('d'),
				 JComponent.WHEN_IN_FOCUSED_WINDOW);
      registerKeyboardAction(this, "right", KeyStroke.getKeyStroke('r'),
				 JComponent.WHEN_IN_FOCUSED_WINDOW);
      registerKeyboardAction(this, "left", KeyStroke.getKeyStroke('l'),
				 JComponent.WHEN_IN_FOCUSED_WINDOW);
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Move clip area");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      ClipByMouseKey h = new ClipByMouseKey();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }   
}
