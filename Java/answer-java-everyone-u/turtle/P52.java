public class P52 {
  public static void main(String[] args){
    TurtleFrame f = new TurtleFrame(600,300);
    Turtle[] hm = new Turtle[10];
    for(int i = 0 ; i < 10; i++){
      hm[i] = new Turtle(i * 50 + 25,150,0);
      f.add(hm[i]);
    }
    for(int i = 0; i < 10; i++){
       int n = i+3;
       for(int j = 0; j < n; j++){
	     hm[i].fd(10);
	     hm[i].rt(360/n);
      }
    }
  }
}
