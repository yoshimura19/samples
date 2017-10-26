public class P21 {         
   public static void main(String[] args){
      TurtleFrame f;           
      f =  new TurtleFrame();  
      Turtle m = new Turtle(); 
      Turtle m1 = new Turtle();
      f.add(m);                
      f.add(m1);               
      m.bk(100);               
      m.lt(90);                
      f.addMesh();
      m.bk(150);               
      m1.lt(90);               
      m1.bk(100);              
      f.clear();
   }
}   
