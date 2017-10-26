public class Graph53 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      int graphs[][] = Turtle.turtleFig;
      Turtle m = new Turtle();
      f.add(m);
      f.addMesh();
      for (int j=0;j<graphs.length;j++) {
	 m.up();
	 m.moveTo(graphs[j][0] * 4 + 200,graphs[j][1] * 4 + 200,0);
	 m.down();
	 for (int i=1;i<(int)(graphs[j].length/2);i++) {
	    m.moveTo(graphs[j][i*2] * 4 + 200,graphs[j][i*2+1] * 4 + 200,0);
	 }
      }
   }
}
