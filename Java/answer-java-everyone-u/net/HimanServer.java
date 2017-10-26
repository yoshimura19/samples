//  練習問題 肥満度判定サーバ
import java.net.*;
import java.io.*;
import java.util.*;

public class HimanServer {
   public static void main(String[] args) throws IOException {
      ServerSocket serverS = null;
      Socket clientS = null;
      try{
          serverS = new ServerSocket(50001);
      } catch (IOException e) {
          System.out.println("ポートにアクセスできません。");
          System.exit(1);
      }

      try{
         clientS = serverS.accept();
      } catch (IOException e) {
         System.out.println("Acceptに失敗しました。");
         System.exit(1);
      }

      PrintWriter out = new PrintWriter(clientS.getOutputStream(), true);
      BufferedReader in = new BufferedReader(new InputStreamReader(clientS.getInputStream()));

      String fromS, fromU;
      HimandoHantei calc = new HimandoHantei();

      out.println("肥満度を判定します。");
      out.println("肥満度判定サーバ: あなたの体重(Kg)を入力してください。");
      fromU = in.readLine();  //クライアントが入力した体重を読む

      try{
         calc.w = Double.parseDouble(fromU);  //体重を設定
      } catch (NumberFormatException error){ calc.w = 0.0;}    
      
      out.println("肥満度判定サーバ: あなたの身長(cm)を入力してください。");
      fromU = in.readLine();  //クライアントが入力した身長を読む
      try{
         calc.h = Double.parseDouble(fromU);  //身長を設定
      } catch (NumberFormatException error){ calc.h = 0.0;}    

      fromS = "肥満度判定サーバ: あなたの標準体重は" + calc.calcStdWeight() + "Kg。" + "肥満度は" + calc.judgeHiman() + "です。";
      out.println(fromS);     //判定をクライアントに渡す

      in.close();
      out.close();
      clientS.close();
      serverS.close();
    }
}


class HimandoHantei{
   double w, h; //体重と身長
   double calcStdWeight(){ //標準体重を計算
      return h/100 * h/100 * 22; 
   }

   double calcHimando(){  //肥満度を計算
      return w /((h/100)*(h/100));
   }

   String judgeHiman(){  //肥満度を判定
      double him = calcHimando();
      if (him<=15) return "痩せすぎ";
      else if (him>15 && him<=20) return "痩せぎみ";
      else if (him>20 && him<=25) return "普通";
      else if (him>25 && him<=30) return "太りぎみ";
      else return "太りすぎ";
   }
}
