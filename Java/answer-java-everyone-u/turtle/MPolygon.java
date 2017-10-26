import java.awt.Color;
public class MPolygon extends HTurtle implements Runnable{
   int n, s;
   MPolygon(int x, int y, int a, int n, int s){
      super(x, y, a);
      this.n = n;   this.s = s;
   }
   public void run(){
      polygon(n,s);
   }
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      MPolygon m = new MPolygon(200,200,0, 10,50);  f.add(m);
      MPolygon m1 = new MPolygon(100,200,0, 5,50);  f.add(m1); 
      m1.setColor(new Color(255,0,0)); 
      m1.speed(5);                     
      Thread t = new Thread(m);
      Thread t1 = new Thread(m1);
      t.start();  
      t1.start(); 
      System.out.println("Main メソッドは終了する。");  
   }
}
