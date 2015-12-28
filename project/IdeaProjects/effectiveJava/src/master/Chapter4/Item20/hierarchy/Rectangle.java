package master.Chapter4.Item20.hierarchy;

class Rectangle extends master.Chapter4.Item20.tagged.Figure {
    final double length;
    final double width;

    Rectangle(double length, double width) {
        this.length = length;
        this.width  = width;
    }
    double area() { return length * width; }
}
