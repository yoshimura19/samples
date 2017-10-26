// リスト16.5 カウンセラーサーバ　通信処理スレッド
import java.net.*;
import java.io.*;
import java.util.*;

public class KaiwaMThread extends Thread {
   Socket socket = null;

   public KaiwaMThread(Socket s) {
      super("KaiwaMSThread");
      socket = s;
   }

    public void run() {
      try{
         PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
         BufferedReader in = new BufferedReader(
                           new InputStreamReader(socket.getInputStream()));

         String fromC, fromUser;
         Counsel c = new Counsel();
         out.println("何でも話してください");
         while ((fromUser = in.readLine()) != null) {
            fromC = c.kaiwa(fromUser);
            out.println(fromC);
            if (fromC.equals("ではまたにしましょう。")) break;
         }
         in.close();
         out.close();
         socket.close();
      } catch (IOException e) { 
         System.out.println("runメソッド実行中例外: " + e);
         System.exit(1);
      }
   }
}

class Counsel{
   int i, n=0;
   String[] henji = { 
       "興味がありますね。", 
       "ほう、そうですか。", 
       "もっと聞かせてください。",
       "それはそれは。", 
       "それで?"};
   String kaiwa(String user){
      i = (int)(Math.random()* henji.length);
      n++;
      if(n>10) return  "ではまたにしましょう。";
      else if(i==0) return (user + "とは" + henji[i]);
      else return henji[i];
   }
}  
