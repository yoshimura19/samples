public class P431 {       
   public static void main(String[] args){
      TurtleFrame f;           
      f =  new TurtleFrame();  
      Turtle m = new Turtle(0,400,0); 
      f.add(m);
      for(int k = 1; k <= 37; k+= 2){
	 m.rt(90); m.fd(10); m.lt(90); m.fd(k);
      }
   }
}