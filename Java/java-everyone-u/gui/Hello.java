//  リスト11.1 こんにちはプログラム(Hello.java)
import java.awt.*;             
import javax.swing.*;  

public class Hello extends JPanel{ 
   JLabel label; //ラベル用の変数
   JButton b1, b2;//ボタン用の変数

   public Hello(){  
      label = new JLabel("こんにちは");  //JLabelオブジェクトの生成
      b1 = new JButton("ボタン１");  //JButtonオブジェクトの生成
      b2 = new JButton("ボタン２");  //JButtonオブジェクトの生成
      setLayout(new BorderLayout());   //パネルの配置方式を設定
      add(label, BorderLayout.NORTH);  //パネルにラベルを置く
      add(b1, BorderLayout.CENTER);    //パネルにボタンを置く
      add(b2, BorderLayout.EAST);      //パネルにボタンを置く
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Hello");//JFrameオブジェクトを生成
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                              //ウィンドウを閉じるとプログラムが終了
      //JFrame.setDefaultLookAndFeelDecorated(true); //Java独自Look&Feel
      Hello h = new Hello();  //Helloのオブジェクトを生成
      frame.add(h, BorderLayout.CENTER); 
      frame.pack();               //フレームを必要最小の大きさにする
      frame.setVisible(true);     //フレームを画面に見せる
   }
}


