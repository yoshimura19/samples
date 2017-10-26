/** お絵かきメソッドを持つTurtle クラス。
 */
public class MyTurtle extends HTurtle{
   /** n 軒の家を大きさ s で w の間隔で描く。
       コメントが2文以上になっている場合，javadoc は，1つ目だけを概要に載せる。*/ 
   public void houses(int n, int s, int w){
      for(int i = 0; i < n; i++){
	 house(s);
	 rt(90); up(); fd(w+s); down(); lt(90);
      }
   }

   /** n 角形の周りにm 角形を1辺の長さ s で描く。*/ 
   public void ppolygon(int n, int m, int s){
      for(int j = 0; j < n; j++){
	 polygon(m, s);
	 fd(s);
	 lt(360/n);
      }
   }

   /** 1辺の長さ s の n 角形を r 枚回しながら描く。*/ 
   public void flower(int n, int r, int s){
      for(int j = 0; j < r; j++){
	 polygon(n, s);
	 rt(360/r);
      }
   }
   /** 1辺の長さ s の n 角形を r 枚回しながら描く。
       n 角形の一つの辺は，回転の中心から l だけ移動した場所から
       d だけ右回転した方向に始まる。*/ 
   public void rflower(int n, int r, int s, int l, int d){
      for(int j = 0; j < r; j++){
	 up(); fd(l);rt(d);down();
	 polygon(n, s);
	 up(); lt(d);bk(l);down();
	 rt(360/r);
      }
   }

   /** (x, y) を左下の座標にし，1辺の長さ s で家の絵を描く。*/ 
   public void house(int x, int y, int s){
      up(); moveTo(x, y, 0); down();
      house(s);
   }

   /** n 軒の家を大きさ s で w の間隔で描く。*/ 
   public void houses(int x, int y, int n, int s, int w){
      up(); moveTo(x, y, 0); down();
      houses(n, s, w);
   }

   /** コンストラクタ，練習問題 7.8 で追加。*/
   public MyTurtle(int x, int y, int angle){
      super(x, y, angle);
   }
   public MyTurtle(){
      super();
   }
}