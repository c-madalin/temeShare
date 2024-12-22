package org.example;

import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        // Create a JFrame
        JFrame frame = new JFrame("Draw Circle Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400); // Set frame size

        // Add a custom panel that draws a circle
        frame.add(new CirclePanel());

        // Make the frame visible
        frame.setVisible(true);
    }
}

// Custom panel to draw a circle
class CirclePanel extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g); // Call the superclass's method to ensure proper painting

        // Cast Graphics to Graphics2D for more advanced options
        Graphics2D g2d = (Graphics2D) g;

        // Set the color for the circle
        g2d.setColor(Color.BLUE);


        g2d.drawLine(0, 0, getWidth(), getHeight());

        g2d.setStroke(new BasicStroke(20));


        // Draw the circle (x, y, width, height)
        g2d.drawOval(100, 100, 200, 200); // Outlined circle
        // g2d.fillOval(100, 100, 200, 200); // Uncomment to draw a filled circle
    }
}
