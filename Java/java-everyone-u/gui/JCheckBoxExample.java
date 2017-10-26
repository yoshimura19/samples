// リスト 11.4 JCheckBoxの例 
import java.awt.*;
import javax.swing.*;  

public class JCheckBoxExample extends JPanel{
   JCheckBox cbox1, cbox2;
   public JCheckBoxExample(){  
      setLayout(new GridLayout(2, 0));
      cbox1 = new JCheckBox("チェックボックス");
      Icon icon1 = new ImageIcon("dance.gif");
      Icon icon2 = new ImageIcon("lay.gif");
      cbox2 = new JCheckBox("うさぎ", icon1);
      cbox2.setSelectedIcon(icon2);  //選択時のアイコン設定
      add(cbox1);
      add(cbox2);
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("JCheckBox");//JFrameオブジェクトを生成
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      JCheckBoxExample h = new JCheckBoxExample();
      frame.add(h, BorderLayout.CENTER);//フレームにオブジェクトを置く
      frame.pack();               //フレームを必要最小の大きさにする
      frame.setVisible(true);     //フレームを画面に見せる
   }
}
