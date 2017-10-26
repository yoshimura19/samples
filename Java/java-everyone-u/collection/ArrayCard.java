// リスト17.3 トランプカードを一枚引く
import java.util.*;

public class ArrayCard{
   public static void main(String[] args){
       String[] suit = {"スペード", "ハート", "ダイヤ", "クラブ"};
       String[] num = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
       List<String> listC = new ArrayList<String>();
       for(String s : suit){
           for(String t : num){
	       listC.add(s + "の" + t);
           }
       }
       Collections.shuffle(listC);
       System.out.println(listC.get(0));
   }
}
