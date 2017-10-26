//  練習問題 マウスドラッグに応じて線を引く
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DrawByMouse2 extends JPanel implements MouseListener, 
                                            MouseMotionListener {
   int x1, y1, x2, y2;
   public DrawByMouse2(){
      setBackground(Color.white);
      setPreferredSize(new Dimension(250, 250));
      addMouseListener(this);
      addMouseMotionListener(this);
   }

   protected void paintComponent(Graphics g){    
      super.paintComponent(g);
      g.drawLine(x1,y1,x2,y2);
   }
	
   public void mousePressed(MouseEvent e){ //マウスを押した時の処理
      x1 = e.getX();
      y1 = e.getY();
   }
   public void mouseDragged(MouseEvent e){ //マウスをドラッグした時の処理
      x2 = e.getX();
      y2 = e.getY();
      repaint();     //図形を描く
   }
   public void mouseMoved(MouseEvent e){   }
   public void mouseReleased(MouseEvent e){   }
   public void mouseClicked(MouseEvent e){   }
   public void mouseEntered(MouseEvent e){   }
   public void mouseExited(MouseEvent e){   }

   public static void main(String[] args){
      JFrame frame  = new JFrame("Draw Line");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      DrawByMouse2 e = new DrawByMouse2();
      frame.add(e, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}

