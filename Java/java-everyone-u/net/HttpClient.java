// リスト16.1 httpクライアント
import java.io.*;
import java.net.*;

public class HttpClient {
   public static void main(String[] args) throws IOException {
      Socket soc = null;
      BufferedReader in = null;
      PrintWriter out = null;
      String host = "www.google.co.jp";
      soc = new Socket(host, 80);
      in = new BufferedReader(new InputStreamReader(soc.getInputStream()));
      out = new PrintWriter(soc.getOutputStream(), true);

      out.print("GET " + "/index.html" + " HTTP/1.0\r\n");
      out.println("Host: " + host + ":80\r\n");

      String line;
      while ((line = in.readLine()) != null) {
	 System.out.println(line);
      }
      in.close();
      out.close();
      soc.close();
   }
}
