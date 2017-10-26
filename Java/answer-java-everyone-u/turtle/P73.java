public class P73 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame(1000,500);
      MyTurtle m = new MyTurtle();
      Turtle.withTurtleAll = false;
      f.add(m);
      for(int n = 3; n < 7; n++){
	 for(int r = 2; r <= 10; r++){
	    m.up(); m.moveTo((r-1) *100,(n-2) * 100,0); m.down();
	    m.flower(n, r, 20);
	 }
      }
   }
}
