// リスト16.4 カウンセラーサーバ　マルチクライアントサポート
import java.net.*;
import java.io.*;

public class KaiwaMServer {
   public static void main(String[] args) throws IOException {
      ServerSocket serverS = null;
      boolean end = true;
      try {
         serverS = new ServerSocket(50000);
      } catch (IOException e) {
         System.out.println("ポートにアクセスできません。");
         System.exit(1);
      }
      while(end){
         new KaiwaMThread(serverS.accept()).start();
      }
      serverS.close();
   }
}


