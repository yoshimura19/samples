public class MannakaTurtle extends Turtle{
    private Turtle t1;    // インスタンス変数として保持
    private Turtle t2;
    private Turtle Mannaka;
    public MannakaTurtle(Turtle m1, Turtle m2){
        this.t1 = m1;     // 問題の指示に従っている(つもりだが)冗長
        this.t2 = m2;
        this.Mannaka = new Turtle((t1.getX() + t2.getX()) / 2, (t1.getY() + t2.getY()) / 2, 0);
    }
    public void moveToMannaka(Turtle t1, Turtle t2){
        this.Mannaka.moveTo((t1.getX() + t2.getX()) / 2, (t1.getY() + t2.getY()) / 2, 0);
    }
}
