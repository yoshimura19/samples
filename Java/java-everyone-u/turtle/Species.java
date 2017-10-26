public class Species {
    private int name;
    private int age = 0;
    private int birth;
    private int ancestor;
    private int alive = 1;
    private int count_p = 0;   // 確率p生存の回数
    private int count_q = 0;   // 確率q分岐の回数(正確には1-p-q)
    public Species(int name, int year, int ancestor){  // コンストラクタ
        this.name = name;
        this.birth = year;
        this.ancestor = ancestor;
    }
    public void gain_age(){    // 年経過
        age += 1;
    }
    public void end_alive(){
        alive = 0;
    }
    public void gain_p(){
        count_p += 1;
    }
    public void gain_q(){
        count_q += 1;
    }
    public int get_name(){
        return(name);
    }
    public int get_age(){
        return(age);
    }
    public int get_alive(){
        return(alive);
    }
    public int get_p(){
        return(count_p);
    }
    public int get_q(){
        return(count_q);
    }
    public void outSpecies(){   // 出力用
        System.out.print("name:" + name + " ");
        System.out.print("age:" + age + " ");
        System.out.print("birth:" + birth + " death:" + (age + birth) + " ");
        System.out.println("ancestor:" + ancestor);
    }
}
