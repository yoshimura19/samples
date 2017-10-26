// リスト13.7  マウスクリックに応じて線を引くプログラム
// アダプターを使った内部リスナークラス
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DrawByMouseAd extends JPanel {
   int x1, y1, x2, y2;
   public DrawByMouseAd(){
      setBackground(Color.white);
      setPreferredSize(new Dimension(250, 250));
      addMouseListener(new MousePosition());
   }

   protected void paintComponent(Graphics g){    
      super.paintComponent(g);
      g.drawLine(x1,y1,x2,y2);
   }
	
   class MousePosition extends MouseAdapter{
      public void mousePressed(MouseEvent e){ //マウスを押した時の処理
	 x1 = e.getX();
	 y1 = e.getY();
      }
      public void mouseReleased(MouseEvent e){ //マウスを離した時の処理
	 x2 = e.getX();
	 y2 = e.getY();
	 repaint();     //ボタンを離した時、図形を描く
      }
   }
   public static void main(String[] args){
      JFrame frame  = new JFrame("Draw Line");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      DrawByMouseAd e = new DrawByMouseAd();
      frame.add(e, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}

