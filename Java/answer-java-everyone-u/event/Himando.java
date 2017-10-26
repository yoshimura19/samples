//練習問題  肥満度計算プログラム
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;  

public class Himando extends JPanel implements ActionListener{
   JTextField hField,wField;   //入力フィールド
   JLabel hyoujun, himando, hantei;    //ラベル
   Double w, h; //体重と身長
   public Himando(){
      setBackground(Color.white);
      hField = new JTextField(10);  //入力フィールドを生成
      wField = new JTextField(10);
      hyoujun = new JLabel();       //ラベルを生成
      himando= new JLabel();
      hantei= new JLabel();
      hField.addActionListener(this);  //入力フィールドにリスナーを設定
      wField.addActionListener(this);
      setLayout(new GridLayout(5,2));  //レイアウトを設定
      add(new JLabel("身長(cm)"));     add(hField);                     
      add(new JLabel("体重(Kg)"));     add(wField);
      add(new JLabel("標準体重(Kg)")); add(hyoujun);
      add(new JLabel("肥満度"));    add(himando);
      add(new JLabel("肥満度判定"));    add(hantei);
   }
   public void actionPerformed(ActionEvent e){  
      try{ //身長を設定
         h = Double.parseDouble(hField.getText()); //double型に変換
      } catch (NumberFormatException error){ h = 0.0; } //エラーがあれば0
      try{ //体重を設定
         w=Double.parseDouble(wField.getText());
      } catch (NumberFormatException error){ w = 0.0; }
      doCalc(); //計算をし、表示をするメソッド
   }
   void doCalc(){
      if(h <= 0){ hField.requestFocus(); } //入力エラーがあった所へカーソル移動
      else if(w <= 0){ wField.requestFocus();}
      else{
	 double std = h/100 * h/100 * 22; //標準体重を計算
	 double him = w /((h/100)*(h/100));  //肥満度を計算
	 hyoujun.setText(String.valueOf(std));//標準体重を表示
	 himando.setText(String.valueOf(him));  //肥満度を表示

	 if (him<=15) hantei.setText("痩せすぎ");
	 else if (him>15 && him<=20) hantei.setText("痩せぎみ");
	 else if (him>20 && him<=25) hantei.setText("普通");
	 else if (him>25 && him<=30) hantei.setText("太りぎみ");
	 else hantei.setText("太りすぎ");
      }
   }
   public static void main(String[] args) {
      JFrame frame = new JFrame("Himando");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Himando h = new Himando();        //肥満度パネルを作る
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
