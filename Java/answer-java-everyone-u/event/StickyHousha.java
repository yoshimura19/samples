//練習問題 放射線の中央点がマウスでドラッグ
import java.awt.*; 
import javax.swing.*;
import java.awt.event.*;

public class StickyHousha extends JPanel implements MouseMotionListener{
   int centerX, centerY;
   public StickyHousha(){
      setBackground(Color.white);     
      setPreferredSize(new Dimension(250, 250));
      addMouseMotionListener(this);
      centerX = 125;
      centerY = 125;
   }

   protected void paintComponent(Graphics g){    
      super.paintComponent(g);
      int pX=getWidth()/2;  //パネルの中央で交差
      int pY=getHeight()/2;
      int x, y;
      double angle;
      for(int i=0; i<=360; i=i+30){
         angle = i*Math.PI/180;
         x = pX + (int)(100*Math.cos(angle));
         y = pY - (int)(100*Math.sin(angle));
         g.drawLine(centerX, centerY, x, y);
      }
   }
   public void mouseDragged(MouseEvent e){  
      centerX = e.getX();
      centerY = e.getY();
      repaint();
   }
   public void mouseMoved(MouseEvent e){   }
   public static void main(String[] args){
      JFrame frame  = new JFrame("Move Center");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      StickyHousha e = new StickyHousha();
      frame.add(e, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}
