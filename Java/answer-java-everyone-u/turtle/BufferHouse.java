public class BufferHouse{
   public static void main(String[] args)    {
      MyBuffer sl = new MyBuffer();
      TurtleFrame f = new TurtleFrame();
      Turtle t1 = new SquareProducer(sl);  f.add(t1);
      Turtle t2 = new SquareConsumer(sl);  f.add(t2);
      (new Thread((Runnable)t1)).start();
      (new Thread((Runnable)t2)).start();
   }
}

class SquareProducer extends HTurtle implements Runnable{
   MyBuffer mes;
   SquareProducer(MyBuffer lo){ mes = lo; } // コンストラクタ
   public void run(){
      int aa[];
      while(true){
	 speed((int)(Math.random() * 20));
	 aa = new int[3];//  x, y, size
	 aa[0] = (int)(Math.random() * 400);
	 aa[1] = (int)(Math.random() * 400);
	 aa[2] = (int)(Math.random() * 100);
	 up(); moveTo(aa[0], aa[1], 90); down();
	 polygon(4, aa[2]);
	 mes.put(aa);
      }
   }
}
class SquareConsumer extends HTurtle implements Runnable{
   MyBuffer mes;
   SquareConsumer(MyBuffer lo){ mes = lo; } // コンストラクタ
   public void run(){
      setColor(java.awt.Color.red);
      while(true){
	 speed((int)(Math.random() * 20));
	 int[] aa = (int[])(mes.get());
	 up(); moveTo(aa[0], aa[1], 30); down();
	 polygon(3,aa[2]);
      }
   }
}

