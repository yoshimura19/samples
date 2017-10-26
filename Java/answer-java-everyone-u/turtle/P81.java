public class P81{
  public static void main(String[] args){
    TurtleFrame f = new TurtleFrame();
    Turtle m;
    if(args.length > 0){  
      m = new HTurtle();  
    }else{                
      m = new Turtle();   
    }
    f.add(m); 
    m.fd(100);
    m.rt(36);
    turtleStar(m);
  }
  static void turtleStar(Turtle t){
     for(int i = 0; i < 5; i++){	
        t.fd(100);
	if (t instanceof HTurtle) {
	  ((HTurtle)t).polygon(5,20);
	}
        t.rt(144);
     }
  }
}
