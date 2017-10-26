// 練習問題 Graphics2Dの回転を使ったプログラム
import java.awt.*;
import javax.swing.*;

public class RotateOval extends JPanel{
   int w = 200, h = 200; // パネルの幅と高さ
   int ow = 150; //楕円の長径
   int oh = 30; //楕円の短径
   int dr = 20; //回転角度
   int x = (w - ow)/2; // 描画位置x座標
   int y = (h - oh)/2; // 描画位置y座標

   public RotateOval() {
       setBackground(Color.white);
       setPreferredSize(new Dimension(w, h));
   }

   protected void paintComponent(Graphics g) {
      super.paintComponent(g);
      g.setColor(Color.red);
      Graphics2D g2 = (Graphics2D)g;
      for(int a=0; a<180; a=a+dr){
         g2.rotate(Math.toRadians(dr), x+ow/2, y+oh/2);
          g.drawOval(x, y, ow, oh);
      }
   }

   public static void main(String[] args) {
       JFrame frame = new JFrame("Rotate Oval");
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       RotateOval h = new RotateOval();
       frame.add(h, BorderLayout.CENTER);
       frame.pack();
       frame.setVisible(true);
   }
}
