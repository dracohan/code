package com.JavaInNut;

/**
 * Created by Jimmy on 2015/3/19.
 */

/** Represents a Cartesian (x,y) point */
class Point {
    // The coordinates of the point
    public double x, y;
    public Point(double x, double y) {  // A constructor that
        this.x = x; this.y = y;  // initializes the fields
    }
    public double distanceFromOrigin() {  // A method that operates
        return Math.sqrt(x*x + y*y);  // on the x and y fields
    }
}

public class c2_72max {

    public static int max(int first, int... rest) {
        int max = first;
        for(int i : rest) { // legal because rest is actually an array
            if (i > max) max = i;
        }
        return max;
    }

    public static void main(String[] args) {
        Point p = new Point(2.0,3.0);
        // This is illegal; string literals cannot be broken across lines.
        String x = "This is a test of the" +
        "emergency broadcast system";;
        System.out.println("The distanceFromOrigin is: " + p.distanceFromOrigin());
        System.out.println("The max number is: " + max(9,16, 8, 4, 2, 1));
    }
}

