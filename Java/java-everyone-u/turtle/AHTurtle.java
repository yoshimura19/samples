public abstract class AHTurtle {
   abstract void fd(int s);
   abstract void bk(int s);
   abstract void rt(int s);
   abstract void lt(int s);
   public void polygon(int n, int s){  
      int a = 360/n;                   
      for(int j = 0; j < n; j++){      
         fd(s);                        
         rt(a);                        
      }
   }
   public void house(int s){
      polygon(4,s);                    
      fd(s); rt(30);
      polygon(3,s);
      lt(30); bk(s);                   
   }
}
