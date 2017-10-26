public class P58 {
   public static void main(String[] args){
      int n = 6;
      int s = 100;
      if(args.length > 0) n = Integer.parseInt(args[0]);
      if(args.length > 1) s = Integer.parseInt(args[1]);
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
