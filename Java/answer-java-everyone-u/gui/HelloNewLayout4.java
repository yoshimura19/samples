//練習問題11.5 
//ボタンとラベルをBoxLayoutで縦一列に配置

import java.awt.*;             
import javax.swing.*;  

public class HelloNewLayout4 extends JPanel{ 
   JLabel label; //ラベル用の変数
   JButton b1, b2;//ボタン用の変数

   public HelloNewLayout4(){  
      setLayout(new BoxLayout(this, BoxLayout.Y_AXIS)); //配置方式の設定
      label = new JLabel("こんにちは");  
      b1 = new JButton("ボタン1");  
      b2 = new JButton("ボタン2");  
      add(label);  
      add(b1); 
      add(b2); 
   }

   public static void main(String[] args){
      JFrame frame = new JFrame();//JFrameオブジェクトを生成
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      HelloNewLayout4 h = new HelloNewLayout4();  //オブジェクトを生成
      frame.add(h, BorderLayout.CENTER);//フレームにオブジェクトを置く
      frame.pack();               //フレームを必要最小の大きさにする
      frame.setVisible(true);     //フレームを画面に見せる
   }
}
