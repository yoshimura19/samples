import java.io.*;
import java.util.*;
public class ScanFile {
    void dataSum() throws IOException {  // Scanner オブジェクトを作る
        Scanner sc = new Scanner(new BufferedReader(new FileReader("data.txt")));
        double sum = 0;
        while (sc.hasNextDouble()) { sum += sc.nextDouble(); } // double型のデータを読んで合計
        System.out.println(sum);
    }
    public static void main(String[] args){
        ScanFile r = new ScanFile();
        try{ r.dataSum();
        } catch(IOException error) { System.out.println("エラー発生 IO"); }
    }
}
