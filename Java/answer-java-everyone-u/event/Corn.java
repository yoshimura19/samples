// 練習問題 マウスで中心が動く同心円
import java.awt.*; 
import java.awt.event.*; 
import javax.swing.*;

public class Corn extends JPanel implements MouseMotionListener{
   int centerX, centerY; //パネルの中心
   int x, y, r;  //円の位置と直径
   int mX, mY;   //マウスの位置
   int distance=10, kosu=20;  //円の直径の変化量と円の個数
   float dx, dy;  //マウスの位置方向へのずれ
   Dimension size = new Dimension(250, 250);  

   public Corn(){
      setBackground(Color.white);     
      setPreferredSize(size);
      mX = size.width/2; //最初のマウスの位置
      mY = size.height/2;
      addMouseMotionListener(this);
   }
   protected void paintComponent(Graphics g){    
       super.paintComponent(g);
       centerX=getWidth()/2;  //パネルの中央
       centerY=getHeight()/2;
       r=0;
       dx = (centerX-mX)/(float)(kosu); //円のずれ
       dy = (centerY-mY)/(float)(kosu);
       for(int i=1; i<=kosu; i++){
           r=r+distance;
	   x = (int)(mX + dx*i - r/2.0F);
	   y = (int)(mY + dy*i - r/2.0F);
	   g.drawOval(x, y, r, r);
       }
   }
   public void mouseDragged(MouseEvent e){
      mX = e.getX();
      mY = e.getY();
      repaint();
   }
   public void mouseMoved(MouseEvent e){  }
   public static void main(String[] args){
      JFrame frame  = new JFrame("Circle Example");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Corn h = new Corn();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}
