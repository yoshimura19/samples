// 演習問題  オフスクリーンイメージを使って図形を繰り返し描画
import java.awt.*;
import java.awt.image.*;
import javax.swing.*;  

public class DrawOffscreen2 extends JPanel{
   BufferedImage bi; //オフスクリーンイメージ
   Graphics bg; //Graphicsコンテキストを得る
   public DrawOffscreen2(){  
      setBackground(Color.white);
      setPreferredSize(new Dimension(250, 80));
   }

   protected void paintComponent(Graphics g){
      if(bi==null){
         bi = (BufferedImage)createImage(51, 51);
         bg = bi.createGraphics(); //Graphicsコンテキストを得る
         bg.setColor(Color.white);
         bg.fillRect(0, 0, 51, 51); //背景を白くするため四角を描く
         bg.setColor(Color.black);
         bg.drawLine(0, 0, 50, 50); //線を描く
         bg.drawLine(50, 0, 0, 50); //線を描く
         bg.drawRect(0, 0, 50, 50); //四角を描く
      }
      super.paintComponent(g);
      for(int i=0; i<4; i++){
         g.drawImage(bi, 10+i*60, 10, this);
      }
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Draw the same lines");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      DrawOffscreen2 h = new DrawOffscreen2();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }   
}
