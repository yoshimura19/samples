import java.awt.*;
import javax.swing.*;

public class RecHouse2 extends JPanel{
   final int W = 500, H = 400;
   RecHouse2() {
      setBackground(Color.white);  
      setPreferredSize(new Dimension(W, H)); 
      setMinimumSize(new Dimension(W, H)); 
   }
   protected void paintComponent(Graphics g){
      super.paintComponent(g); 
      drawHouse(g, 100, 300, 128, 4);
   }
   void drawHouse(Graphics g, int x, int y, int s, int n){
      drawFrame(g, x, y, s);
      if(n == 1){  
	 g.drawRect(x + s/2, y - s*7/10 , s, s/2);
      }else{
	 drawHouse(g, x + s/6, y - s/5, s/3, n-1);
	 drawHouse(g, x + s*7/6, y - s/5, s/3, n-1);
      }
   }
   void drawFrame(Graphics g, int x, int y, int s){
      g.drawRect(x, y - s, s*2, s);
      g.drawPolygon(new int[]{x - s/2, x , x + s*2, x+s*5/2},
		    new int[]{y-s, y - s*3/2, y - s*3/2, y-s}, 4);
   }

   public static void main(String args[]){
      JFrame frame  = new JFrame("Rec House2");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      RecHouse2 h = new RecHouse2();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}

