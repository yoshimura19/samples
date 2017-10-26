public class P84 {
   public static void main(String args[]){
      TurtleFrame f = new TurtleFrame();
      Drawable[] hm = new Drawable[4];   
      hm[0] = new DrawHouse(); f.add((Turtle)hm[0]);
      hm[1] = new DrawStar(); f.add((Turtle)hm[1]); 
      hm[2] = new DrawText();  
      hm[3] = new DrawGraph();  f.add((Turtle)hm[3]); 
      Turtle.speedAll(1);
      while(true){
         int n = (int)(Math.random() * hm.length);
         int x = (int)(Math.random() * 400);
         int y = (int)(Math.random() * 400);
         hm[n].draw(x, y);
      }
   }
}
