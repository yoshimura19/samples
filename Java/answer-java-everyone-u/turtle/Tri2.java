public class Tri2 {
   public static void main(String[] args){
      int r = 100;
      int th = 36;
      TurtleFrame f =  new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      m.fd(r);
      m.rt(180 - th);
      m.fd((int)(r * Math.cos(th * Math.PI/180)));
      m.rt(90);
      m.fd((int)(r * Math.sin(th * Math.PI/180)));
  }
}
