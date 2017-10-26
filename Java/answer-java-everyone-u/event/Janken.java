//  練習問題  じゃんけんプログラム
import java.awt.*;             
import java.awt.event.*;             
import javax.swing.*;  

public class Janken extends JPanel implements ActionListener{ 
   JLabel labelC, labelH, labelWin; //ラベル
   JButton bg, bt, bp;//ボタン
   ImageIcon gu, tyoki, pa, muji;    //アイコン
   int comp, human;                 //コンピュータの手,人間の手
   public Janken(){  
      setBackground(Color.white);
      bg = new JButton("グー");  //JButtonオブジェクトの生成
      bt = new JButton("チョキ"); 
      bp = new JButton("パー"); 
      bg.addActionListener(this); //リスナーの設定
      bt.addActionListener(this);
      bp.addActionListener(this);
      muji = new ImageIcon("gu.gif");
      gu = new ImageIcon("gu.gif");
      tyoki = new ImageIcon("tyoki.gif");
      pa = new ImageIcon("pa.gif");

      JPanel p1 = new JPanel(); //ボタンを置くパネル
      p1.setLayout(new GridLayout(3,0));
      p1.add(bg);
      p1.add(bt);
      p1.add(bp);
      //手と勝敗を表示するJLabelの生成
      labelC = new JLabel("コンピュータ", muji, SwingConstants.CENTER);
      labelH = new JLabel("あなた", muji, SwingConstants.CENTER);  
      labelC.setHorizontalTextPosition(SwingConstants.CENTER);
      labelC.setVerticalTextPosition(SwingConstants.TOP);
      labelH.setHorizontalTextPosition(SwingConstants.CENTER);
      labelH.setVerticalTextPosition(SwingConstants.TOP);
      labelWin = new JLabel("  ", SwingConstants.CENTER);

      JPanel p2 = new JPanel(); //ボタンのパネルとあなたの手を置くパネル
      p2.setBackground(Color.white);
      p2.add(labelH);
      p2.add(p1);
   
      setLayout(new BorderLayout());   //外側パネルの配置方式の設定
      add(labelC, BorderLayout.WEST);    //コンピュータの手
      add(new JLabel("VS"), BorderLayout.CENTER); 
      add(p2, BorderLayout.EAST);      //人の手とボタン
      add(labelWin, BorderLayout.SOUTH); //勝敗のラベルを置く
   }

   public void actionPerformed(ActionEvent e){
      Object obj = e.getSource();
      if(obj == bg){
         labelH.setIcon(gu);
         human = 0;
      }else if(obj == bt){
         labelH.setIcon(tyoki);
         human = 1;
      }else if(obj == bp){
         labelH.setIcon(pa);
         human = 2;
      }
      comp = (int)(Math.random()*3); //乱数を生成
      dispComp(comp); //コンピュータの手を表示 
      dispWin(comp, human); //勝敗を表示 
   }

   void dispWin(int c, int m){  //勝敗を判定、表示
      switch(c){
      case 0: if(m==0)labelWin.setText("あいこ");
              else if (m==1)labelWin.setText("あなたの負け");
              else if (m==2)labelWin.setText("あなたの勝ち");
	      break;
      case 1: if(m==0)labelWin.setText("あなたの勝ち");
              else if (m==1)labelWin.setText("あいこ");
              else if (m==2)labelWin.setText("あなたの負け");
              break;
      case 2: if(m==0)labelWin.setText("あなたの負け");
              else if (m==1)labelWin.setText("あなたの勝ち");
              else if (m==2)labelWin.setText("あいこ");
              break;
      default: labelWin.setText("わかりません");
              break;
      }
   }
 
   void dispComp(int c){
      switch(c){
      case 0: labelC.setIcon(gu);
	      break;
      case 1: labelC.setIcon(tyoki);
	      break;
      case 2: labelC.setIcon(pa);
	      break;
      }
 }
  public static void main(String[] args){
      JFrame frame = new JFrame("Janken");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Janken j = new Janken();  //Jankenのオブジェクトを生成
      frame.add(j, BorderLayout.CENTER);//フレームにJankenオブジェクトを置く
      frame.pack();               
      frame.setVisible(true);     
   }
}
