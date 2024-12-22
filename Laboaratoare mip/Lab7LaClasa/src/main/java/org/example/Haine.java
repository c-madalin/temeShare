package org.example;

public class Haine implements Product {
    private String name;
    private String material;
    private int pret;

    public Haine()
    {

    }
    public Haine(String name, String material, int pret)
    {
        this.name = name;
        this.material = material;
        this.pret = pret;
    }

    @Override
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    @Override
    public int getPrice() {
        return pret;
    }
    @Override
    public void setPrice(int pret) {
        this.pret = pret;
    }
}
