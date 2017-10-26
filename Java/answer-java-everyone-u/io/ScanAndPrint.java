// 練習問題  ファイルを読み、書式付出力、計算
import java.io.*;
import java.util.*;

public class ScanAndPrint{
    void dataCalc() throws IOException{ //ファイルを読み、データを解析、計算
        String entry, name=" ";
        double weight=0, height=0;
        double aveW, aveH, sumW=0, sumH=0;
        int cnt=0;
        BufferedReader din = new BufferedReader(new FileReader("listdata.txt"));
        while ((entry=din.readLine()) != null) { //1行読む
            Scanner sc = new Scanner(entry);
            if(sc.hasNext()) name = sc.next();
            if(sc.hasNextDouble()) weight = sc.nextDouble();
            if(sc.hasNextDouble()) height = sc.nextDouble();
            sumW = sumW + weight;
            sumH = sumH + height;
            cnt++;
            System.out.printf("%s: %5.1fKg　%5.1fcm\n", name, weight, height);
        }
        System.out.println("-----------------------");
        System.out.printf("平均: %5.1fKg　%5.1fcm\n", sumW/cnt, sumH/cnt);
        din.close();
    }

    public static void main(String[] args){
        ScanAndPrint r = new ScanAndPrint();
        try{
            r.dataCalc();
        }catch(IOException error) { System.out.println("IOエラー発生");}
    }
}
