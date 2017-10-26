// リスト12.3　オフスクリーンイメージを使って図形を繰り返し描画
import java.awt.*;
import java.awt.image.*;
import javax.swing.*;  

public class DrawOffscreen extends JPanel{
   BufferedImage bi; //オフスクリーンイメージ
   Graphics bg;  //Graphicsコンテキスト
   public DrawOffscreen(){  
      setBackground(Color.white);
      setPreferredSize(new Dimension(250, 80));
      bi = new BufferedImage(51, 51, BufferedImage.TYPE_INT_RGB);
      bg = bi.createGraphics(); //Graphicsコンテキストを得る
      bg.fillRect(0,0,51,51); //背景を白くするため描画色で四角を描く
      bg.setColor(Color.black); //描画色を黒にする
      bg.drawLine(0, 0, 50, 50); //線を描く
      bg.drawLine(50, 0, 0, 50); //線を描く
      bg.drawRect(0, 0, 50, 50); //四角を描く
   }

   protected void paintComponent(Graphics g){
      super.paintComponent(g);
      for(int i=0; i<4; i++){
      g.drawImage(bi, 10+i*60, 10, this);
      }
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Draw the same lines");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      DrawOffscreen h = new DrawOffscreen();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }   
}
