import java.awt.*;
import java.awt.image.*;
import javax.swing.*;

public class Circles extends JPanel{
   final int WW = 400, WH = 400;
   int X = 200, Y = 200, R = 150, N=6;
   Circles() {
      setBackground(Color.white);  
      setPreferredSize(new Dimension(WW, WH)); 
   }
   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      circles(g, X, Y, R, N);
   }
   double arand(){
      double x = Math.random();
      double y = Math.random();
      return (x+y)/2;
   }

   void circles(Graphics g, double x, double y, double r, int n){
      if(n <= 0) return;
      g.drawOval((int)(x - r), (int)(y - r), (int)r*2, (int)r*2);
      double tt = Math.random() * Math.PI;
      double r1 = r/2;
      circles(g, x + r1, y, r1, n-1);
      circles(g, x - r1, y, r1, n-1);
   }
   public static void main(String args[]){
      JFrame frame = new JFrame();
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Circles h = new Circles();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
