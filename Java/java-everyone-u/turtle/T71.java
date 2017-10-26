public class T71 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      HTurtle m = new HTurtle();
      int s = 50;
      f.add(m);   
      m.house(s); 
      m.up(); m.lt(90); m.fd(50); m.rt(72); m.down();
      m.polygon(5, s / 2); 
      m.up(); m.moveTo(100,100,0); m.down();
      m.polygon(10, s / 5);
   }
}
