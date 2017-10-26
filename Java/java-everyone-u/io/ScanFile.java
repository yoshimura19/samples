// リスト15.6 ファイルから読んだデータを，Scannerで解析
import java.io.*;
import java.util.*;

class ScanFile {
   void dataSum() throws IOException{   //数値を読んで合計
      Scanner sc = new Scanner(new BufferedReader(new FileReader("data.txt")));
      double sum = 0;
      while (sc.hasNextDouble()) { sum += sc.nextDouble(); } //double型のデータを読んで合計
      sc.close();
      System.out.println(sum);
   }

   public static void main(String[] args){
      ScanFile r = new ScanFile();
      try{ r.dataSum();   
      }catch(IOException error) { System.out.println("IOエラー発生");}
   }
}
