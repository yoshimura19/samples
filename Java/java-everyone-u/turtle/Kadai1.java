public class Kadai1 {
    public static void main(String[] args){
        TurtleFrame f = new TurtleFrame(600, 300);  // あとでコンストラクタに
        Turtle[] hm = new Turtle[3];
        for(int i = 0; i < 3; i++) {
            hm[i] = new Turtle(i * 200 + 25, 150, 0);
            f.add(hm[i]);
        }
        int n;
        if(args.length == 0) n = 40;
        else n = Integer.parseInt(args[0]);

        // 三角形用
        int remainder = n % 3;   // ステップ数を各辺に分割
        int half = ((n - remainder) / 3) / 2;
        int steps_side1 = (n - remainder) / 3 - half;
        int steps_side2 = ((n - remainder) / 3) * 2 - half;
        int steps_side3 = ((n - remainder) / 3) * 3 - half;
        hm[2].rt(360/3 - 90);

        // nステップの円
        for(int i = 0; i < n; i++) {
            hm[0].fd(10);
            hm[0].rt(360/n);

        // nステップ三角形
        //if(i < remainder; i++) {}  // 考えてはみたが、今回はステップ数割り切れないケースについては考えない
            if(i == steps_side1 || i == steps_side2 || i == steps_side3) {
                hm[2].rt(360/3);
            }
            hm[2].fd(10);

        // nステップ円と三角形の中間
            hm[1].moveTo((hm[0].getX() + hm[2].getX())/2 , (hm[0].getY() + hm[2].getY())/ 2);
        }
    }
}
