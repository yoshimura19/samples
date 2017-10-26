public class Q48 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      for(int i = 0; i < 18; i++){
	 m.fd(50);
	 switch (i % 3) {
	 case 0:
	    m.lt(120);
	    break;
	 default:
	    m.rt(30);
	 }
      }  
   }
}

