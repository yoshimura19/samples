import java.util.regex.Pattern;
import java.util.regex.Matcher;
public class SimpleRegexTest {
    public static void main(String[] args){
        String myText = "this is my 1st test string";
        String myRegex = "\\d+\\w+";    // これは\d+\w+を意味する
        Pattern p = Pattern.compile(myRegex);
        Matcher m = p.matcher(myText);
        if(m.find()){
            String matchedText = m.group(); // マッチした文字列
            int matchedFrom = m.start();    // マッチの開始位置
            int matchedTo = m.end();        // マッチの終了位置
            System.out.println("matched [" + matchedText + "] " + "from " +
                               matchedFrom + " to " + matchedTo + ".");
        } else {
            System.out.println("didn't match");
        }
        Pattern p2 = Pattern.compile("([-+]?\\d+(\\.\\d*)?) *([CF])$");
        Matcher m2 = p2.matcher("35.7 C");
        if(m2.find()){
            System.out.println(m2.group());
            System.out.println(m2.group(0));
            System.out.println(m2.group(1));
            System.out.println(m2.group(2));
            System.out.println(m2.group(3));
        }
        String text = "Java 1.5 is not Java 1.4. Java 1.8 is the latest.";
        Matcher m3 = Pattern.compile("\\bJava\\s*1\\.8\\b").matcher(text);
        System.out.println(m3.replaceAll("Java 8"));

        Pattern p4 = Pattern.compile("ATG([ATGC]{3})*?(TAA|TAG|TGA)");
        Matcher m4 = p4.matcher("ATCATATGTATTTCCTATCTTAATTT");
        if(m3.find()){
            System.out.println(m2.group());
            System.out.println(m2.group(0));
            System.out.println(m2.group(1));
            System.out.println(m2.group(2));
            System.out.println(m2.group(3));
        }
    }
}
