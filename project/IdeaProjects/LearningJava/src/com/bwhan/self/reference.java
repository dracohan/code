package self;

/**
 * Created by Jimmy on 2015/5/19.
 */
public class reference {
    static String s = "adb" + "def";
    static Character c = 'a';
    public static void main(String[] args){
        Byte b = (byte)257;
        System.out.println("character: " + c);
        System.out.println("byte: " + b);
        System.out.println("String: " + s);
        stringseter("ggg", 'd');
        System.out.println("String: " + s);
        System.out.println("character: " + c);
    }

    private static void stringseter(String str, Character c){
        reference.s = str;
        reference.c = c;
    }
}
