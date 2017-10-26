// 練習問題  ボタンでアイコンが変わる
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;  

public class ChangeIcon extends JPanel implements ActionListener{
   JButton b1, b2, b3;
   JLabel label;
   ImageIcon dance, lay, stand;
   public ChangeIcon(){  
      JPanel p1 = new JPanel(); //ボタンを置くパネル
      b1 = new JButton("踊る");
      b2 = new JButton("倒れる");
      b3 = new JButton("立つ");
      p1.setBackground(Color.WHITE);
      p1.add(b1);
      p1.add(b2);
      p1.add(b3);
      b1.addActionListener(this); //イベントリスナーを設定
      b2.addActionListener(this); //イベントリスナーを設定
      b3.addActionListener(this); //イベントリスナーを設定
      dance = new ImageIcon("dance.gif");
      lay = new ImageIcon("lay.gif");
      stand = new ImageIcon("up.gif");

      JPanel p2 = new JPanel();
      //上部パネルのサイズを好ましい大きさに設定
      p2.setPreferredSize(new Dimension(250, 100));
      p2.setBackground(Color.WHITE);
      label = new JLabel();
      p2.add(label);

      setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
      add(p2);//上部にパネルを配置
      add(p1);//下部にボタンを置いたパネルを配置
   }

   public void actionPerformed(ActionEvent e){
      Object obj = e.getSource();
      if(obj == b1){          //b1が押されたら
         label.setIcon(dance); 
      }
      else if(obj == b2){     //b2が押されたら
	 label.setIcon(lay);
      }
      else if(obj == b3){     //b3が押されたら
         label.setIcon(stand);
      }
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Change Icon");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      ChangeIcon h = new ChangeIcon();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
