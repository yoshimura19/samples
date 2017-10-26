// リスト12.5　クリッピングパスの設定
import java.awt.*;
import java.awt.geom.*;
import javax.swing.*;  
import java.io.*;
import javax.imageio.*;  
public class ClipDraw extends JPanel{
   Image image;
   GeneralPath path;
   public ClipDraw(){  
      setPreferredSize(new Dimension(250, 188));
      path = new GeneralPath(); //空のパスを生成
      Ellipse2D maru = new Ellipse2D.Double(20, 45, 100, 100); //円を生成
      path.append(maru, false); //円のパスを追加
      path.moveTo(170f, 30f); //三角形のパスを追加
      path.lineTo(100f, 170f); 
      path.lineTo(240f, 170f); 
      path.closePath(); 
      try{ image = ImageIO.read(new File("kame.jpg"));
      }catch(IOException e){}
   }

   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      Graphics2D g2 = (Graphics2D) g;
      g2.setClip(path);  //クリッピングパスの設定
      g.drawImage(image, 0, 0, this); //画像を描く
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Set clip and draw");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      ClipDraw h = new ClipDraw();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }   
}
