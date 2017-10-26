// リスト 11.3 JButtonの例  
import java.awt.*;             
import javax.swing.*;  

public class JButtonExample extends JPanel{
   JButton b1, b2;

   public JButtonExample(){  
      ImageIcon icon1 = new ImageIcon("dance.gif");
      ImageIcon icon2 = new ImageIcon("lay.gif");
      b1 = new JButton(icon1);
      b2 = new JButton(icon2);
      add(b1);
      add(b2);
   }

   public static void main(String[] args){
      JFrame frame = new JFrame("JButton");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      JButtonExample h = new JButtonExample();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);     
   }
}
