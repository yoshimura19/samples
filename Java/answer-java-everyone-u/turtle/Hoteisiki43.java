public class Hoteisiki43 {
   public static void main(String[] args){
      int x;
      for (x = 0; x < 100; x++){
	 if(x % 2 == 0) continue;
         if(x * x - 145 * x + 3616 == 0)break; 
      }                                        
      if (x < 100) System.out.println(x); 
      else System.out.println("Not exist");
   }
}
