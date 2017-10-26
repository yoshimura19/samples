public class Array53 {
   public static void main(String[] args){
      int[][] a = {{2,5,4,2},{2,2,4,1},{1,3,4,2}};

      for(int i = 0; i < a.length; i++){
	 for(int j = 0; j < a[i].length; j++){
	    System.out.print(a[i][j] + " ");
	 }
	 System.out.println("");
      }
	 System.out.println("");

      int sum;
      for(int i = 0; i < a.length; i++){
	 sum = 0;
	 for(int j = 0; j < a[i].length; j++){
	    sum += a[i][j];
	 }
	 System.out.print(sum + " ");
      }
      System.out.println("");

      for(int j = 0; j < a[0].length; j++){  // 全ての行が同じ個数でないと動かない
	 sum = 0;
	 for(int i = 0; i < a.length; i++){
	    sum += a[i][j];
	 }
	 System.out.print(sum + " ");
      }
      System.out.println("");

      sum = 0;
      for(int i = 0; i < a.length; i++){
	 for(int j = 0; j < a[i].length; j++){
	    sum += a[i][j];
	 }
      }
      System.out.println(sum);
   }
}