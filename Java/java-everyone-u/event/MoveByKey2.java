//  リスト13.9 キー入力に応答するプログラム
//  画面に描画された黒丸が矢印キーによって上下左右に動く
//  registerKeyboardActionを使ったイベント処理

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class MoveByKey2 extends JPanel implements ActionListener{
   int x, y;     //座標
   int move = 2; //移動距離
   int r= 10;    //円の大きさ

   public MoveByKey2(){
      setBackground(Color.white);
      setPreferredSize(new Dimension(250, 250));//パネルの望むサイズを設定
      x = getPreferredSize().width/2;     //パネルの中央
      y = getPreferredSize().height/2;
      //キーアクションの登録 矢印キー
      registerKeyboardAction(this, "right", 
                             KeyStroke.getKeyStroke(KeyEvent.VK_RIGHT, 0),
                             JComponent.WHEN_FOCUSED);
      registerKeyboardAction(this, "left", 
                             KeyStroke.getKeyStroke(KeyEvent.VK_LEFT, 0),
                             JComponent.WHEN_FOCUSED);
      registerKeyboardAction(this, "down", 
                             KeyStroke.getKeyStroke(KeyEvent.VK_DOWN, 0),
                             JComponent.WHEN_FOCUSED);
      registerKeyboardAction(this, "up",
                             KeyStroke.getKeyStroke(KeyEvent.VK_UP, 0),
                             JComponent.WHEN_FOCUSED);
   }

   protected void paintComponent(Graphics g){    
      super.paintComponent(g);
      g.fillOval(x, y, r, r);
   }

   public void actionPerformed(ActionEvent e) {
      String com = e.getActionCommand();
      if (com.equals("right")) { x = x+move; }
      else if (com.equals("left")) { x = x-move; }
      else if (com.equals("up")) { y = y-move; }
      else if (com.equals("down")) { y = y+move; }
      repaint();
   }

   public static void main(String[] args){
      JFrame frame  = new JFrame("Move a circle");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      MoveByKey2 k = new MoveByKey2();
      frame.add(k, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}

