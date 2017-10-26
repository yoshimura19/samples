//リスト15.5 テキストエディタの枠組
// 特定のファイルの表示のみ
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

public class TextEditor extends JPanel{
    JTextArea text;
    String filename = "Hello.java";  //編集するファイル
    JButton open, save;

    TextEditor() { 
        JPanel p = new JPanel(); //ボタンを置くパネル
        open = new JButton("開く");
        save = new JButton("保存");
        p.setBackground(Color.WHITE);
        p.add(open);
        p.add(save);
        text = new JTextArea(); //JTextAreaオブジェクト
        JScrollPane pane = new JScrollPane(text);  //textをJScrollPaneに入れる
        pane.setPreferredSize(new Dimension(300, 300));

        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        add(pane);//上部にJScrollPane
        add(p);//下部にボタンを置いたパネルを配置

        try{ dataRead();   
        }catch(IOException error){System.out.println("ファイルエラー");}
    }

    void dataRead() throws IOException{   //一行ずつ読んで表示
       BufferedReader din = new BufferedReader(new FileReader(filename));
       String s;
       while((s = din.readLine()) != null){//ファイルの終わりまで、1行読み、
          text.append(s);  //ファイルの行をtextに追加
          text.append("\n");
       }
        din.close();
    }    

    public static void main(String[] args){
      JFrame frame = new JFrame("Text Editor");//JFrameオブジェクトを生成
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      TextEditor h = new TextEditor();  
      frame.add(h, BorderLayout.CENTER); 
      frame.pack();
      frame.setVisible(true); 
   }
}

