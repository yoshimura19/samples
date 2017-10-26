public class P71 {
  public static void main(String[] args){
    TurtleFrame f = new TurtleFrame();
    MyTurtle m = new MyTurtle();
    int s = 50;
    f.add(m);
    m.houses(5, 20, 10);
  }
}
