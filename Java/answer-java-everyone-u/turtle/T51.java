public class T51 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame(600,300);
      Turtle[] hm = new Turtle[10];            // 配列オブジェクトを生成
      for(int i = 0 ; i < 10; i++){
         hm[i] = new Turtle(i * 50 + 25,150,0); // タートルを生成，配列の各要素に代入
         f.add(hm[i]);
      }
      for(int i = 0; i < 10; i++){
         for(int j = 0; j < 6; j++){       // 6回繰り返す
            hm[i].fd(10);                  // hm[i] に代入されている
            hm[i].rt(360/6);               // タートルに対するメソッド呼出し
         }
      }
  }
}
