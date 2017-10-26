//  パラメータで挨拶が変わるこんにちはアプレット版
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;  

public class HelloApplet2 extends JApplet implements ActionListener{ 
   JLabel label; //ラベル用の変数
   JButton b1, b2;//ボタン用の変数
   String word ;
   public void init(){  
      word = getParameter("greeting");
      if(word==null) {word = "こんにちは";}
      label = new JLabel("  ");  //JLabelオブジェクトの生成
      b1 = new JButton("ごあいさつ");  //JButtonオブジェクトの生成
      b2 = new JButton("消去");  //JButtonオブジェクトの生成
      b1.addActionListener(this); //イベントリスナーを設定
      b2.addActionListener(this); //イベントリスナーを設定
      add(label, BorderLayout.NORTH);  //ラベルを置く
      add(b1, BorderLayout.CENTER);    //ボタンを置く
      add(b2, BorderLayout.EAST);      //ボタンを置く
      validate();
   }

   public void actionPerformed(ActionEvent e){
      Object obj = e.getSource();
      if(obj == b1){          //b1が押されたら
	 label.setText(word);    //labelに文字列を設定 
      } else if(obj == b2){     //b2が押されたら
	 label.setText(" ");              //labelの文字列を消す
      }
   }
}

