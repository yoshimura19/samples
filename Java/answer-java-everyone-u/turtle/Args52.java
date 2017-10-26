public class Args52 {
   public static void main(String[] args){
      double sum = 0;
      for(int i = 0 ; i < args.length; i++){
        sum += Integer.parseInt(args[i]);
      }
      System.out.println(sum);
   }
}
