public class Array51 {
   public static void main(String[] args){
      int[] a = new int[10];
      a[0] = 100;
      a[1] = 50;
      a[2] = 200;
      a[3] = 100;
      a[4] = 0;
      a[5] = 200;
      a[6] = 102;
      a[7] = 40;
      a[8] = 3;
      a[9] = 100;

      for(int i = 0; i < 10; i++){
	 System.out.print(a[i] + " ");
      }
      System.out.println("");

      int sum = 0;
      for(int i = 0; i < 10; i++){
	 sum += a[i];
      }
      System.out.println("和:" + sum);
      System.out.println("平均:" + sum/10);

      int maxind = 0;
      for(int i = 1; i < 10; i++){
	 if (a[i] > a[maxind]) maxind = i;
      }
      System.out.println("最大値:" + a[maxind]);
      System.out.println("最大値を与える一番小さいインデックス:" + maxind);

      int c = 0;
      for(int i = 0; i < 10; i++){
	 if (a[i] >= 100) c++;
      }
      System.out.println("100以上の数の個数:" + c);
   }
}
