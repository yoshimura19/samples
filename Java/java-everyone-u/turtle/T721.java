public class T721{
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Stepper1 m1 = new Stepper1(); f.add(m1);
      Stepper1 m2 = new Stepper1(); f.add(m2);
      m1.n = 4;  m1.size = 100;
      m2.n = 3;  m2.size = 100;  m2.up(); m2.moveTo(100,200,0); m2.down();
      for(int i = 0; i < 4; i++){
         m1.step();
         m2.step();
      }
   }
}
