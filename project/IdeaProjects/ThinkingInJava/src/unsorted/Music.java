package com.company;

/**
 * Created by bwhan on 2015/2/5.
 */


//: Music.java
// Inheritance & upcasting
class Note {
    private int value;
    private Note(int val) { value = val; }
    public static final Note
            middleC = new Note(0),
            cSharp = new Note(1),
            cFlat = new Note(2);
} // Etc.
class Instrument1 {
    public void play(Note n) {
        System.out.println("Instrument1.play()");
    }
}
// Wind1 objects are instruments
// because they have the same interface:
class Wind1 extends Instrument1 {
    // Redefine interface method:
    public void play(Note n) {
        System.out.println("Wind1.play()");
    }
}
public class Music {
    public static void tune(Instrument1 i) {
// ...
        i.play(Note.middleC);
    }
    public static void main(String[] args) {
        Wind1 flute = new Wind1();
        tune(flute); // Upcasting
    }
} ///:~