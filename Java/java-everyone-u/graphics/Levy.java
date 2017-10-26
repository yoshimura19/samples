import java.awt.*;
import java.awt.geom.*;
import java.awt.image.*;
import javax.swing.*;

public class Levy extends JPanel{
   static int n = 15;               // 繰り返し回数
                                    // main の中で代入できるように，クラス変数にした。
   int m = 200;           // 1辺の長さ
   final int W = m * 3, H = m * 3;
   BufferedImage bi;
   Graphics2D bg;
   GeneralPath gp = new GeneralPath();
   Levy() {
      setPreferredSize(new Dimension(W, H)); 
      bi = new BufferedImage(W, H, BufferedImage.TYPE_INT_RGB);
      bg = (Graphics2D) bi.createGraphics();
      bg.fillRect(0,0,W,H); 
      bg.setColor(Color.black); 
      levy(m,2*m,2*m,2*m,n);
   }
   void levy(double ax, double ay, double bx, double by, int n){
      if(n==0){
	 bg.drawLine((int)ax,(int)ay,(int)bx,(int)by);
      }else{
	 double cx = (bx + ax)/2 + (by-ay)/2;
	 double cy = (by+ay)/2 - (bx - ax)/2;
	 levy(ax, ay, cx,cy, n-1);
	 levy(cx, cy, bx,by, n-1);
      }
   }
   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      g.drawImage(bi, 0, 0, this);
   }
   public static void main(String args[]){
      if(args.length > 0) n = Integer.parseInt(args[0]);
      JFrame frame = new JFrame();
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Levy h = new Levy();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
    }
}


