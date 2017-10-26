// 練習問題 ファイルを読み、ArrayListを作り、平均,最大,最小を表示
import java.io.*;
import java.util.*;

public class AveMaxMin{
   void dataCalc() throws IOException{ //ファイルを読み、コレクション作る
      String entry;
      double weight=0, sum=0;
      List<Double> listW = new ArrayList<Double>();
      BufferedReader din = new BufferedReader(new FileReader("listdata.txt"));
      while ((entry=din.readLine()) != null) { //1行読む
	 Scanner sc = new Scanner(entry);
	 if(sc.hasNext()) sc.next();
	 if(sc.hasNextDouble())weight = sc.nextDouble();
	 listW.add(weight);
      }
      din.close();
      for(Double x: listW){
	  sum = sum + x;
      }
      System.out.printf("平均: %5.1fKg\n", sum/listW.size());     
      System.out.printf("最大: %5.1fKg\n", Collections.max(listW));
      System.out.printf("最小: %5.1fKg\n", Collections.min(listW));
   }

   public static void main(String[] args){
      AveMaxMin r = new AveMaxMin();
      try{
          r.dataCalc();   
      }catch(IOException error) { System.out.println("IOエラー発生");}
   }
}
