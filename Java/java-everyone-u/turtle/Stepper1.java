public class Stepper1 extends Turtle{
   public static int n;   
   public static int size;
   private int j = 0;     
   public void step() { 
      if(j >= n)
         return;
      fd(size);
      rt(360/n);
      j++;      
   }
}
