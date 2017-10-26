// 練習問題 ファイルを読み、体重をキーにTreeMapを作る。
// 体重でソートされた一覧を表示する。
import java.io.*;
import java.util.*;
public class SortWeight{
   void dataCalc() throws IOException{
      String entry, name=" ";
      double weight=0;
      int index=0;
      Map<Double, String> map;  //Mapの変数を宣言
      map = new TreeMap<Double, String>();//TreeMapを生成
      BufferedReader din = new BufferedReader(new FileReader("listdata.txt"));
      while ((entry=din.readLine()) != null) { //1行読む
	 Scanner sc = new Scanner(entry);
	 if(sc.hasNext()) name = sc.next();
	 if(sc.hasNextDouble())weight = sc.nextDouble();
	 map.put(weight, name); //Mapに要素をput
      }
      din.close();
      Set<Double> c = map.keySet(); //キーのコレクションを取り出す
      for(Double d: c){ //変数dにキーであるDouble型のオブジェクトが代入される
        System.out.println(map.get(d) + "さんのデータ: " + d + "Kg");
      }
   }    
   public static void main(String[] args){
      SortWeight r = new SortWeight();
      try{
              r.dataCalc();   
      }catch(IOException error) { System.out.println("IOエラー発生");}
   }
}
