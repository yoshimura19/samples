// リスト15.7 ファイルから読んだデータを，パターンを使って解析
import java.io.*;
import java.util.*;
public class ScanFile2 {
  void dataRead() throws IOException{   //パターンで読む
     Scanner s = new Scanner(new BufferedReader(new FileReader("listdata.txt")));
     String str;
     String p = "(\\S+)(\\s)(\\d+).(\\d+)(\\s)(\\d+).(\\d+)"; //正規表現を表す文字列
     while( (str = s.findInLine(p)) != null){
        System.out.println(str);
        s.skip("(\\s+)");  //行末記号を読み飛ばす
     }
      s.close();
    }

  public static void main(String[] args){
      ScanFile2 r = new ScanFile2();
      try{ r.dataRead();   
        }catch(IOException error) { System.out.println("IOエラー発生");}
  }
}
