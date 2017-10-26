public class P75{
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      CStepper m1 = new CStepper(4, 100); f.add(m1);
      CStepper m2 = new CStepper(3, 100, 100, 200, 0); f.add(m2);
      for(int i = 0; i < 4; i++){
         m1.step();
         m2.step();
      }
   }
}
