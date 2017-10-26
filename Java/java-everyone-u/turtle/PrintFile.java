import java.io.*;
public class PrintFile{
    void dataInOut() throws IOException{
        String name = "青田";
        double weight = 60.5, height = 170.6;
        PrintWriter fileout = new PrintWriter("list.txt"); // 出力ストリーム生成
        fileout.printf("%s %.lf %.lf", name, weight, height); // 書式付きで出力
        fileout.close();
    }
    public static void main(String[] args){
        PrintFile r = new PrintFile();
        try{ r.dataInOut();
        } catch(IOException error) { System.out.println("エラー発生IO"); }
    }
}
