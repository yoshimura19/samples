// リスト17.4 配列からArrayListを作り、平均を計算
import java.util.*;

public class ArrayasList{
   void dataCalc(){ 
      Double data[] ={60.5,45.2,78.4,82.4,78.4,75.7,89.7,56.8,63.7};
      double sum=0;
      List<Double> listW = Arrays.asList(data);
      for(Double x: listW){
        sum = sum + x;
      }
      System.out.printf("平均: %5.1fKg\n", sum/listW.size());       
   }

   public static void main(String[] args){
      ArrayasList r = new ArrayasList();
      r.dataCalc();   
   }
}
