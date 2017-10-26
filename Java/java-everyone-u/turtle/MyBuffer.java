public class MyBuffer{    
   boolean avail = false;		// 登録されているか
   Object value;			// 登録される値
   synchronized void put(Object n) {
      if(avail){       // すでにデータが登録されているならば
	 try{	
	    wait();    //  消費されるのを待つ
	 }catch(InterruptedException e){}
      }
      value = n;  avail = true;
      notify();
   }
   synchronized Object get() {
      if(!avail){      // データが登録されていないならば
	 try{	
	    wait();    //  待つ
	 }catch(InterruptedException e){}
      }
      avail = false;
      notify();
      return value;
   }
}
