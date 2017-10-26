public class T43 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      for(int j = 0; j < 8; j++){
         for(int i = 0; i < 5; i++){
            m.fd(50);
            m.lt(72);
         }
         m.fd(50);
         m.rt(45);
      }
   }
}
