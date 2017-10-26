// リスト11.5  JComboBoxの例
import java.awt.*;             
import javax.swing.*;  

public class JComboBoxExample extends JPanel{
   JComboBox select;
   public JComboBoxExample() {
      setBackground(Color.white);
      String[] list = {"立つ", "踊る", "倒れる", "立ち上がる"};
      select = new JComboBox(list); //項目を指定してJComboBox生成
      add(select);                  //JComboBoxをパネルに置く
   }
   public static void main(String[] args){
      JFrame frame = new JFrame("JComboBox");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      JComboBoxExample h = new JComboBoxExample();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);     
   }
}
