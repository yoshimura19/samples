public class Sleep10 {
   public static void main(String[] args)    {
      System.out.println("Timer Start");
      try{               
         for(int i = 10; i >= 0; i--){
            Thread.sleep(1000);
            System.out.println(i);
         }               
      }catch(InterruptedException e){} 
   }
}
