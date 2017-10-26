import java.awt.Color;
public class CStepper extends Turtle{
   private int n;
   private int size;
   private int j = 0;
   public CStepper(int n, int size, int x, int y, int angle){
      super(x, y, angle);    //Turtle のコンストラクタ呼出し
      this.n = n;            //インスタンス変数 n に 引数 n を設定
      this.size = size;      //インスタンス変数 size の設定
   }
   public CStepper(int n, int size){
      this(n, size, 200, 200, 0); //上記のコンストラクタ呼出し
   }
   public void step() {
      if(j >= n)
         return;      //描き終えていたならすぐ終了
      fd(size);
      rt(360/n);
      j++;            //j の値を 1 増やす
   }
   /* メインメソッドは，リスト 7.6 にある。*/
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame(600,300);
      int[] size = {100,28,90,40,2,100,40,2, 30, 20};
      int[] n = {6, 5, 3,10,20,3,4,5,3,5};
      Color[] c = {Color.red, Color.blue, Color.cyan, Color.yellow};
      CStepper[] hm = new CStepper[10];
      for(int i = 0 ; i < 10; i++){
	 hm[i] = new CStepper(n[i], size[i], i * 50 + 25,150,0);
	 hm[i].setColor(c[i % c.length]);
	 f.add(hm[i]);
      }
      for(int j = 0; j < 20; j++){
	 for(int i = 0; i < 10; i++){
	    hm[i].step();
	 }
      }
   }
}
