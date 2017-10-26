public class Mikuji92 {
    public static void main(String[] args){
        if(mikuji(args[0])){
            System.out.println("あたり");
        }else{
            System.out.println("はずれ");
        }
    }
    static boolean mikuji(String s){
        int number;
        try{
            number = Integer.parseInt(s);
        }catch(NumberFormatException e){
            System.out.println(e.getMessage());
            System.out.println("引数に数を指定してください");
            number = -1;
        }
        return (number == 7);      // number と 7 が等しければ true,
    }                             // 等しくなければ false が返る`
}


