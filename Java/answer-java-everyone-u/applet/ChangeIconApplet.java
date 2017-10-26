//練習問題 ボタンでアイコンが変わるアプレット
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;  
import java.net.*;  

public class ChangeIconApplet extends JApplet implements ActionListener{
   JButton b1, b2, b3;
   JLabel label;
   ImageIcon dance, lay, stand;
   public void init(){  
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
      try{
         dance = new ImageIcon(new URL(getCodeBase(), "dance.gif"));
         lay = new ImageIcon(new URL(getCodeBase(), "lay.gif"));
         stand = new ImageIcon(new URL(getCodeBase(), "up.gif"));
      }catch(MalformedURLException er){}
      JPanel p2 = new JPanel();
      //上部パネルのサイズを好ましい大きさに設定
      p2.setPreferredSize(new Dimension(250, 100));
      p2.setBackground(Color.WHITE);
      label = new JLabel();
      p2.add(label);

      //setLayoutは自動的にアプレットのコンテントペインに対して実行される
      //BoxLayoutの引数にはアプレットのコンテントペインが必要
      Container c = getContentPane();
      setLayout(new BoxLayout(c, BoxLayout.Y_AXIS));
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
}
