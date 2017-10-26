public class Graph52 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      int graphs[][] = {{50,300,100,100,300,200,350,300},
			{100,100,100,50},{150,300,200,300,175,250,150,300}};
      Turtle m = new Turtle();
      f.add(m);
      f.addMesh();
      for (int j = 0; j < graphs.length; j++) {
	 m.up();
	 m.moveTo(graphs[j][0], graphs[j][1]);
	 m.down();
	 for (int i = 1; i < (int)(graphs[j].length / 2) ; i++) {
	    m.moveTo(graphs[j][i*2], graphs[j][i*2+1]);
	 }
      }
   }
}
