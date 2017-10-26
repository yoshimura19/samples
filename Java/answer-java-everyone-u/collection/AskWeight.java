// 練習問題 ファイルを読み、ArrayListを作り、引数で指定された名前の体重を出力
import java.io.*;
import java.util.*;

public class AskWeight{
    void dataCalc(String nn) throws IOException{ //ファイルを読み、コレクション作る
        String entry, name=" ";
        double weight=0;
        int index=0;
        List<Double> listW = new ArrayList<Double>();
        List<String> listN = new ArrayList<String>();
        BufferedReader din = new BufferedReader(new FileReader("listdata.txt"));
        while ((entry=din.readLine()) != null) { //1行読む
            Scanner sc = new Scanner(entry);
            if(sc.hasNext()) name = sc.next();
            if(sc.hasNextDouble())weight = sc.nextDouble();
            listN.add(name);
            listW.add(weight);
        }
        din.close();
        index = listN.indexOf(nn);     // 引数のString nn と一致を探す
        if(index == -1){System.out.println("データはありません");}
        else {System.out.println(nn + "さんの体重は" + listW.get(index) + "Kg"); }   }

    public static void main(String[] args){
        AskWeight r = new AskWeight();
        if(args.length ==0){ System.out.println("名前を指定してください");}
        else {
            try{
                r.dataCalc(args[0]);
            }catch(IOException error) { System.out.println("IOエラー発生");}
        }
    }
}
