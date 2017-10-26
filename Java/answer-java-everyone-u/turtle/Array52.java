public class Array52 {
   public static void main(String[] args){
      int[] a = {100, 50, 200, 100, 0, 200, 102, 40, 3, 100, 600};

      for(int i = 0; i < a.length; i++){
	 System.out.print(a[i] + " ");
      }
      System.out.println("");

      int sum = 0;
      for(int i = 0; i < a.length; i++){
	 sum += a[i];
      }
      System.out.println("和:" + sum);
      System.out.println("平均:" + sum/a.length);

      int maxind = 0;
      for(int i = 1; i < a.length; i++){
	 if (a[i] > a[maxind]) maxind = i;
      }
      System.out.println("最大値:" + a[maxind]);
      System.out.println("最大値を与える一番小さいインデックス:" + maxind);

      int c = 0;
      for(int i = 0; i < a.length; i++){
	 if (a[i] >= 100) c++;
      }
      System.out.println("100以上の数の個数:" + c);
   }
}
