//  リスト14.3 音声を再生するアプレット
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.AudioClip;

public class SoundExample extends JApplet implements ActionListener{
   AudioClip clip;     // オーディオクリップ用の変数を宣言 
   boolean looped;     // 再生中か否かのフラグ false:停止中 true:再生中
   JButton loopB, stopB;
   public void init(){
      Container c = getContentPane();
      c.setLayout(new FlowLayout());
      c.setBackground(Color.white);
      loopB = new JButton("再生");
      stopB = new JButton("停止");
      loopB.addActionListener(this);
      stopB.addActionListener(this);
      add(loopB);   add(stopB);
      stopB.setEnabled(false);         // 停止ボタンを無効にする
      clip = getAudioClip(getCodeBase(), "usagid.mid"); // オーディオクリップを作る
   }

   public void stop(){  // ブラウザが別のWebページに移った時 
      if(looped){  clip.stop(); } // 繰返再生中ならオーディオクリップの再生を中止する    
   }
   public void start(){   // アプレットを含むページが表示された時
      if(looped){  clip.loop(); } // 再生中ならオーディオクリップの再生を再開する
   }

   public void actionPerformed(ActionEvent e){
      Object obj = e.getSource();
      if(obj == loopB){    // 繰返再生ボタンが押されたら
         looped = true;         // 再生フラグをonに設定
         clip.loop();           // オーディオクリップを繰返し再生する
         loopB.setEnabled(false);  // 繰返ボタンを無効にする
         stopB.setEnabled(true);   // 停止ボタンを有効にする
         stopB.requestFocus();  //停止ボタンにキーボードフォーカスを移す
         showStatus("Play sound continuously"); 
      }
      else if (obj == stopB){  // 停止ボタンが押されたら
         looped = false;       // 再生フラグをoffに設定
         clip.stop();          // オーディオクリップの再生を中止する 
         loopB.setEnabled(true);       // 繰返ボタンを有効にする
         stopB.setEnabled(false);      // 停止ボタンを無効にする
         showStatus("Stop sound");
      }
   }    
}
