public class Tensen1 extends HTurtle{
   int psize = 10;
    public void fd(int s){  // オーバーライド
      int k, len;
      if(isDown()){
	 for(k = 0, len = 0 ; len + psize <= s; k++, len+= psize){
	    if(k % 2 == 0) down(); else  up();
	    super.fd(psize);
	 }
	 down();
	 super.fd(s - len);
      }else{
	 super.fd(s);
      }
   }
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Tensen1 m = new Tensen1();
      f.add(m);
      m.fd(100);
      m.rt(90);
      m.up(); m.fd(100); m.down();
      m.lt(90);
      m.polygon(5, 50);
   }
}
