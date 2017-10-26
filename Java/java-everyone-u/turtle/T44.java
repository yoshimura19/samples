public class T44 {
   public static void main(String[] args){
      TurtleFrame f;           
      f =  new TurtleFrame();  
      Turtle m = new Turtle(0,400,0); 
      f.add(m);
      int k = 1;
      while(m.getY() >= 20){
	 m.rt(90); m.fd(10); m.lt(90); m.fd(k);
	 k++;
      }
   }
}

