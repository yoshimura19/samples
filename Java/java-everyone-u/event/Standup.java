//リスト13.2 チェックボックスの選択によりアイコンが変化
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;  

public class Standup extends JPanel implements ItemListener{
   JLabel label; //ラベル
   JCheckBox cb; //チェックボックス
   ImageIcon lay,up; //アイコン
   public Standup(){
      setBackground(Color.white); //パネルの背景を白に
      lay = new ImageIcon("lay.gif");
      up = new ImageIcon("up.gif");
      label = new JLabel(lay);  
      cb = new JCheckBox("立つ");  
      cb.setBackground(Color.white);//チェックボックスの背景を白に
      cb.addItemListener(this); //リスナーの設定
      add(label);  //ラベルを置く
      add(cb);     //チェックボックスを置く
   }
 
   public void itemStateChanged(ItemEvent e){
      if( e.getStateChange()==ItemEvent.SELECTED){ //選択された状態
         label.setIcon(up);  
      }else if(e.getStateChange()==ItemEvent.DESELECTED){ //非選択の状態
         label.setIcon(lay);  
      }
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("Standup");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Standup h = new Standup();
      frame.add(h, BorderLayout.CENTER);
      frame.setSize(new Dimension(150, 110));
      frame.setVisible(true);
   }
}
