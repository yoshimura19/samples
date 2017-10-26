public class SLock{
   boolean lo  = false;  // 終わって待っているスレッドがあれば true;
   synchronized void syncro() {
      if(lo){           // 待ってるスレッドがあれば
         lo = false;    //待ってるスレッドがあるという印をはずして
         notify();      // 起こしてあげる
      }else{            // そうでなければ
         lo = true;     // 待ってるスレッドがあるという印を付けて
         try{
            wait();     //  待つ
         }catch(InterruptedException e){}
      }
   }
}
