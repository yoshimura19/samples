//練習問題11.1 ボタンにイメージを貼った例

import java.awt.*;             
import javax.swing.*;  

public class HelloIcon extends JPanel{
   JLabel label; //ラベル用の変数
   JButton b1, b2;//ボタン用の変数

   public HelloIcon(){
      ImageIcon icon1 = new ImageIcon("hello.gif");
      ImageIcon icon2 = new ImageIcon("doron.gif");

      label = new JLabel("こんにちは");  //JLabelオブジェクトの生成
      b1 = new JButton("あいさつ", icon1);  //JButtonオブジェクトの生成
      b2 = new JButton("消える", icon2);  //JButtonオブジェクトの生成

      setLayout(new BorderLayout());   //配置方式の設定
      add(label, BorderLayout.NORTH);  //ラベルを置く
      add(b1, BorderLayout.CENTER);    //ボタンを置く
      add(b2, BorderLayout.EAST);      //ボタンを置く
   }
 

   public static void main(String[] args){
      JFrame frame = new JFrame("Hello");//JFrameオブジェクトを生成
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      HelloIcon h = new HelloIcon();  //HelloIconのオブジェクトを生成
      frame.add(h, BorderLayout.CENTER);//フレームにHelloオブジェクトを置く
      frame.pack();               //フレームを必要最小の大きさにする
      frame.setVisible(true);     //フレームを画面に見せる
   }
}
