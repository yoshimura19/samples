import java.io.*;
public class MyBuffern{    
   /*  values にデータが記憶される。インデックス0 から順に記憶され，
    *   size の大きさまで記憶されると，先頭に戻って記憶される。topp が
    *   記憶の先頭，botomp が一番昔に記憶されてまだ消費されてないもの。
    */
   int size;
   Object values[];	      
   int topp = 0, botomp = 0;  
   MyBuffern(int size){
      this.size = size;
      values = new Object[size];
   }
   synchronized void put(Object n) {
      if(botomp == (topp + 1)%size){       // すでにデータが一杯なら
	 try{	
	    wait();    //  消費されるのを待つ
	 }catch(InterruptedException e){}
      }
      values[topp] = n;
      topp= (topp+1)%size;
      notify();
   }
   synchronized Object get() {
      if(botomp ==topp){      // データが全くないないならば
	 try{	
	    wait();    //  待つ
	 }catch(InterruptedException e){}
      }
      Object v = values[botomp];
      botomp = (botomp+1)%size;
      notify();
      return v;
   }

   /* サンプルプログラム。入力された文字列（改行で終わる）を記憶しなが
    * ら，1秒おきに大文字に変換して１つづつ表示する。記憶している文字列
    * がなければ，入力を待つ。5個以上記憶を要求されると，待ってから記憶
    * する。その間に入力された文字列も，OS によって記憶されるので，見た
    * 目には，待っていることが分からない。
    */

   public static void main(String[] args) {
      final MyBuffern b = new MyBuffern(5);
      Thread p = new Thread(){   //ここでは，匿名クラスを使ってみる。
	    public void run(){   // Thread クラスのサブクラスでこの run が定義された
	       try{              // クラスを定義し，そのオブジェクトを1個作成するという
		  while(true){   // 意味になる。
		     Thread.sleep(1000); 
		     System.out.println(((String)(b.get())).toUpperCase());
		  }             // b から取り出したものの表示をし続ける。
	       }catch(InterruptedException e){}
	    }
	 };                      //ここまでが匿名クラスの定義
      p.start();
      String c;
      BufferedReader bin = new BufferedReader(  // 入出力については15章参照。
	 new InputStreamReader(System.in));
      try{
	 while(true){
	    c = bin.readLine();            // 入力された文字列を b に登録しつづける。
	    b.put(c);
	 }
      }catch(IOException e){}
   }
}