//  リスト13.8 キー入力に応答するプログラム
//  画面に描画された黒丸が矢印キーによって上下左右に動く

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MoveByKey extends JPanel implements KeyListener{
   int x, y;     //座標
   int move = 2; //移動距離
   int r= 10;    //円の大きさ
   public MoveByKey(){
      setBackground(Color.white);
      setPreferredSize(new Dimension(250, 250));//パネルの望むサイズを設定
      x = getPreferredSize().width/2;     //パネルの中央
      y = getPreferredSize().height/2;
      setFocusable(true);
      addKeyListener(this);
   }

   public void keyPressed(KeyEvent e){ 
      int k = e.getKeyCode();
      if(k == KeyEvent.VK_RIGHT) { x = x+move; }
      else if (k == KeyEvent.VK_LEFT) { x = x-move; }
      else if (k == KeyEvent.VK_DOWN) { y = y+move; }
      else if (k == KeyEvent.VK_UP) { y = y-move; }
      repaint();
   }
   public void keyReleased(KeyEvent e){ } 
   public void keyTyped(KeyEvent e){ }

   protected void paintComponent(Graphics g){    
      super.paintComponent(g);
      g.fillOval(x, y, r, r);
   }

   public static void main(String[] args){
      JFrame frame  = new JFrame("Move a circle");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      MoveByKey k = new MoveByKey();
      frame.add(k, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}

