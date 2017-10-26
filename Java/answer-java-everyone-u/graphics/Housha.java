// 練習問題  放射線
import java.awt.*; 
import javax.swing.*;

public class Housha extends JPanel {
   public Housha(){
      setBackground(Color.white);     
      setPreferredSize(new Dimension(250, 250));
   }

   protected void paintComponent(Graphics g){    
      super.paintComponent(g);
      int centerX=getWidth()/2;  //パネルの中央で交差
      int centerY=getHeight()/2;
      int x, y;
      double angle;
      for(int i=0; i<=360; i=i+30){
         angle = i*Math.PI/180;
	 x = centerX + (int)(100*Math.cos(angle));
	 y = centerY - (int)(100*Math.sin(angle));
	 g.drawLine(centerX, centerY, x, y);
      }
   }
   public static void main(String[] args){
      JFrame frame  = new JFrame("Housya Example");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Housha h = new Housha();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}
