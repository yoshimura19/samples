// リスト15.8 ファイルへ書式付き出力
import java.io.*;
public class PrintFile{
   void dataInOut() throws IOException{ 
   String name = "青田";  //書き出すデータ
   double weight = 60.5;
   double height = 170.6;
      PrintWriter fileout = new PrintWriter("list.txt");
      fileout.printf("%s %.1f %.1f", name, weight, height);
      fileout.close();
  }    
  public static void main(String[] args){
     PrintFile r = new PrintFile();
     try{
        r.dataInOut();   
     }catch(IOException error) { System.out.println("IOエラー発生");}
  }
}
