package Models;

public class Pisica extends Animal {
    public Pisica(String name ,int age) {
        this.age=age;
        this.name=name;
    }

    @Override
    public void makeSound() {
        System.out.println("Miau");
    }
}
