//練習問題11.2
import java.awt.*;             
import javax.swing.*;  

public class HelloFlowLayout extends JPanel{ 
   JLabel label; //ラベル用の変数
   JButton b1, b2;//ボタン用の変数

   public HelloFlowLayout(){
      label = new JLabel("こんにちは");  //JLabelオブジェクトの生成
      b1 = new JButton("ボタン1");  //JButtonオブジェクトの生成
      b2 = new JButton("ボタン2");  //JButtonオブジェクトの生成
      add(label);  //ラベルを置く
      add(b1);    //ボタンを置く
      add(b2);    //ボタンを置く
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("FlowLayout");//JFrameオブジェクトを生成
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                              //ウィンドウを閉じるとプログラムが終了
      HelloFlowLayout h = new HelloFlowLayout();  //HelloFlowLayoutオブジェクトを生成
      frame.add(h, BorderLayout.CENTER); 
      frame.pack();               //フレームを必要最小の大きさにする
      frame.setVisible(true);     //フレームを画面に見せる
   }
}

