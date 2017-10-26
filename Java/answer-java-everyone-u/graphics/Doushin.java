// 練習問題  同心円
import java.awt.*; 
import javax.swing.*;

public class Doushin extends JPanel {
   int centerX, centerY; // パネルの中心
   int x, y, r; 
   public Doushin(){
      setBackground(Color.white);     
      setPreferredSize(new Dimension(250, 250));
   }
   protected void paintComponent(Graphics g){    
      super.paintComponent(g);
      centerX=getWidth()/2;  //パネルの中央に円の中心を置く
      centerY=getHeight()/2;
      r=0;
      for(int i=1; i<=10; i++){
         r = i*20;
         x = centerX - r/2;
         y = centerY - r/2;
         g.drawOval(x, y, r, r);
      }
   }
   public static void main(String[] args){
      JFrame frame  = new JFrame("Circle Example");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Doushin h = new Doushin();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}
