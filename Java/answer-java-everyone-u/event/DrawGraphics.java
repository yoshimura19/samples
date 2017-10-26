//練習問題 超簡易図形エディタ
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class DrawGraphics extends JPanel implements ActionListener{
   JButton b1, b2, b3;
   final int RECT = 1;  final int OVAL = 2; final int LINE=3;
   DrawByMouse area;
   int type = RECT;   //描く図形の種類, 初期値は四角
   public DrawGraphics(){
      JPanel p1 = new JPanel(); //ボタンを置くパネル
      b1 = new JButton("四角");
      b2 = new JButton("円");
      b3 = new JButton("直線");
      b1.addActionListener(this);
      b2.addActionListener(this);
      b3.addActionListener(this);
      p1.setBackground(Color.WHITE);
      p1.add(b1);
      p1.add(b2);
      p1.add(b3);
      area = new DrawByMouse();
      setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));  //縦に配置
      add(area);
      add(p1);
   }

   public void actionPerformed(ActionEvent e) {
      Object target = e.getSource();
      if (target == b1) { type = RECT; }   //描く図形の種類を四角に設定
      else if (target == b2) { type = OVAL; }  //描く図形の種類を円に設定
      else if (target == b3) { type = LINE; }  //描く図形の種類を線に設定
   }


   class DrawByMouse extends JPanel implements MouseListener, 
                                            MouseMotionListener {
      int x1, y1, x2, y2; //描画用の座標
      int fX, fY, sX, sY; //マウスカーソルの位置
      DrawByMouse(){
	 setBackground(Color.white);
	 setPreferredSize(new Dimension(250, 250));
	 addMouseListener(this);
	 addMouseMotionListener(this);
      }

      protected void paintComponent(Graphics g){    
	 super.paintComponent(g);
	 if(type == RECT){
	    g.drawRect(x1, y1, x2-x1, y2-y1);
	 } else if (type == OVAL){
	    g.drawOval(x1, y1, x2-x1, y2-y1);
	 } else if (type == LINE){
	    g.drawLine(x1,y1,x2,y2);
	 }
      }

      public void mousePressed(MouseEvent e){ //マウスを押した時の処理
	 fX = e.getX();
	 fY = e.getY();
      }
      public void mouseDragged(MouseEvent e){ //マウスを離した時の処理
	 sX = e.getX();
	 sY = e.getY();
	 if(type == LINE) {x1=fX; x2=sX; y1=fY; y2=sY;}
	 else {adjustPoint();}
	 repaint();     //ボタンを離した時、図形を描く
      }
      public void mouseMoved(MouseEvent e){   }
      public void mouseReleased(MouseEvent e){   }
      public void mouseClicked(MouseEvent e){   }
      public void mouseEntered(MouseEvent e){   }
      public void mouseExited(MouseEvent e){   }

      void adjustPoint(){ //ドラッグ先の座標が始めの点より小さい場合の処理
	 if(sX>=fX && sY>=fY) { //右下へドラッグ 変更なし
	    x1=fX; x2=sX;
	    y1=fY; y2=sY;
         }else if(sX<fX && sY<fY){ //左上へドラッグ ｘｙ座標交換
            x1=sX; x2=fX;
	    y1=sY; y2=fY;
	 }else if(sX>=fX && sY<fY){ //右上へドラッグ ｙ座標交換
	    x1=fX; x2=sX;
	    y1=sY; y2=fY;
	 }else if(sX<fX && sY>=fY){ //左下へドラッグ ｘ座標交換
            x1=sX; x2=fX;
	    y1=fY; y2=sY;
	 }
      }
   }
   public static void main(String[] args){
      JFrame.setDefaultLookAndFeelDecorated(true);
      JFrame frame  = new JFrame("Draw Editor");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      DrawGraphics e = new DrawGraphics();
      frame.add(e, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}

