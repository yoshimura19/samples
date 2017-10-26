public class P22 {
   public static void main(String[] args){
      int x = 50, y = 100, d = 200;
      TurtleFrame f = new TurtleFrame(700,500);
      Turtle m = new Turtle(x,y,180);
      Turtle m1 = new Turtle(x+ d,y+ d,0);
      java.awt.Color c = new java.awt.Color(255,0,0);
      m1.setColor(c);
      f.add(m);
      f.add(m1);
      m.fd(d);
      m1.fd(d);
      m.lt(90);
      m1.lt(90);
      d = d / 2;
      m.fd(d);
      m1.fd(d);
      m1.moveTo(m);
   }
}
