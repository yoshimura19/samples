//  リスト 11.6 JPanelの例 
import java.awt.*;
import javax.swing.*;  

class JPanelExample extends JPanel{
  JPanelExample(){
     JPanel pa = new JPanel();
     pa.setLayout(new BoxLayout(pa, BoxLayout.Y_AXIS));
     pa.add(new JButton("ボックス上"));
     pa.add(new JButton("ボックス中"));
     pa.add(new JButton("ボックス下"));
     JPanel pb = new JPanel();
     pb.setLayout(new GridLayout(2,0));
     pb.add(new JButton("格子左上 "));
     pb.add(new JButton("格子右上 "));
     pb.add(new JButton("格子左下 "));
     pb.add(new JButton("格子右下 "));
     add(pa);
     add(pb);
  }
  public static void main(String[] args){
     JFrame f  = new JFrame("JPanel Example");
     JPanelExample example = new JPanelExample();
     f.getContentPane().add(example, BorderLayout.CENTER);
     f.pack();
     f.setVisible(true);
  }
}
