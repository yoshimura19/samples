public class P74 {
   public static void main(String[] args){
      int d = 0;
      TurtleFrame f = new TurtleFrame();
      HTurtle1 m = new HTurtle1();
      int s = 50;
      f.add(m);
      d += m.house(s);
      m.up(); m.lt(90); m.fd(50); m.rt(72); m.down();
      d += m.polygon(5, s / 2);
      m.up(); m.moveTo(100,100,0); m.down();
      d += m.polygon(10, s / 5);
      System.out.println(d);
   }
}
