//練習問題 100個の円
import java.awt.*;
import javax.swing.*;

public class CustomGraphics2 extends JPanel {
   int x, y;
   int r=10; //円の直径
   public CustomGraphics2(){
      setBackground(Color.white);
      setPreferredSize(new Dimension(250, 250));//望むサイズを設定
   }

   protected void paintComponent(Graphics g){    
      super.paintComponent(g);

      for(int i=1; i<=10; i++){
         x = 20*i;
         for(int j=1; j<=10; j++){
            y = 20*j;
            g.drawOval(x, y, r, r);
         }
      }
   }
	
   public static void main(String[] args){
      JFrame frame  = new JFrame("Circle on lines");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      CustomGraphics2 h = new CustomGraphics2(); 
      frame.add(h, BorderLayout.CENTER); 
      frame.pack();               //フレームを必要最小の大きさにする
      frame.setVisible(true);     //フレームを画面に見せる
   }
}

