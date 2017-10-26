public class Kadai2 {
    public static void main(String[] args){
        Species[] s = new Species[1000000];
        s[0] = new Species(0, 0, 0);  // 始まりの種(name, birth, ancestor)

        int end_year = 10;  // 世界の終わり
        double p = 0.4, q = 0.3;      // 分岐、絶滅、生存(1-p+q)
        int count_species = 1;        // 総誕生種の数(最初は1種)
        // int sum_count_species = 1;

        for(int year = 0; year < end_year; year++) {
            int number_newborn = 0;
            int end_species = 0;     // 絶滅数
            for(int j = 0; j < count_species; j++) {
                if(s[j].get_alive() == 0) {
                    end_species += 1;
                    continue;  // 種jは生きていない
                }
                double random = Math.random();   // 0以上1未満の乱数
                // System.out.println(random);
                if(p + q <= random){  // 生存
                    s[j].gain_p();
                    System.out.println("s[" + j + "]:生存");
                    s[j].gain_age();
                } else if (random < p){ // 分岐(2種誕生)
                    s[j].gain_q();
                    System.out.println("s[" + j + "]:分岐");
                    s[j].end_alive();
                    for(int i = 0; i < 2; i++){ // 2種作る
                        number_newborn += 1;
                        int new_name = count_species + number_newborn - 1;
                        s[new_name] = new Species(new_name, year + 1, j);
                    }
                } else {   // (p <= random || random < p + q) 絶滅
                    System.out.println("s[" + j + "]絶滅");
                    s[j].end_alive();
                    end_species += 1;
                }
            }
            count_species += number_newborn;
            System.out.println("現在" + year + "年全" + count_species + "種");
            System.out.println("生存" + (count_species - end_species) + "種");
            if(end_species == count_species) break;
            for(int i = 0; i < count_species; i++) {
                s[i].outSpecies();
            }
            System.out.println("");
        }

        System.out.println("生存個体について、pと(1-p-q)を集計、生存個体の名前を出力");
        int []live_species = new int[100];
        int index = 0;
        for(int i = 0; i < count_species; i++){
            if(s[i].get_alive() == 1){
                live_species[index] = s[i].get_name();
                index++;
            }
        }

        int count_p = 0, count_q = 0;
        for(int i = 0; i < index; i++){
            System.out.print(live_species[i] + " ");
            System.out.println("");
            count_p += s[i].get_p();
            count_q += s[i].get_q();
            // for(int j = 0;; j++){     // 無限ループ
            //     count_p += s.[live_species[j].get_name()].get_p();
            //     count_q += s.[live_species[j].get_name()].get_q();
            // }
        }

        System.out.println("最後に生存していた個体についての分岐数pと生存回数");
        System.out.println("分岐数:" + count_p);
        System.out.println("生存回数:" + count_q);
    }
}
