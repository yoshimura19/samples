public class T45 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      for(int i = 0; i < 5; i++){
	 if(i == 3)
	    m.setColor(java.awt.Color.red);
	 m.fd(100);
	 m.rt(72);
      }
   }  
}


