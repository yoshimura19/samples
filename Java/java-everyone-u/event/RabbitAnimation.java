// リスト13.10 うさぎのダンスアニメーション
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.imageio.*;  

class RabbitAnimation extends JPanel implements ActionListener {
   int number = 0;       //表示する画像の番号
   int cell = 20;         //画像の数
   int interval =300;     //画像の表示間隔(単位ミリ秒)
   Timer timer;           //タイマー用変数
   Image[] image;         //画像を格納する配列
   Image stage;           //背景画像用変数

   RabbitAnimation() {
      try{ stage = ImageIO.read(new File("rabbit/stage.gif")); //画像のロード
      }catch(IOException e){System.out.println("ファイルをロードできません");}

      image = new Image[cell];
      for (int i = 1; i <= cell; i++) {   //画像のロード
         try{ 
            image[i-1] = ImageIO.read(new File("rabbit/rabbit" + i + ".gif"));
         }catch(IOException e){System.out.println("ファイルをロードできません");}
      }
      timer = new Timer(interval, this); //タイマーの生成
      setBackground(Color.white);       //パネルの背景色
      setPreferredSize(new Dimension(stage.getWidth(this), stage.getHeight(this)));
      timer.start();                    //アニメーションの開始
   }

   public void actionPerformed(ActionEvent e) { //アクションイベント処理
      repaint(); //描画
      number++;  
      number = number%cell;  //次に表示する画像の番号
   }

   protected void paintComponent(Graphics g) {
      super.paintComponent(g); //背景の描画
      g.drawImage(stage, 0, 0, this);
      int x = getWidth()/2-30; //ウィンドウのほぼ中央にうさぎを表示
      int y = getHeight()/2+20;
      g.drawImage(image[number], x, y, this);
   }

   public static void main(String[] args) {
      JFrame frame  = new JFrame("Animation");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      RabbitAnimation panel = new RabbitAnimation();
      frame.add(panel, BorderLayout.CENTER);
      frame.pack();
      frame.setVisible(true);
   }
}






