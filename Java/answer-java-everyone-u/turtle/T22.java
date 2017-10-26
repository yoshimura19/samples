public class T22 {
   public static void main(String[] args){   
      int x = 300, y = 200, d = 100;           //  int 型の変数を用意
      TurtleFrame f = new TurtleFrame(700,500);//引数のあるコンストラクタ呼出し
      Turtle m = new Turtle(x,y,180);   
      Turtle m1 = new Turtle(x+ d,y+ d,0);    
      java.awt.Color c = new java.awt.Color(255,0,0);// 赤色オブジェクトを生成
      m1.setColor(c);                         // m1 の色を赤色に指定
      f.add(m);                                 
      f.add(m1);                                
      m.fd(d);                                  
      m1.fd(d);                                 
      m.lt(90);                                 
      m1.lt(90);                                
      d = d / 2;   //d の値を d/2 に変更        
      m.fd(d);                                  
      m1.fd(d);                                 
      m1.moveTo(m);                             
   }
}
