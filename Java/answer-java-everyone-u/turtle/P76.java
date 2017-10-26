public class P76 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame(1000,500);
      Turtle.withTurtleAll = false;
      for(int n = 3; n < 7; n++){
	 for(int r = 2; r <= 10; r++){
	    // たくさん Turtle を作成することにする。
	    MyTurtle m = new MyTurtle((r-1) *100,(n-2) * 100,0);
	    f.add(m);
	    m.flower(n, r, 20);
	 }
      }
   }
}
