package c08;

/**
 * Created by bwhan on 4/28/15.
 */
//: Compare.java
// Interface for sorting callback:

interface Compare {
    boolean lessThan(Object lhs, Object rhs);
    boolean lessThanOrEqual(Object lhs, Object rhs);
} ///:~
