/* 教科書の例題に対し， Spinner を利用し，abort ボタンを追加している。

Spinner の利用方法：
   new JSpinner(); で作られる spinner は，値に制限がない。
   初期値 v, 最小値 min, 最大値 max, ステップ s の spinner は，
   spinner = new JSpinner(new SpinnerNumberModel(v,min,max,s));
   で作成する。

   spinner は，ChangeEvent イベントを発生する。ChangeEvent については
   P185 の説明を参照。


abort ボタンを作成するには：

    ボタンが押されたなどの GUI の処理は一つのメソッドで行っているので，
    他のボタンにより起動されたメソッドが実行している間は，次のメソッド
    を起動できない。よって，現在行われている処理を止めるための abort ボ
    タンは，そのままでは実現できない。ここでは，描画処理は，GUI から起
    動されたメソッドではなく，別メソッドに実現させている。abort ボタン
    が押されると，それが押されたことを示す変数 stop を true にし，描画
    処理のメソッドはこの値を見て，途中で処理を終了する。処理を終了する
    のに，例外を発生（throw）させている。

*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;   //ChangeListener を利用する時にこの import が必要
import java.awt.geom.*;
import java.awt.image.*;
import javax.swing.*;

public class LevyPanel extends JPanel implements ActionListener, ChangeListener{
   int n = 0;               // `繰り返し回数`
   int M = 250;           // 1辺の長さ(オフスクリーン上)
   // M を変更してコンパイルしなおせば，より細かい画像を作れる。
   int W = M * 3, H = M * 3; // オフスクリーンの画像のサイズ
   int WW = 800, WH = 800;
   BufferedImage bi;
   Graphics2D bg;
   Canvas v;
   JSpinner spinner;
   JButton abort;
   Thread th;
   boolean stop = false;

   JRadioButton single, multi;
   ButtonGroup gr;

   double zoom = 1.0;
   JButton zoomin, zoomout;
   JScrollPane sp;

   LevyPanel(){
      v = new Canvas();
      bi = new BufferedImage(W, H, BufferedImage.TYPE_INT_RGB);
      bg = (Graphics2D) bi.createGraphics();
      bg.fillRect(0,0,W,H); 
      bg.setColor(Color.black); 
      v.setPreferredSize(new Dimension(W, H)); 

      sp = new JScrollPane(v);
      sp.setPreferredSize(new Dimension(WW, WH));
      setLayout(new BorderLayout());
      add(sp,BorderLayout.CENTER);

      JPanel cp = new JPanel(new GridLayout(0,1));
      single = new JRadioButton("single", true);
      multi =  new JRadioButton("multi");
      gr = new ButtonGroup();
      gr.add(single);  gr.add(multi);
      cp.add(single); cp.add(multi);
      single.addActionListener(this);
      multi.addActionListener(this);
      cp.add(new JLabel(""));
      spinner = new JSpinner(new SpinnerNumberModel(0,0,50,1)); spinner.addChangeListener(this); cp.add(spinner);
      cp.add(new JLabel(""));
      abort = new JButton("abort"); abort.addActionListener(this);
      cp.add(abort);

      zoomin = new JButton("Zoom in"); zoomin.addActionListener(this); cp.add(zoomin);
      zoomout = new JButton("Zoom out"); zoomout.addActionListener(this); cp.add(zoomout);

      JPanel cpp = new JPanel(new FlowLayout());
      cpp.add(cp);
      add(cpp, BorderLayout.EAST);
      paintit();
   }
   public void zooming(double zoom){
      double origzoom = this.zoom;
      this.zoom = zoom;
      Point p = sp.getViewport().getViewPosition(); //左上の座標
      v.setPreferredSize(new Dimension((int)(W * zoom), (int)(H * zoom))); 
      v.revalidate();
      sp.getViewport().setViewPosition(new Point((int)(p.x*zoom/origzoom) , (int)(p.y*zoom/origzoom)));   //元と同じ点が左上の座標に来るように調整。
   }



   public void stateChanged(ChangeEvent e){  
             //JSpinner の状態が変わった時のイベント
      paintit();
   }

   public void actionPerformed(ActionEvent e){ 
      Object orig = e.getSource();
      if(orig == abort) {
	 if (th != null) stop = true; 
	 return;
              // スレッドを終了させるのに，横から強制終了するのではなく，
              //stop という変数の値を設定するだけとする。スレッドが自分で
              //stop の値を見て，必要なら終了する。P103, 傍注６
      }
      if(orig == zoomin){ zooming(zoom * 1.2); repaint(); return;}
      if(orig == zoomout){ zooming(zoom / 1.2); repaint(); return;}
   }
   public void paintit(){
      // 別スレッドが動いていたら，何もしない。
      if(th != null) return;

      n = (Integer)(spinner.getValue());
      bg.setColor(Color.white); 
      bg.fillRect(0,0,W,H); 
      th = new Thread(){ // 匿名クラスとして，Threadのサブクラスを定義
	                 // しながら，そのオブジェクトを生成  (P75)
	    public void run() {
	       try{
		  if(multi.isSelected()){
		     for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
			   bg.setColor(Color.getHSBColor((float)(i*3+j)/9,0.6f,0.6f));
			   levy(i*M, j*M, i*M, (j+1)*M, n);
			   bg.setColor(Color.getHSBColor((float)((i*3+j+2)%9)/9,0.8f,0.8f));
			   levy(i*M, (j+1)*M, (i+1)*M, (j+1)*M, n);
			   bg.setColor(Color.getHSBColor((float)((i*3+j+4)%9)/9,0.7f,0.7f));
			   levy((i+1)*M, (j+1)*M, (i+1)*M, j*M, n);
			   bg.setColor(Color.getHSBColor((float)((i*3+j+6)%9)/9,1.0f,1.0f));
			   levy((i+1)*M, j*M, i*M, j*M, n);
			}
		     }
		  }
		  bg.setColor(Color.black);
		  levy(M,2*M,2*M,2*M,n);
	       }catch(Exception e) {   // 下の throw で，ここまでぬけてくる。
		  System.out.println("CATCH STOP");
		  stop = false;}
	       th = null;
	       stop = false;
	    }

	    public void levy(float x1, float y1, float x2, float y2, int n) throws Exception{
	       if(stop){ // stop が true なら，自分でスレッドを終了する。
		  System.out.println("STOP");
		  throw(new Exception());  // 例外を起こして，いきなりぬける。(P97)
	       }
	       float x3 = (x2 + x1)/2 + (y2-y1)/2;
	       float y3 = (y2+y1)/2 - (x2 - x1)/2;
      
	       if(n == 0){
		  if (x1+x2+x3 < 0){ x1 += W; x2 += W; x3 += W;}
		  if (x1+x2+x3 > 3*W){ x1 -= W; x2 -= W; x3 -= W;}
		  if (y1+y2+y3 < 0){ y1 += H; y2 += H; y3 += H;}
		  if (y1+y2+y3 > 3*H){ y1 -= H; y2 -= H; y3 -= H;}
		  int[] xx = new int[]{(int)x1,(int)x2,(int)x3};
		  int[] yy = new int[]{(int)y1,(int)y2,(int)y3};
		  bg.fillPolygon(xx, yy, 3);
		  bg.drawPolygon(xx, yy, 3);
	       }else{
		  levy(x1, y1, x3,y3, n-1);
		  levy(x3, y3, x2,y2, n-1);
	       }
	       repaint();
	       // 描画と別スレッドなので，ここに入れると途中経過も描画
	       // される。
	    }

	 };// ここまでが匿名クラスの定義とオブジェクト生成 (run と levy はそのメソッド)
      th.start();
   }

   class Canvas extends JPanel{
      Canvas(){
	 setBackground(Color.white);  
      }
      protected void paintComponent(Graphics g){
	 super.paintComponent(g); 
	 g.drawImage(bi, 0, 0, (int)(W * zoom), (int)(H * zoom), this);
      }
   }
   public static void main(String args[]){
      JFrame.setDefaultLookAndFeelDecorated(true);
      JFrame frame = new JFrame();
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      LevyPanel h = new LevyPanel();
      frame.add(h, BorderLayout.CENTER);
      frame.pack();               
      frame.setVisible(true);
    }
}


