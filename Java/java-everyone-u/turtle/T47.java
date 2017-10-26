public class T47 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      for(int i = 0; i < 12; i++){
	 if(i % 3 == 0){             // i が 3 の倍数のとき
	    m.setColor(java.awt.Color.red);
	 }else if (i % 3 == 1) {    // i が 3 で割って余り1のとき
	    m.setColor(java.awt.Color.green);
	 }else{                    // それ以外（3 で割って余り2）のとき
	    m.setColor(java.awt.Color.yellow);
	 }
	 m.lt(30);
	 m.fd(50);
      }
   }
}





