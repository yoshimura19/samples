public class P47 {
   public static void main(String[] args){
      int n = 4, r = 7;
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      for(r=2;;r++){
	 for(int j = 0; j < r; j++){
	    for(int i = 0; i < n; i++){
	       m.fd(50);
	       m.rt(360/n);
	    }
	    m.rt(360/r);
	 }
	 f.clear();
      }
   }
}