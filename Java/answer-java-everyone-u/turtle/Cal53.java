public class Cal53 {
   public static void main(String[] args){
      int y = 2007;
      int m = 8;
      int d = 20;

      if(args.length <= 2){
	 System.out.println("Usage:  java Cal53 year month day");
	 System.exit(0);
      }
      y = Integer.parseInt(args[0]);
      m = Integer.parseInt(args[1]);
      d = Integer.parseInt(args[2]);

      int[] mon = {0,31,28,31,30,31,30,31,31,30,31,30,31};
      String[] week = {"日曜日","月曜日","火曜日","水曜日","木曜日","金曜日","土曜日"};
      int gantan = 1;

      int sum = 0;  //1900 年1月1日から何日目かを数える。

      for(int i = 1900; i < y; i++){
	 if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
	    sum += 366;
	 }else{
	    sum += 365;
	 }
      }
      for(int i = 1; i < m; i++){
	 sum += mon[i];
      }
      if(m >= 3 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)){
	 sum += 1; 
      }
      sum += d;
      System.out.println(sum);
      int wday = (sum - 1 + gantan) % 7;

      System.out.println(week[wday]);
   }
}