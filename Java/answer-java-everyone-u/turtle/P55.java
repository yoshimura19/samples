import java.awt.*;
public class P55 {
   public static void main(String[] args){
      int[] size = {20, 40, 20, 60};
      int[] n = {7, 5, 3, 4, 6};
      Color[] c = {Color.orange, Color.red, Color.blue};

      TurtleFrame f = new TurtleFrame(600,300);
      Turtle[] hm = new Turtle[10];
      for(int i = 0 ; i < hm.length; i++){
         hm[i] = new Turtle(i * 50 + 25,150,0); 
	 hm[i].setColor(c[i%c.length]);
         f.add(hm[i]);
      } 
      for(int i = 0; i < hm.length; i++){ 
	 int nn = n[i%n.length];
         for(int j = 0; j < nn; j++){
            hm[i].fd(size[i%size.length]);           
            hm[i].rt(360/nn);        
         }
      }  
   }
}
