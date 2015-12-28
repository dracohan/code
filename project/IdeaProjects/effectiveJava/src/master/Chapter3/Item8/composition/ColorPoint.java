package master.Chapter3.Item8.composition;

// Adds a value component without violating the equals contract - Page 40
public class ColorPoint {
    private final master.Chapter4.Item14.Point point;
    private final master.Chapter3.Item8.Color color;

    public ColorPoint(int x, int y, master.Chapter3.Item8.Color color) {
        if (color == null)
            throw new NullPointerException();
        point = new master.Chapter4.Item14.Point(x, y);
        this.color = color;
    }

    /**
     * Returns the point-view of this color point.
     */
    public master.Chapter4.Item14.Point asPoint() {
        return point;
    }

    @Override public boolean equals(Object o) {
        if (!(o instanceof ColorPoint))
            return false;
        ColorPoint cp = (ColorPoint) o;
        return cp.point.equals(point) && cp.color.equals(color);
    }

    @Override public int hashCode() {
        return point.hashCode() * 33 + color.hashCode();
    }
}