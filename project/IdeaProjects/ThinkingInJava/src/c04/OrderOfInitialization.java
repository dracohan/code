package c04;

/**
 * Created by bwhan on 4/2/15.
 */
//: OrderOfInitialization.java
// Demonstrates initialization order.
// When the constructor is called, to create a
// Tag object, you'll see a message:
class Tag {
    Tag(int marker) {
        System.out.println("Tag(" + marker + ")");
    }
}
class Card {



	static {
		System.out.println("static initilize statement");
	}
	Tag t3 = new Tag(3); // At end
	Card() {
		// Indicate we're in the constructor:
		System.out.println("Card()");
		t3 = new Tag(33); // Re-initialize t3
	}
	{
		System.out.println("initilize statement");
	}
	Tag t1 = new Tag(1); // Before constructor

    static Tag t2 = new Tag(2); // After constructor
    void f() {
        System.out.println("f()");
    }


}
public class OrderOfInitialization {
    public static void main(String[] args) {
        System.out.println("test start");
        Card t = new Card();
        t.f(); // Shows that construction is done
    }
} ///:~
