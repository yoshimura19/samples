import java.awt.*;
import java.awt.image.*;
import javax.swing.*;

public class LevyTiling extends JPanel{
   static int N = 15;               // 繰返し回数
   final int W = 600, H = 600, M = 200;
   BufferedImage bi;
   Graphics bg;
   LevyTiling() {
      setPreferredSize(new Dimension(W, H)); 
      bi = new BufferedImage(W, H, BufferedImage.TYPE_INT_RGB);
      bg = bi.createGraphics();
      bg.setColor(Color.white); 
      bg.fillRect(0,0,W,H); 
      bg.setColor(Color.black); 

      for(int i = 0; i < 3; i++){
	 for(int j = 0; j < 3; j++){
           // (i,j) の時，(i,j) の正方形の内側に４つ levy 曲線を描く。
	    bg.setColor(Color.getHSBColor((float)(i*3+j)/9,0.6f,0.6f));
	    levy(i*M, j*M, i*M, (j+1)*M, N);
	    bg.setColor(Color.getHSBColor((float)((i*3+j+2)%9)/9,0.8f,0.8f));
	    levy(i*M, (j+1)*M, (i+1)*M, (j+1)*M, N);
	    bg.setColor(Color.getHSBColor((float)((i*3+j+4)%9)/9,0.7f,0.7f));
	    levy((i+1)*M, (j+1)*M, (i+1)*M, j*M, N);
	    bg.setColor(Color.getHSBColor((float)((i*3+j+6)%9)/9,1.0f,1.0f));
	    levy((i+1)*M, j*M, i*M, j*M, N);
	 }
      }
      bg.setColor(Color.black);
      levy(M,2*M,2*M,2*M,N);   // 真ん中のだけ強調するため，黒色にする。
   }
   void levy(double ax, double ay, double bx, double by, int n){
      double cx = (bx + ax)/2 + (by-ay)/2;
      double cy = (by+ay)/2 - (bx - ax)/2;
      if(n==0){
         // 画面から外れているかは，重心でチェックするのが楽。
	 if (ax+bx+cx < 0){ ax += W; bx += W; cx += W;}
	 if (ax+bx+cx > 3*W){ ax -= W; bx -= W; cx -= W;}
	 if (ay+by+cy < 0){ ay += H; by += H; cy += H;}
	 if (ay+by+cy > 3*H){ ay -= H; by -= H; cy -= H;}

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
      JFrame frame  = new JFrame("LevyTiling");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      LevyTiling h = new LevyTiling();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
