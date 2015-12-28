package master.Chapter3.Item8;// Attempting to add a value component to Point - Pages 37 - 38

public class ColorPoint extends master.Chapter4.Item14.Point {
    private final Color color;

    public ColorPoint(int x, int y, Color color) {
        super(x, y);
        this.color = color;
    }

    // Broken - violates symmetry!
    @Override public boolean equals(Object o) {
        if (!(o instanceof ColorPoint))
            return false;
        return super.equals(o) && ((ColorPoint) o).color == color;
    }

    // Broken - violates transitivity!
//  @Override public boolean equals(Object o) {
//      if (!(o instanceof Point))
//          return false;
//
//      // If o is a normal Point, do a color-blind comparison
//      if (!(o instanceof ColorPoint))
//          return o.equals(this);
//
//      // o is a ColorPoint; do a full comparison
//      return super.equals(o) && ((ColorPoint)o).color == color;
//  }

    public static void main(String[] args) {
        // First equals function violates symmetry
        master.Chapter4.Item14.Point p = new master.Chapter4.Item14.Point(1, 2);
        ColorPoint cp = new ColorPoint(1, 2, Color.RED);
        System.out.println(p.equals(cp) + " " + cp.equals(p));

        // Second equals function violates transitivity
        ColorPoint p1 = new ColorPoint(1, 2, Color.RED);
        master.Chapter4.Item14.Point p2 = new master.Chapter4.Item14.Point(1, 2);
        ColorPoint p3 = new ColorPoint(1, 2, Color.BLUE);
        System.out.printf("%s %s %s%n",
                          p1.equals(p2), p2.equals(p3), p1.equals(p3));
    }
}
