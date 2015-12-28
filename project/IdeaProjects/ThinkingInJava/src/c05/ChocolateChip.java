package c05;

import c05.desert.Cookie;

/**
 * Created by root on 4/10/15.
 */
public class ChocolateChip extends Cookie {
    public ChocolateChip() {
        System.out.println(
                "ChocolateChip constructor");
    }
    public static void main(String[] args) {
        ChocolateChip x = new ChocolateChip();
        x.foo(); // Can't access foo
    }
} ///:~
