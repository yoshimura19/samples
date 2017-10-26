public class Tensen2 extends HTurtle{
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      HTurtle m = new Tensen();
      f.add(m);
      m.fd(100);  
      m.rt(90);
      m.up(); m.fd(100); m.down();
      m.lt(90);
      m.polygon(5, 50);
   }
}
