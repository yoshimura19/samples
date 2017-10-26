//  リスト 12.2  イメージの表示　ImageIOを使う
import java.awt.*;
import javax.swing.*;
import javax.imageio.*;
import java.io.*;

public class ImageExample extends JPanel{
   Image image;
   public ImageExample(){
      setBackground(Color.white);
      try{
         image = ImageIO.read(new File("frog.gif"));
      }catch(IOException e){}
   }

   public void paintComponent(Graphics g){
      super.paintComponent(g);
      g.drawImage(image, 0, 0, this);  //元の大きさで描画
      g.drawImage(image, 400, 50, 100, 100, this);//スケーリングして描画
      g.drawImage(image, 400, 200, 500, 300, 
                         140, 60, 190, 110, this);//スケーリングして描画
   }
	
   public static void main(String[] args){
      JFrame frame  = new JFrame("Image Example");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      ImageExample h = new ImageExample();
      frame.add(h, BorderLayout.CENTER);
      frame.setSize(550,400);
      frame.setVisible(true);
   }
}
