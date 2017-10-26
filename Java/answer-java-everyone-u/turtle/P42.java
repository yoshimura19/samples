public class P42 {
   public static void main(String[] args){
      TurtleFrame f;
      f =  new TurtleFrame();
      Turtle m = new Turtle(0,400,90);
      f.add(m);
      for(int i = 0; i < 40; i++) {
          m.fd(10);
          m.lt(90);
          m.fd(10);
          m.rt(90);
      }
   }
}
