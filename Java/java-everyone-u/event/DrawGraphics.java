//リスト13.5  超簡易図形エディタの枠組み
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DrawGraphics extends JPanel implements ActionListener{
   DrawByMouse area;   //描画域のパネル
   JButton b1, b2, b3;
   final int RECT = 1;  final int OVAL = 2; final int LINE=3;
   int type = RECT;   //描く図形の種類, 初期値は四角
   public DrawGraphics(){
      //3つのボタンを生成，リスナーを設定
      //ボタンを置くパネルを作り，ボタンを配置
      //描画域を生成
      //描画域とボタンを置いたパネルを配置
   }

   public void actionPerformed(ActionEvent e) {
      //押されたボタンに応じて，typeにRECT, OVAL, LINEの値を設定
   }
   //描画域のパネル，内部クラスとして定義

   class DrawByMouse extends JPanel implements MouseListener, 
                                            MouseMotionListener {
      int x1, y1, x2, y2; //描画用の座標
      DrawByMouse(){
	 //背景色を設定，パネルサイズを設定，リスナーを設定
      }
      protected void paintComponent(Graphics g){    
	 //typeの値に応じて，四角，円，直線を描く。
      }
      public void mousePressed(MouseEvent e){ 
	 //マウスを押した時の処理
      }
      public void mouseDragged(MouseEvent e){ 
	 //マウスを離した時の処理
      }
      public void mouseMoved(MouseEvent e){   }
      public void mouseReleased(MouseEvent e){   }
      public void mouseClicked(MouseEvent e){   }
      public void mouseEntered(MouseEvent e){   }
      public void mouseExited(MouseEvent e){   }
   }
   public static void main(String args[]){
      JFrame frame  = new JFrame("Draw Editor");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      DrawGraphics e = new DrawGraphics();
      frame.add(e, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}
