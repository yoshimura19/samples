// 練習問題 11.6
// 配置練習
import java.awt.*;
import javax.swing.*;  

public class HaitiRensyu extends JPanel{
   JButton b1, b2, b3;
   JLabelExample p2;

   public HaitiRensyu(){  
      JPanel p1 = new JPanel(); //ボタンを置くパネル
      b1 = new JButton("ボタン１");
      b2 = new JButton("ボタン２");
      b3 = new JButton("ボタン３");
      p1.setBackground(Color.WHITE);
      p1.add(b1);
      p1.add(b2);
      p1.add(b3);

      p2 = new JLabelExample();
      //上部パネルのサイズを好ましい大きさに設定
      p2.setPreferredSize(new Dimension(250, 250));

      setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
      add(p2);//上部にJLabelExampleパネルを配置
      add(p1);//下部にボタンを置いたパネルを配置
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("JPanel");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      HaitiRensyu h = new HaitiRensyu();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
