public class P34 {
   public static void main(String[] args){
      int d = 100, x, y, a;
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle(200,300,0);
      f.add(m);
      m.fd(d);
      x = m.getX();
      y = m.getY();
      a = m.getAngle() - 45;
      Turtle m1 = new Turtle(x, y, a);
      f.add(m1);
      m1.fd(d);
      Turtle m2 = m.clone();
      f.add(m2);
      m.rt(45);
      m.fd(d);
      m2.tcolor = new java.awt.Color(0,255,255);
      m2.tscale = m2.tscale * 4;
      m2.fd(d);
      System.exit(0);  // Systemクラス (int status)正常終了は0,エラーは1
   }
}
