import java.io.*;
public class FileReadWrite {
    void dataInOut() throws IOException {  // 1文字ずつコピー
        int c;
        FileReader filein = new FileReader("Hello32.java"); // 入力ストリーム
        FileWriter fileout = new FileWriter("Back.java"); // 出力ストリーム
        while((c = filein.read()) != -1) {
            fileout.write(c);
        }
        filein.close();
        fileout.close();
    }
    public static void main(String[] args){
        FileReadWrite r = new FileReadWrite();
        try{ r.dataInOut();
        } catch(IOException error) { System.out.println("エラー発生IO"); }
    }
}
