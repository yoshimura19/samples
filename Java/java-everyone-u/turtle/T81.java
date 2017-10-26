public class T81{
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Turtle m;  
      if(args.length > 0){     // コマンド実行時に引数が与えられれば
         m = new HTurtle();    // HTurtle を生成して m に代入
      }else{                   // そうでなければ 
         m = new Turtle();     // Turtle を生成して m に代入
      }
      f.add(m);
      m.fd(100); m.rt(36);     //m は HTurtle と Turtle と両方の可能性あり
      turtleStar(m); 
   }
   static void turtleStar(Turtle t){ 
      for(int i = 0; i < 5; i++){
         t.fd(100); t.rt(144);
      }
   }
}
