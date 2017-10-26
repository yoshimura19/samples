public class Q46 {
   public static void main(String[] args){
      int y = 1900;
      if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
	 System.out.println("Yes");
      }else{
	 System.out.println("No");
      }
   }
}