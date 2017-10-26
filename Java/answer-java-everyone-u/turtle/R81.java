class R81 {
  public static void main(String[] args){
    TurtleFrame f; 
    f =  new TurtleFrame();
    Rabbit m = new Rabbit();	// Rabbit を作成
    Turtle m1 = new Turtle();	// Turtle を作成
    m.tscale = 2.0;
    m1.tscale = 2.0;
    f.add(m);
    f.add(m1);
    m.fd(100);
    m.rt(90);
    m.fd(150);
    m1.rt(90);
    m1.fd(100);
    }
}
