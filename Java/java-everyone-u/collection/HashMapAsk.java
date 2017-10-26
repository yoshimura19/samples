// リスト17.2 ファイルを読み、HashMapを作る。引数で指定された人のデータを表示する。
import java.io.*;
import java.util.*;
public class HashMapAsk{
   void dataCalc(String nn) throws IOException{
      String entry, name=" ";
      double weight=0, height=0;
      int index=0;
      Map<String, HData> map = new HashMap<String, HData>();  //Mapの変数を宣言,HashMapを生成
      BufferedReader din = new BufferedReader(new FileReader("listdata.txt"));
      while ((entry=din.readLine()) != null) { //1行読む
	 Scanner sc = new Scanner(entry);
	 if(sc.hasNext()) name = sc.next();
	 if(sc.hasNextDouble())weight = sc.nextDouble();
	 if(sc.hasNextDouble())height = sc.nextDouble();
	 map.put(name, new HData(weight, height)); //Mapに要素をput
      }
      din.close();
      HData r = map.get(nn);  //Mapからキーの値を検索
      if(r==null){System.out.println("データはありません");}
      else {System.out.println(nn + "さんのデータ: " + 
                                   r.w + "Kg, " + r.h + "cm"); 
      }
   }    
   public static void main(String[] args){
      HashMapAsk r = new HashMapAsk();
      if(args.length ==0){ System.out.println("名前を指定してください");}
      else {
         try{
              r.dataCalc(args[0]);   
         }catch(IOException error) { System.out.println("IOエラー発生");}
      }
   }

    class HData{  //データ保持用のクラス
	double w; //体重
        double h; //身長
        HData (double ww, double hh){
	    w = ww;
            h = hh;
	}
    }
}
