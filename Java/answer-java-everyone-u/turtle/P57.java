public class P57 {
   public static void main(String[] args){
      int n = Integer.parseInt(args[0]);
      int s = Integer.parseInt(args[1]);
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      int i;
      for(i = 0; i < n; i++){
         m.fd(s);
         m.rt(360/n);
      }
   }  
}
