import java.io.*;
import java.util.*;
public class ArrayListAve{
    void dataCalc() throws IOException{
        String entry;
        double weight = 0, sum = 0;
        List<Double> listW = new ArrayList<Double>(); // List型変数の宣言とArrayListの生成
        BufferedReader din = new BufferedReader(new FileReader("listdata.txt"));
        while ((entry=din.readLine()) != null) {     // ファイルから1行読む
            Scanner sc = new Scanner(entry);
            if(sc.hasNext()) sc.next();  // 名前を読み飛ばす
            if(sc.hasNextDouble()) weight = sc.nextDouble();  // 体重を取り出す
            listW.add(weight);
        }
        din.close();
        for(Double x: listW){   // 拡張for文
            sum = sum + x;      // 体重の合計計算
        }
        System.out.printf("平均: %5.1fKg\n", sum / listW.size());
    }
    public static void main(String[] args){
        ArrayListAve r = new ArrayListAve();
        try{
            r.dataCalc();
        } catch(IOException error){ System.out.println("エラー発生IO"); }
    }
}
