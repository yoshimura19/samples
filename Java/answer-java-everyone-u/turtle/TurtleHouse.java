public class TurtleHouse {
  public static void main(String[] args){
     int x = 100, y = 300, d = 50;
     int a = 60;
     TurtleFrame f;
     f =  new TurtleFrame();
     Turtle m = new Turtle(x, y, 0);
     f.add(m);
     m.fd(d);
     m.lt(90);
     m.fd(d/2);
     m.rt(180-a);
     m.fd(d);
     m.rt(a);
     m.fd(2*d);
     m.rt(a);
     m.fd(d);
     m.rt(180-a);
     m.fd(d/2);
     m.lt(90);
     m.fd(d);
     m.up();
  }
}
