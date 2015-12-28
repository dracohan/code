package c07;

/**
 * Created by root on 4/17/15.
 */
//: TestBed.java
// Putting test code in a static inner class
class TestBed {
    TestBed() {}
    void f() { System.out.println("f()"); }
    public static class Tester {
        public static void main(String[] args) {
            TestBed t = new TestBed();
            t.f();
        }
    }
} ///:~
