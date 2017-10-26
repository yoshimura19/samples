interface Drawable
{
   public void draw(int x, int y);
}

class DrawHouse extends HTurtle implements Drawable{
   int s = 10;
   public void draw(int x, int y) {
      up(); moveTo(x, y, 0); down();
      house(s);
      s+= 10;
   }
}
class DrawStar extends Turtle  implements Drawable{
   int size = 10;
   public void draw(int x, int y) {
      up(); moveTo(x, y, 18); down();
      for(int i = 0; i < 5; i++){
         fd(size); rt(144);
      }
      size += 10;
   }
}
class DrawText  implements Drawable{
   int s = 1;
   public void draw(int x, int y) {
      for(int i = 0; i < x / 10; i++){
         System.out.print("*");
      }
      for(int i = 0; i < y / 10; i++){
         System.out.print("+");
      }
      System.out.println("");
   }
}
