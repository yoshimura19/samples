import java.awt.*;
import java.awt.image.*;
import java.awt.event.*;
import javax.swing.event.*;
import javax.swing.*;

public class STree extends JPanel implements ChangeListener, ActionListener{
   double scale = 0.7;        // `育つ枝の長さの比率`
   int angle = 30;           // `枝の広がる角度（度単位）`
   int n = 15;               // `繰り返し回数`
   double len = 100.0;    // `最初の枝の長さ`
   BufferedImage bi;
   Graphics bg;
   JSlider slidera, sliders; 
   JTextField ntf;
   final int W = 650, H = 650;
   STree() {
      bi = new BufferedImage(W, H, BufferedImage.TYPE_INT_RGB);
      bg = bi.createGraphics();
      MyCanvas can = new MyCanvas();
      JPanel cpanel = new JPanel();
      slidera = new JSlider(JSlider.HORIZONTAL,0,180, 30);
      sliders = new JSlider(JSlider.HORIZONTAL,0,100, 70);
//      slidera.setPreferredSize(new Dimension(150,20));
//      sliders.setPreferredSize(new Dimension(150,20));
      slidera.addChangeListener(this);
      sliders.addChangeListener(this);
      ntf = new JTextField(3);
      ntf.setText("15");
      ntf.addActionListener(this);

      cpanel.add(new JLabel("回数:"));
      cpanel.add(ntf);
      cpanel.add(new JLabel("  枝の広がり:"));
      cpanel.add(slidera);
      cpanel.add(new JLabel("  枝の長さ:"));
      cpanel.add(sliders);
      setLayout(new BorderLayout());
      add(can, BorderLayout.CENTER);
      add(cpanel, BorderLayout.SOUTH);
      drawing();
   }
   public void actionPerformed(ActionEvent aa){
      n = Integer.parseInt(ntf.getText());
      drawing();
      repaint();
   }
   public void stateChanged(ChangeEvent aa){
      if(aa.getSource() == slidera){
	 angle = slidera.getValue();
      }else{
	 scale = sliders.getValue()/100.0;
      }
      drawing();
      repaint();
   }
   void drawTree(double x1, double y1, double len, double stand, int nn){
      double x2,y2;
      x2=x1 + len*Math.sin(Math.toRadians(stand));  //`枝先のx座標`
      y2=y1 - len*Math.cos(Math.toRadians(stand));  //`枝先のy座標`
      bg.drawLine((int)x1,(int)y1,(int)x2,(int)y2); //`線を描く`
      if(nn>1){   //`木の末端まで達していない時は，次の枝を描く`
	 drawTree(x2,y2,len*scale,stand-angle,nn-1); //`次の右の枝を描く`
	 drawTree(x2,y2,len*scale,stand+angle,nn-1); //`次の左の枝を描く`
      }
   }
   void drawing(){
      bg.setColor(Color.white);
      bg.fillRect(0,0,W,H); 
      bg.setColor(new Color(100, 153, 0));  // `描画色の設定`
      drawTree(W/2, H-50, len, 0, n);  // `再帰処理の開始`
   }
   class MyCanvas extends JPanel{
      MyCanvas(){
	 setPreferredSize(new Dimension(W, H)); 
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
      STree h = new STree();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
    }
}



/*      if(nn == 8 || nn == 7){
         double p = len * 3.5;
	 double zh =p*Math.sin(RAD*stand);
	 double zw =p*Math.cos(RAD*stand);
	 double zx = x1 - zw/2;
	 double zy = y1 - zh/2;
	 bg.setColor(Color.red);
	 bg.drawPolygon(new int[]{(int)zx, (int)(zx + zw), (int)(zx+zw+zh), (int)(zx+zh)},
			new int[]{(int)zy, (int)(zy + zh), (int)(zy+zh-zw), (int)(zy - zw)}, 4);
	 bg.setColor(Color.black);
      }
*/