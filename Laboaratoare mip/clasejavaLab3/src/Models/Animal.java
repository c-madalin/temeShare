package Models;

public abstract class Animal {
    protected String name;
    protected int age;
    public abstract void makeSound();
    public void eat()
    {
        System.out.println("Eating...");
    }
    public void displayInfo()
    {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }




}
