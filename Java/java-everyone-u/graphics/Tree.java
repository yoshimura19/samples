import java.awt.*;
import java.awt.image.*;
import javax.swing.*;

public class Tree extends JPanel{
   double scale = 0.7;        // 育つ枝の長さの比率
   int angle = 30;           // 枝の広がる角度（度単位）
   int N = 8;               // 繰返し回数
   final int W = 400, H = 400;
   double len = 100.0;    // 最初の枝の長さ
   BufferedImage bi;
   Graphics bg;
   Tree() {
      setPreferredSize(new Dimension(W, H)); 
      bi = new BufferedImage(W, H, BufferedImage.TYPE_INT_RGB);
      bg = bi.createGraphics();
      bg.setColor(Color.white);  
      bg.fillRect(0,0,W,H); 
      bg.setColor(new Color(100, 153, 0));  // 描画色の設定
      drawTree(W/2, H, len, 0, N);  // 再帰処理の開始 
   }
   void drawTree(double x1, double y1, double len, double stand, int n){
      double x2=x1 + len*Math.sin(Math.toRadians(stand));  //枝先のx座標
      double y2=y1 - len*Math.cos(Math.toRadians(stand));  //枝先のy座標
      bg.drawLine((int)x1,(int)y1,(int)x2,(int)y2); //線を描く
      if(n>=1){   //木の末端まで達していないときは，次の枝を描く
	 drawTree(x2,y2,len*scale,stand-angle,n-1); //次の右の枝を描く
	 drawTree(x2,y2,len*scale,stand+angle,n-1); //次の左の枝を描く
      }
   }
   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      g.drawImage(bi, 0, 0, this);
   }
   public static void main(String args[]){
      JFrame frame = new JFrame();
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Tree h = new Tree();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
    }
}

