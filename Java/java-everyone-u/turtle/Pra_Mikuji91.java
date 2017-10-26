public class Pra_Mikuji91 {
    public static void main(String[] args){
        if(mikuji(args[0])){
            System.out.println("あたり");
        } else {
            System.out.println("はずれ");
        }
    }
    static boolean mikuji(String s){
        int number;
        number = Integer.parseInt(s);
        return (number == 7);
    }
}
