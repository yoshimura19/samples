import java.awt.*;
import java.awt.image.*;
import java.awt.event.*;
import javax.swing.*;

public class RectanglesPanel extends JPanel implements ActionListener{
   final int WW = 400, WH = 400;
   int X = 50, Y = 100, W = 300, H = 200, N = 6;

   JButton next;
   JRadioButton rand1, rand2;
   ButtonGroup group = new ButtonGroup();
   BufferedImage bi;
   Graphics2D bg;
   JTextField ntf;

   RectanglesPanel(){
      bi = new BufferedImage(WW, WH, BufferedImage.TYPE_INT_RGB);
      bg = (Graphics2D) bi.createGraphics();

      JPanel cpanel = new JPanel();
      rand1 = new JRadioButton("一様乱数", true);
      rand2 = new JRadioButton("テント分布乱数");
      next = new JButton("次");

      ntf = new JTextField(3);
      ntf.setText("10");

      cpanel.add(new JLabel("回数:"));
      cpanel.add(ntf);



      group.add(rand1); group.add(rand2);
      cpanel.add(next);
      cpanel.add(rand1);
      cpanel.add(rand2);
      MyCanvas m = new MyCanvas();
      setLayout(new BorderLayout());
      add(m, BorderLayout.CENTER);
      add(cpanel, BorderLayout.SOUTH);
      next.addActionListener(this);
      makeFigure();
   }

   void makeFigure(){
      bg.setColor(Color.white); 
      bg.fillRect(0,0,WW,WH); 
      bg.setColor(Color.black); 

      bg.drawRect(X, Y, W, H);
      int n = Integer.parseInt(ntf.getText());

      rects(bg, X, Y, W, H, n);
   }

   public void actionPerformed(ActionEvent e){
      makeFigure();
      repaint();
   }

   double arand(){
      return (Math.random() + Math.random())/2;
   }

   double nrand(){
      double x = 0;
      for(int i = 0; i < 12; i++){
	 x += Math.random();
      }
      return (x-6)/6+0.5;
   }

   void rects(Graphics g, int x, int y, int w, int h, int depth){
      if(depth <= 0) return;
      if (w > h){
	 int m;
	 if(rand2.isSelected()) m = (int)(arand() * w);
	 else m = (int)(Math.random() * w);
	 g.drawLine(x + m, y, x + m, y+h);
	 rects(g, x , y, m, h, depth-1);
	 rects(g, x + m, y, w - m, h, depth-1);
      }else{
	 int m;
	 if(rand2.isSelected()) m = (int)(arand() * w);
	 else m = (int)(Math.random() * w);
	 g.drawLine(x, y + m, x+w, y + m);
	 rects(g, x , y, w, m, depth-1);
	 rects(g, x, y+m, w, h-m, depth-1);
      }
   }

   class MyCanvas extends JPanel{
      MyCanvas(){
	 setBackground(Color.white);  
	 setPreferredSize(new Dimension(WW, WH)); 
      }
      protected void paintComponent(Graphics g){
	 super.paintComponent(g); 
	 g.drawImage(bi, 0, 0, this);
      }
   }
   public static void main(String args[]){
      JFrame.setDefaultLookAndFeelDecorated(true);
      JFrame frame = new JFrame();
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      RectanglesPanel h = new RectanglesPanel();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
   }
}
