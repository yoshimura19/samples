import java.awt.*;
import java.awt.image.*;
import javax.swing.*;

public class Rectangles extends JPanel{
   final int WW = 400, WH = 400;
   int X = 50, Y = 100, W = 300, H = 200, N = 6;
   Rectangles() {
      setBackground(Color.white);  
      setPreferredSize(new Dimension(WW, WH)); 
   }
   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      g.drawRect(X, Y, W, H);
      rects(g, X, Y, W, H, N);
   }
   void rects(Graphics g, int x, int y, int w, int h, int depth){
      if(depth <= 0) return;
      if (w > h){
	 int m = (int)(Math.random() * w);
	 g.drawLine(x + m, y, x + m, y+h);
	 rects(g, x , y, m, h, depth-1);
	 rects(g, x + m, y, w - m, h, depth-1);
      }else{
	 int m = (int)(Math.random() * h);
	 g.drawLine(x, y + m, x+w, y + m);
	 rects(g, x , y, w, m, depth-1);
	 rects(g, x, y+m, w, h-m, depth-1);
      }
   }
   public static void main(String args[]){
      JFrame frame = new JFrame();
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Rectangles h = new Rectangles();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
