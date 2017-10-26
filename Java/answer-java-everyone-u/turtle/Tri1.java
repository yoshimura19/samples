public class Tri1 {       
   public static void main(String[] args){
      int r = 100;
      int th = 36;
      TurtleFrame f =  new TurtleFrame();  
      Turtle m = new Turtle(); 
      f.add(m); 
      m.fd((int)(Math.sqrt(2) * r));            
      m.rt(135);             
      m.fd(r);            
      m.rt(90);             
      m.fd(r);            
  }
}
