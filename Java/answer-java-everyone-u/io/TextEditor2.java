// テキストエディタ
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.io.*;

public class TextEditor2 extends JPanel implements ActionListener{
    JTextArea text;
    String filename;  //編集するファイル
    JButton open, save;
    JFileChooser chooser;
    TextEditor2() { 
        JPanel p = new JPanel(); //ボタンを置くパネル
        open = new JButton("開く");
        save = new JButton("保存");
        open.addActionListener(this);
        save.addActionListener(this);
        p.setBackground(Color.WHITE);
        p.add(open);
        p.add(save);
        text = new JTextArea(); //JTextAreaオブジェクト
        JScrollPane pane = new JScrollPane(text);  //textをJScrollPaneに入れる
        pane.setPreferredSize(new Dimension(300, 300));

        setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
        add(pane);//上部にJScrollPane
        add(p);//下部にボタンを置いたパネルを配置

        chooser = new JFileChooser();
        chooser.addActionListener(this);
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

    void dataWrite() throws IOException{  //ファイルへデータを書く
      BufferedWriter dout = new BufferedWriter(new FileWriter(filename));
      dout.write(text.getText());
      dout.close();
    }    

    public void actionPerformed(ActionEvent e) {
       Object obj = e.getSource();
       if( obj == open){
	   chooser.showOpenDialog(this);
           if(filename != null){
	       text.setText(null);//テキスト域のクリア
             try{
               dataRead();   //ファイルからデータを読む
             }catch(IOException error) 
                    { System.out.println("ファイルが読めませんでした。");}
           }
       }else if(obj == save && filename != null){
          try{
             dataWrite();   //ファイルへデータを書く
           }catch(IOException error) { System.out.println("書き込みエラー");}
       }else if(obj == chooser){
           File ff = chooser.getSelectedFile(); //選択されたファイル
           if(ff!=null) filename = ff.getAbsolutePath();//選択されたファイルのパス
	   System.out.println(filename);
       }

    }

    public static void main(String[] args){
      JFrame frame = new JFrame("Text Editor");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      TextEditor2 h = new TextEditor2();  
      frame.add(h, BorderLayout.CENTER); 
      frame.pack();
      frame.setVisible(true); 
   }
}

