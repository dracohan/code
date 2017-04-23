package c10;

import java.util.Date;
import java.util.StringTokenizer;

/**
 * @project: LearningJava
 * @filename: StringFreeStyle.java
 * @version: 0.10
 * @author: Jimmy Han
 * @date: 21:00 2015/7/12
 * @comment: Test Purpose
 * @result:
 */
import static tool.util.prt;

public class StringFreeStyle {
    public static void main(String[] args) {
        String str = "abc";
        int lenght = str.length();
        boolean isEmpty = str.isEmpty();
        System.out.println(str);
        System.out.println(lenght);
        System.out.println(isEmpty);

        String str2 = str + "def";
        System.out.println(str2);

        String str3 = str2.concat("ggg");
        System.out.println(str3);

        String str4 = "adfasdfadfasdf" +
                "asdfasdfasdfasdfasdfasdf" +
                "asdfasdfasdfasdfasdfasdf";
        System.out.println(str4);

        char[] carr = new char[]{'a', 'b'};
        System.out.println(carr);
        String str5 = new String(carr);

        for(int i = 0; i < str5.length(); i++){
            System.out.println(str5.charAt(i));
        }

        String adf = String.valueOf(1);
        System.out.println(adf);

        String strdate = new Date().toString();
        System.out.println(strdate);
        System.out.println(new Date());

        String s1 = "fff";
        String s2 = "FFF";
        System.out.println(s1.equals(s2));
        System.out.println(s1.equalsIgnoreCase(s2));
        System.out.println(s1 == s2);
        System.out.println(s1.compareTo(s2) > 0);

        String url = new String("www.sina.com.cn");
        int i = url.indexOf('w');
        System.out.println(i);
        System.out.println(url.contains("com"));
        System.out.println(url.contains("cem"));

        System.out.println(url.lastIndexOf('w'));

        String ss = "abcdefghi";
        System.out.println(ss.trim());
        System.out.println(ss.substring(1,5));

        StringBuilder sb = new StringBuilder("hiiiiii");
        sb.append("ooooo");
        sb.append("hhhh");
        System.out.println(sb);
        String sfi = sb.toString();
        System.out.println(sfi);

        byte b = Byte.parseByte("16");

        //StringTokenizer
        String text= "4321, Java programming, 1000.00";
        StringTokenizer st = new StringTokenizer(text, ",");

        while(st.hasMoreTokens()){
            String word = st.nextToken();
            prt(word);
        }




    }
}
