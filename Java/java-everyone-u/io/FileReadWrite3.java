//リスト15.4 キーボードから読む
import java.io.*;
public class FileReadWrite3{
  void dataInOut() throws IOException{   //キーボードからの入力を表示
    BufferedReader din = new BufferedReader(new InputStreamReader(System.in));
    String s;
    while((s = din.readLine()) != null){//1行読み
	System.out.println(s);    //標準出力へ表示
    }
    din.close();
  }    

  public static void main(String[] args){
      FileReadWrite3 r = new FileReadWrite3();
      try{
          r.dataInOut();   
        }catch(IOException error) { System.out.println("IOエラー発生");}
  }
}
