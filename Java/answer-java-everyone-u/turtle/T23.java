public class T23 {
   public static void main(String[] args){
      int d = 100, x, y, a;
      TurtleFrame f = new TurtleFrame(); 
      Turtle m = new Turtle(200,300,0);  
      f.add(m);                       
      m.fd(d);                        
      x = m.getX();                // m のX 座標のとり出し
      y = m.getY();                // m のY 座標のとり出し
      a = m.getAngle() - 45;       // m の角度のとり出し
      Turtle m1 = new Turtle(x, y, a); //m1 の生成
      f.add(m1);              
      m1.fd(d);
      Turtle m2 = m.clone();       //m2 の生成
      f.add(m2);                
      m.rt(45);                        
      m.fd(d);
      m2.tcolor = new java.awt.Color(0,255,255); // m2 の亀の色を水色に変える
      m2.tscale = m2.tscale * 4;  // m2 の亀を現在の 4 倍の大きさにする
      m2.fd(d);               
   }
}
