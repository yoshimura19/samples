//リスト15.2 文字コードの変換
import java.io.*;
public class ChangeCode {
  void dataInOut() throws IOException{ 
       int c;
       InputStreamReader filein = new InputStreamReader(
               new FileInputStream("Text.txt"), "SJIS"); //入力ストリーム
       OutputStreamWriter fileout = new OutputStreamWriter(
               new FileOutputStream("Back.txt"), "ISO2022JP"); //出力ストリーム
       while((c = filein.read()) != -1) {//ファイルの最後まで1文字読み、
            fileout.write(c);	   //それを書き出す
       }
       filein.close();
       fileout.close();
  }    
  public static void main(String[] args){
      ChangeCode r = new ChangeCode();
      try{
          r.dataInOut();   
        }catch(IOException error) { System.out.println("IOエラー発生");}
  }
}



