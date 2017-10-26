//リスト11.2 JLabelの例
import java.awt.*;             
import javax.swing.*;  

public class JLabelExample extends JPanel{
   JLabel a1, a2;
   public JLabelExample(){  
      setBackground(Color.white); //パネルの背景を白にする
      ImageIcon icon = new ImageIcon("dance.gif");
      JLabel a1 = new JLabel("うさぎのダンス");
      JLabel a2 = new JLabel(icon);
      add(a1);
      add(a2);
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("JLabel");//JFrameオブジェクトを生成
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      JLabelExample h = new JLabelExample();
      frame.add(h, BorderLayout.CENTER);//フレームにオブジェクトを置く
      frame.pack();               //フレームを必要最小の大きさにする
      frame.setVisible(true);     //フレームを画面に見せる
   }
}
