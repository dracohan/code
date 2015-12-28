package c07;

/**
 * Created by root on 4/17/15.
 */
//: IInterface.java
// Static inner classes inside interfaces
interface IInterface {
    static class Inner {
        int i, j, k;
        public Inner() {}
        void f() {}
    }
} ///:~
