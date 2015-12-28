package c09;

/**
 * Created by bwhan on 5/4/15.
 */
//: ThrowOut.java
public class ThrowOut {
    public static void
    main(String[] args) throws Throwable {
        try {
            throw new Throwable();
        } catch(Exception e) {
            System.out.println("Caught in main()");
        }
    }
} ///:~
