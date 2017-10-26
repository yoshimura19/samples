import java.awt.Color;
public class P56 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      Turtle m = new Turtle();
      f.add(m);
      Color[] c = {Color.red, Color.green, Color.yellow};
      for(int i = 0; i < 12; i++){
	 m.setColor(c[i%3]);
	 m.lt(30);
	 m.fd(50);
      }
   }
}





