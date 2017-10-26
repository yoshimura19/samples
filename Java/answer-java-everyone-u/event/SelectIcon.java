// 練習問題 コンボボックス
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class SelectIcon extends JPanel implements ItemListener{
   JComboBox select;
   JLabel photo;
   ImageIcon[] gazo;

   public SelectIcon() {
      String[] list = {"スクッと立つ", "ガンガン踊る", "バタッと倒れる", "ムクッと立ち上がる"};
      select = new JComboBox(list); //項目を指定してJComboBox生成
      select.addItemListener(this); //リスナーを設定する
      select.setBackground(Color.white);
      gazo = new ImageIcon[4];
      gazo[0] = new ImageIcon("syoumen.gif");
      gazo[1] = new ImageIcon("dance.gif");
      gazo[2] = new ImageIcon("lay.gif");
      gazo[3] = new ImageIcon("up.gif");

      photo = new JLabel(gazo[0]);
      photo.setBorder(BorderFactory.createEmptyBorder(10,0,10,0));
      setBackground(Color.white);
      setLayout(new BorderLayout());
      add(photo, BorderLayout.CENTER);
      add(select, BorderLayout.SOUTH);    //JComboBoxをJPanelに置く

   }

   public void itemStateChanged(ItemEvent e) {
      //選択された項目に応じて画像を表示
      photo.setIcon(gazo[select.getSelectedIndex()]);  
   }

   public static void main(String[] args){
      JFrame frame  = new JFrame("Select Icon");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      SelectIcon s = new SelectIcon();
      frame.getContentPane().add(s, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}
