//練習問題 100個の円のアニメーション
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ExpandCircle extends JPanel implements ActionListener{
   int x, y;
   int r=10; //円の直径
   public ExpandCircle(){
      setBackground(Color.white);
      setPreferredSize(new Dimension(250, 250));//望むサイズを設定
      Timer t = new Timer(100,this);
      t.start();
   }

    public void actionPerformed(ActionEvent e){
       r++;
       repaint();
    }

   protected void paintComponent(Graphics g){    
      super.paintComponent(g);

      for(int i=1; i<=10; i++){
         x = 20*i ;
         for(int j=1; j<=10; j++){
            y = 20*j;
            g.drawOval(x, y, r, r);
         }
      }
   }
	
   public static void main(String[] args){
      JFrame frame  = new JFrame("Expand Circles");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      ExpandCircle h = new ExpandCircle(); 
      frame.add(h, BorderLayout.CENTER); 
      frame.pack();               //フレームを必要最小の大きさにする
      frame.setVisible(true);     //フレームを画面に見せる
   }
}

