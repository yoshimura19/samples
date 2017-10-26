//リスト13.3  標準体重計算プログラム
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;  

public class StdWeight extends JPanel implements ActionListener{
   JTextField hField;   //入力フィールド
   JLabel hyoujun;    //ラベル
   Double h; //身長
   public StdWeight(){
      setBackground(Color.white);
      hField = new JTextField(10);  //入力フィールドを生成
      hyoujun = new JLabel();       //ラベルを生成
      hField.addActionListener(this);  //入力フィールドにリスナーを設定
      setLayout(new GridLayout(2,2));  //レイアウトを設定
      add(new JLabel("身長(cm)"));     add(hField);                     
      add(new JLabel("標準体重(Kg)")); add(hyoujun);
   }
   public void actionPerformed(ActionEvent e){  
      try{ //身長を設定
         h = Double.parseDouble(hField.getText()); //double型に変換
      } catch (NumberFormatException error){ h = 0.0; } //エラーがあれば0
      doCalc(); //計算をし、表示をするメソッド
   }
   void doCalc(){
      if(h > 0){
	 double std = h/100 * h/100 * 22;
	 hyoujun.setText(String.valueOf(std));//標準体重を計算,表示
      }
   }
   public static void main(String[] args) {
      JFrame frame = new JFrame("Standart Weight");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      StdWeight h = new StdWeight();        //肥満度パネルを作る
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
