package master.Chapter3.Item8;// Trivial subclass of Point - doesn't add a value component - Page 39

import java.util.concurrent.atomic.*;

public class CounterPoint extends master.Chapter3.Item8.composition.Point {
    private static final AtomicInteger counter =
        new AtomicInteger();

    public CounterPoint(int x, int y) {
        super(x, y);
        counter.incrementAndGet();
    }
 
    public int numberCreated() { return counter.get(); }
}
