/** 最初のプログラムの例 */
public class P21 {
   public static void main(String[] args){
       //      TurtleFrame f;             // 変数 f の型宣言
       //f =  new TurtleFrame();    // TurtleFrameを生成しfに代入
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();   // Turtle を生成し，m の初期値として代入
      Turtle m1 = new Turtle();  // もう一つ生成し，m1 の初期値として代入
      f.add(m);                  // f に m を追加 画面にカメサンを追加
      f.add(m1);                 // f に m1 を追加
      f.addMesh();
      m.fd(100);                 // m よ前に 100 進め
      m.rt(90);                  // m よ右に 90 度回れ
      m.fd(150);                 // m よ前に 150 進め
      m1.rt(90);                 // m1 よ右に 90 度回れ
      m1.fd(300);                // m1 よ前に 100 進め
      m1.lt(270);
      m1.bk(300);
      f.clear();
   }
}
