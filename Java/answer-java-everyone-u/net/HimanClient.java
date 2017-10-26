// 練習問題  肥満度判定クライアント
import java.io.*;
import java.net.*;

public class HimanClient {
   public static void main(String[] args) throws IOException {

   Socket himanS = null;
   BufferedReader in = null;
   PrintWriter out = null;

   try{
      himanS = new Socket(InetAddress.getLocalHost(), 50001);
      in = new BufferedReader(new InputStreamReader(himanS.getInputStream()));
      out = new PrintWriter(himanS.getOutputStream(), true);
      } catch (UnknownHostException e) {
          System.out.println("ホストに接続できません。");
          System.exit(1);
      } catch (IOException e) {
          System.out.println("IOコネクションを得られません。");
          System.exit(1);
      }

    BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));
    String fromS;
    String fromU;

    System.out.println(in.readLine());  //開始メッセージを読んで表示
    System.out.println(in.readLine()); //体重入力プロンプト
    fromU = stdIn.readLine();        //体重
    out.println(fromU);   
    System.out.println(in.readLine()); //身長入力プロンプト
    fromU = stdIn.readLine();        //身長
    out.println(fromU);   
    fromS=in.readLine();             //判定を読む
    System.out.println(fromS);       //判定を表示

    out.close();
    in.close();
    stdIn.close();
    himanS.close();
    }
}



