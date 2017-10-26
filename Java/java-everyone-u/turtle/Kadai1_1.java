public class Kadai1_1 {
    public static void main(String[] args){
        TurtleFrame f = new TurtleFrame(600, 300);  // あとでコンストラクタに
        Turtle[] hm = new Turtle[2];
        for(int i = 0; i < 2; i++) {
            hm[i] = new Turtle(i * 400 + 25, 150, 0);
            f.add(hm[i]);
        }
        MannakaTurtle m = new MannakaTurtle(hm[0], hm[1]);
        f.add(m);

        int n;
        if(args.length == 0) n = 40;
        else n = Integer.parseInt(args[0]);

        // 三角形用
        int remainder = n % 3;   // ステップ数を各辺に分割
        int half = ((n - remainder) / 3) / 2;
        int steps_side1 = (n - remainder) / 3 - half;
        int steps_side2 = ((n - remainder) / 3) * 2 - half;
        int steps_side3 = ((n - remainder) / 3) * 3 - half;
        hm[1].rt(360/3 - 90);

        // nステップの円
        for(int i = 0; i < n; i++) {
            hm[0].fd(10);
            hm[0].rt(360/n);

        // nステップ三角形
        //if(i < remainder; i++) {}  // 書いてはみたが、今回割り切れないケースについては考えない
            if(i == steps_side1 || i == steps_side2 || i == steps_side3) {
                hm[1].rt(360/3);
            }
            hm[1].fd(10);

        // nステップ円と三角形の中間
            //hm[1].moveTo((hm[0].getX() + hm[2].getX())/2 , (hm[0].getY() + hm[2].getY())/ 2);
            m.moveToMannaka(hm[0], hm[1]);
        }
    }
}
