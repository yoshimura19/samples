public class T54 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame(600,300);
      Turtle[] hm = new Turtle[10];            // 配列オブジェクトを生成
      for(int i = 0 ; i < 10; i++){
         hm[i] = new Turtle(i * 50 + 25,150,0); // タートルを生成，配列の各要素に代入
         f.add(hm[i]);
      }
      for(Turtle m:hm){ 
	 for(int j = 0; j < 6; j++){
	    m.fd(10);     
	    m.rt(360/6);  
	 }
      }
   }
}
