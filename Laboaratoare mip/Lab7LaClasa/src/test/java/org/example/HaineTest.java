package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class HaineTest {

    @Test
    void testGetName() {
        Haine h = new Haine("bluza","kasmir",15);
        assertEquals("bluza",h.getName());
    }

    @Test
    void testSetName() {
        Haine h = new Haine("bluza","kasmir",15);
        h.setName("hanorac");
        assertEquals("hanorac",h.getName());
    }

    @Test
    void testGetPrice() {
        Haine h = new Haine("bluza","kasmir",15);
        assertEquals(15,h.getPrice());
    }

    @Test
    void testSetPrice() {
        Haine h = new Haine("bluza","kasmir",15);
        h.setPrice(20);
        assertEquals(20,h.getPrice());

    }
}