// リスト17.1 ファイルを読み、ArrayListを作り、平均を計算
import java.io.*;
import java.util.*;

public class ArrayListAve{
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
   }

   public static void main(String[] args){
      ArrayListAve r = new ArrayListAve();
      try{
          r.dataCalc();   
      }catch(IOException error) { System.out.println("IOエラー発生");}
   }
}
