public class MT51 extends Turtle implements Runnable{
   MT51(int x, int y, int a){
      super(x, y, a);
   }
   public void run(){
      for(int j = 0; j < 6; j++){
	 fd(10);    
	 rt(360/6); 
      }
   }        

   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame(600,300);
      MT51[] hm = new MT51[10];
      Thread[] th = new Thread[10];
      for(int i = 0 ; i < 10; i++){
	 hm[i] = new MT51(i * 50 + 25,150,0);
         th[i] = new Thread(hm[i]);
         f.add(hm[i]);
	 th[i].start();
      }
   }
}