public class Janken41 {
   public static void main(String[] args){
      int n = 10;
      for(int i = 0; i < n; i++) {
          double c = Math.random();
          if(c < 1.0/3){
              System.out.println("グー");
          }else if(c < 2.0/3){
              System.out.println("チョキ");
          }else{
              System.out.println("パー");
          }
      }
   }
}
