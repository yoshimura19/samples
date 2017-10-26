public class Race42 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Turtle m1 = new Turtle(0,100,90);
      Turtle m2 = new Turtle(0,300,90);
      Turtle.speedAll(3);
      f.add(m1); f.add(m2);
      for(int i = 0; i < 30; i++){
	 if(Math.random() < 0.5){
	    m1.fd(10);
	 }else{
	    m2.fd(10);
	 }
	 int d = m1.getX() - m2.getX();
	 if(d >= 50 || d <= -50) break;
      }
      if(m1.getX() > m2.getX()) f.remove(m2);
      if(m1.getX() < m2.getX()) f.remove(m1);
   }  
}


