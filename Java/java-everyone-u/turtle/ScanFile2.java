import java.io.*;
import java.util.*;
public class ScanFile2 {
    void dataRead() throws IOException {
        Scanner s = new Scanner(new BufferedReader(new FileReader("listdata.txt")));
        String str;
        String p = "(\\S+)(\\s)(\\d+).(\\d+)(\\s)(\\d+).(\\d+)";  // 正規表現 \sは空白,\dは数字,\Sは非空白文字,+は1つ以上
        while ((str = s.findInLine(p)) != null){  // パターンを見つけて読む
            System.out.println(str);
            s.skip("(\\s+)");  // 行末記号は読み飛ばす
        }
        s.close();
    }
    public static void main(String[] args){
        ScanFile2 r = new ScanFile2();
        try{ r.dataRead();
        } catch (IOException error) { System.out.println("エラー発生IO");}
    }
}
