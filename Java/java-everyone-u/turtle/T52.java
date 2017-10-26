public class T52 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame(600,300);
      Turtle[][] tm = new Turtle[3][4]; 
      for(int n = 0 ; n < 3; n++){
         for(int m = 0 ; m < 4; m++){   
            tm[n][m] = new Turtle(m * 50 + 50,n * 50 + 50,0);
            f.add(tm[n][m]);
         }
      }
      for(int n = 0; n < 3; n++){
         for(int m = 0; m < 4; m++){
            for(int j = 0; j < n + 3; j++){
                tm[n][m].fd((m + 1) * 10);
                tm[n][m].rt(360/(n+3));
            }
         }
      }
   }
}
