public class SLock3{
   int n = 3;     //待ち合わせの個数。
   int num = 0;   // 終わって待っているスレッドの個数 true。
   synchronized void syncro() {
      if(num == n-1){           // 待ってるスレッドが n-1 なら
	 num = 0;
         notifyAll();      // 起こしてあげる
      }else{            // そうでなければ
	 num += 1;
         try{
            wait();     //  待つ
         }catch(InterruptedException e){}
      }
   }
   /* コンストラクター */
   SLock3(){
   }
   SLock3(int n){
      this.n = n;
   }
}
