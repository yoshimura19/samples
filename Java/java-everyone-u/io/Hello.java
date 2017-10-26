//  リスト13.1 こんにちはプログラム(Hello.java)
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;  

public class Hello extends JPanel implements ActionListener{ 
   JLabel label; //ラベル用の変数
   JButton b1, b2;//ボタン用の変数

   public Hello(){  
      label = new JLabel(" ");  //最初は何も表示しない
      b1 = new JButton("ごあいさつ");  //ごあいさつボタン
      b2 = new JButton("消去");  //消去ボタン

      b1.addActionListener(this); //イベントリスナーを設定
      b2.addActionListener(this); //イベントリスナーを設定

      setLayout(new BorderLayout());   //配置
      add(label, BorderLayout.NORTH);  
      add(b1, BorderLayout.CENTER);    
      add(b2, BorderLayout.EAST);      
   }

  public void actionPerformed(ActionEvent e){
     Object obj = e.getSource();
     if(obj == b1){          //b1が押されたら
        label.setText("こんにちは");    //labelに文字列を設定 
     }
     else if(obj == b2){     //b2が押されたら
        label.setText(" ");              //labelの文字列を消す
     }
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Hello");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Hello h = new Hello(); 
      frame.add(h, BorderLayout.CENTER); 
      frame.pack();          
      frame.setVisible(true);
   }
}

