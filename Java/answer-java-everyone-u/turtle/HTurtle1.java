public class HTurtle1 extends Turtle {    //Turtle を拡張する 
   public int polygon(int n, int s){   //polygonメソッドの定義 
      int a = 360/n;                     //曲がる角度を求めておく 
      for(int j = 0; j < n; j++){        //n 回繰り返す 
         fd(s);                           //s 前に進んで
         rt(a);                           //a 曲がるのを
      }
      return n * s;
   }
   public int house(int s){   //house メソッドの定義
      int d = 0;
      d += polygon(4,s);                      //polygon を利用
      fd(s); rt(30);
      d += polygon(3,s);
      lt(30); bk(s);                     //元の場所に戻しておく
      return d;
   }
} 
