// Definirea clasei Rectangle în afara clasei Main
class Rectangle {
    private double width;
    private double height;

    // Constructor
    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    // Metodă pentru calcularea ariei
    public double area() {
        return width * height;
    }

    // Metodă pentru calcularea perimetrului
    public double perimeter() {
        return 2 * (width + height);
    }
}

// Clasa principală
public class Main {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle(5, 10); // Crearea unui obiect Rectangle
        System.out.println("Area: " + rect.area());
        System.out.println("Perimeter: " + rect.perimeter());
    }
}
