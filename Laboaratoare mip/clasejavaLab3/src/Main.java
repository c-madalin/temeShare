import Models.Animal;
import Models.Dog;
import Models.Pisica;


public class Main {
    public static void main(String[] args)
    {
        Animal pisic=new Pisica("marius",13);
        Animal catel= new Dog("marta",9);

        pisic.makeSound();
        catel.makeSound();

        pisic.displayInfo();
        catel.displayInfo();
    }
}