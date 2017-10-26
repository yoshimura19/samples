public class T48 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      for(int i = 0; i < 12; i++){
	 switch (i % 3) {
	 case 0:
	    m.setColor(java.awt.Color.red);
	    break;
	 case 1:
	    m.setColor(java.awt.Color.green);
	    break;
	 case 2:
	    m.setColor(java.awt.Color.yellow);
	    break;
	 }
	 m.lt(30);  m.fd(50);
      }
   }
}
