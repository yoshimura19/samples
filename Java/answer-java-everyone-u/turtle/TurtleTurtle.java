public class TurtleTurtle extends DrawGraph{
   public int x = 200;
   public int y = 200;
   public int angle = 0;
   public double scale = 1.0;
   public int step = 80;
   
   int[][][] turtles = {Turtle.turtleLFig, Turtle.turtleFig, 
			Turtle.turtleRFig, Turtle.turtleFig};
   int which;

   TurtleTurtle(int x, int y, int angle){
      this.x = x; this.y = y; this.angle = angle;
   }
   void forward(){
      x = x + (int)(step * Math.sin(Math.toRadians(angle)));
      y = y - (int)(step * Math.cos(Math.toRadians(angle)));
      draw(x, y, trans(turtles[which%turtles.length], angle, scale));
      which++;
   }

   void rightTurn(int th){
      angle += th; 
      x = x + (int)(step * Math.sin(Math.toRadians(angle)));
      y = y - (int)(step * Math.cos(Math.toRadians(angle)));
      draw(x, y, trans(turtles[which%turtles.length], angle, scale));
      which++;
   }

   public static void main(String[] args){
      TurtleTurtle m = new TurtleTurtle(200,550,-30);
      TurtleFrame f = new TurtleFrame(800,800);
      f.add(m);
      for(int i = 0; i < 4; i++){
	 m.forward();
      }
      for(int i = 0; i < 7; i++){
	 m.rightTurn(30);
	 m.scale *= 1.2;
	 m.step *= 1.2;
      }
      Turtle m1 = new Turtle(m.x, m.y, m.angle);
      m1.tscale = m.scale;
      m1.withTurtleAll = true;
      f.add(m1);
      m1.up();
      m1.speed(100);
      m1.fd(100);
      m1.rt(90);
      m1.fd(200);
      m1.rt(90);
      m1.fd(250);
      m.speed(100);
      m.up();
      m.tscale = 1.0;
      m.moveTo(230,613,-30);
      m.speed(1000);
      m.moveTo(200,550,-30);
   }
}