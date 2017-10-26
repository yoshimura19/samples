// 練習問題  クリッピングパスの設定（縦じまに円形のクリッピング）
import java.awt.*;
import java.awt.geom.*;
import javax.swing.*;  
public class ClipDraw2 extends JPanel{
   GeneralPath path;
   int w=200, h=200;
   int shima = 5; // 縦じまの幅
   int x, y, r=50;
   public ClipDraw2(){  
      setPreferredSize(new Dimension(w, h));
      path = new GeneralPath(); //空のパスを生成      
      Ellipse2D maru;
      for(int i=0; i<w/r; i++){
         x = r*i;
         for(int j=0; j<h/r; j++){
            y = r*j;
            maru = new Ellipse2D.Double(x, y, r, r); 
            path.append(maru, false); //パスを追加
         }
      }
   }

   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      Graphics2D g2 = (Graphics2D) g;
      g2.setClip(path);  //クリッピングパスの設定
      for(int i=0; i<w/shima; i++){
	  g.fillRect(shima+i*(shima*2), 0, shima, h);
      }
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Set clip and draw");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      ClipDraw2 h = new ClipDraw2();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }   
}
