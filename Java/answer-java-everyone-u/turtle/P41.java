public class P41 {
   public static void main(String[] args){
//    int s = 100, n = 5;
      int s = 1, n = 360;
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      for(int i = 0; i < n; i++){
         m.fd(s);
         m.rt(360/n);
      }
   }
}
