public class Graph51 {
   public static void main(String[] args){
      TurtleFrame f = new TurtleFrame();
      int graph[] = {50,300,100,100,300,200,350,300};
      Turtle m = new Turtle(graph[0], graph[1],0);
      f.add(m);
      f.addMesh();
      for (int i = 1; i < graph.length/2; i++) {
	 m.moveTo(graph[i*2], graph[i*2+1]);
      }
   }
}
