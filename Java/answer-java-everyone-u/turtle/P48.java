public class P48 {       
   public static void main(String[] args){
      int r = 12;     // 枚数
      int n = 4;      // 何角形
      int size = 50;  // 1辺の長さ
      int distance = size/2;  // 中心から書き出し頂点までの距離
      int theta = 135;  // 書き出し頂点での傾き
//  int distance = -size/2, theta = 0;    教科書左の絵
//  int distance = size/2, theta = 0;     教科書右の絵

      TurtleFrame f =  new TurtleFrame();  
      Turtle m = new Turtle(); 
      f.add(m);
      for(int i = 0; i < r; i++){
	 m.up();m.fd(distance); m.rt(theta);m.down();
	 for(int j = 0; j < n; j++){
	    m.fd(size);
	    m.rt(360/n);
	 }
	 m.up(); m.lt(theta);m.bk(distance); m.down();
	 m.rt(360/r);
      }
   }
}