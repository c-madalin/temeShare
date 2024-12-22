package Models;

public class Dog extends Animal {
    public Dog(String name, int age) {
        //super(name,age);
        this.name = name;
        this.age = age;
    }
    @Override
    public void makeSound() {
        System.out.println("ham ham");
    }

}
