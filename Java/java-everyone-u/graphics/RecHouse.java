import java.awt.*;
import java.awt.image.*;
import javax.swing.*;

public class RecHouse extends JPanel{
   final int W = 650, H = 700;
   RecHouse() {
      setBackground(Color.white);  
      setPreferredSize(new Dimension(W, H)); 
   }
   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      drawHouse(g, 100, 300, 128, 1); 
      drawHouse(g, 100, 600, 128, 4); 
   }
   void drawHouse(Graphics g, int x, int y, int s, int n){
      drawFrame(g, x, y, s);
      if(n <= 1){
	 g.drawRect(x + s/2, y - s*7/10 , s, s/2);
      }else{
	 drawHouse(g, x + s/2, y - s/5, s/2, n-1);
      }
   }
   void drawFrame(Graphics g, int x, int y, int s){ 
      g.drawRect(x, y - s, s*2, s);
      g.drawPolygon(new int[]{x - s/2, x , x + s*2, x+s*5/2},
		    new int[]{y-s, y - s*3/2, y - s*3/2, y-s}, 4);
   }
   public static void main(String args[]){
      JFrame frame = new JFrame();
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      RecHouse h = new RecHouse();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}


/*
public class RecHouse extends JPanel{
   final int W = 650, H = 850;
   RecHouse() {
      setBackground(Color.white);  
      setPreferredSize(new Dimension(W, H)); 
   }
   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      drawHouse(g, 100, 200, 128, 0); 
      drawHouse(g, 100, 500, 128, 1); 
      drawHouse(g, 100, 800, 128, 4); 
   }
   void drawHouse(Graphics g, int x, int y, int s, int n){
      if(n <= 0){
	 g.drawRect(x, y - s , s * 2, s);
      }else{
	 drawFrame(g, x, y, s);
	 drawHouse(g, x + s/2, y - s/5, s/2, n-1);
      }
   }
   void drawFrame(Graphics g, int x, int y, int s){ 
      g.drawRect(x, y - s, s*2, s);
      g.drawPolygon(new int[]{x - s/2, x , x + s*2, x+s*5/2},
		    new int[]{y-s, y - s*3/2, y - s*3/2, y-s}, 4);
   }
   public static void main(String args[]){
      JFrame frame = new JFrame();
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      RecHouse h = new RecHouse();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
*/