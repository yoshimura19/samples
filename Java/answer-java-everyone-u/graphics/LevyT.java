import java.awt.*;
import java.awt.image.*;
import javax.swing.*;

public class LevyT extends JPanel{
   static int N = 15;               // 繰返し回数
   final int W = 600, H = 600, X1 = 200, Y1 = 400, X2 = 400, Y2 = 400;
   BufferedImage bi;
   Graphics bg;
   LevyT() {
      setPreferredSize(new Dimension(W, H)); 
      bi = new BufferedImage(W, H, BufferedImage.TYPE_INT_RGB);
      bg = bi.createGraphics();
      bg.setColor(Color.white); 
      bg.fillRect(0,0,W,H); 
      bg.setColor(Color.black); 
      levy(X1, Y1, X2, Y2, N);  // 再帰処理の開始
   }
   void levy(double ax, double ay, double bx, double by, int n){
      double cx = (bx + ax)/2 + (by-ay)/2;
      double cy = (by+ay)/2 - (bx - ax)/2;
      if(n==0){
	 int[] xx = new int[]{(int)ax,(int)bx,(int)cx};
	 int[] yy = new int[]{(int)ay,(int)by,(int)cy};
	 bg.fillPolygon(xx, yy, 3);
	 bg.drawPolygon(xx, yy, 3);
      }else{
	 levy(ax, ay, cx,cy, n-1);
	 levy(cx, cy, bx,by, n-1);
      }
   }
   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      g.drawImage(bi, 0, 0, this);
   }
   public static void main(String args[]){
      if(args.length > 0) N = Integer.parseInt(args[0]);
      JFrame frame  = new JFrame("LevyT");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      LevyT h = new LevyT();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
