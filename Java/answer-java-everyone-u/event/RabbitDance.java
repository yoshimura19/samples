//練習問題 アニメーションの開始と停止
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.imageio.*;  

public class RabbitDance extends JPanel implements ActionListener {
   JButton b1, b2;
   RabbitAnimation area;

   public RabbitDance(){  
      JPanel p1 = new JPanel(); //ボタンを置くパネル
      b1 = new JButton("スタート");
      b2 = new JButton("ストップ");
      b1.addActionListener(this);
      b2.addActionListener(this);
      p1.add(b1);
      p1.add(b2);
 
      area = new RabbitAnimation();
      setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
      add(area);//上部にRabbitAnimationパネルを配置
      add(p1);//下部にボタンを置いたパネルを配置
   }

   public void actionPerformed(ActionEvent e) { //アクションイベント処理
      Object obj = e.getSource();
      if(obj == b1){          //b1が押されたら
	 area.startDance();
      }
      else if(obj == b2){     //b2が押されたら
         area.stopDance();
      }
    }
    public static void main(String[] args) {
       JFrame frame  = new JFrame("Animation");
       frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       RabbitDance k = new RabbitDance();
       frame.add(k, BorderLayout.CENTER);
       frame.pack();
       frame.setVisible(true);
    }
}


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
       setPreferredSize(new Dimension(stage.getWidth(this), stage.getHeight(this)));
       //timer.start();                    //アニメーションの開始
    }

    void startDance(){
	if(!timer.isRunning()) timer.start();
    }
    void stopDance(){
	if(timer.isRunning()) timer.stop();
    }

    public void actionPerformed(ActionEvent e) { //アクションイベント処理
       number++;  
       number = number%cell;  //次に表示する画像の番号
       repaint(); //描画
    }

    protected void paintComponent(Graphics g) {
       super.paintComponent(g); //背景の描画
       g.drawImage(stage, 0, 0, this);
       int x = getWidth()/2-30; //ウィンドウのほぼ中央にうさぎを表示
       int y = getHeight()/2+20;
       g.drawImage(image[number], x, y, this);
    }
}






