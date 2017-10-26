public class Race41 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Turtle m1 = new Turtle(0,100,90);
      Turtle m2 = new Turtle(0,300,90);
      Turtle.speedAll(3);
      f.add(m1); f.add(m2);
      for(int i = 0; i < 30; i++){
          if(Math.random() < 0.5){    //  [0,1]のdoubleの乱数
              m1.fd(10);
	 }else{
              m2.fd(10);
	 }
      }
      if(m1.getX() > m2.getX()) f.remove(m2);
      if(m1.getX() < m2.getX()) f.remove(m1);
   }
}


