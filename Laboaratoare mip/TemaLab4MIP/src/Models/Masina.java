package Models;

import Interfaces.iMasina;

public class Masina implements iMasina {
    public Masina(){
        System.out.println("Construiesc Masina");
    }
    public void Accelereaza(){
        System.out.println("Accelereaza Masina");
    }
    public void Semnalizeaza(){
        System.out.println("Semnalizeaza Masina");
    }
    public void Vireaza(){
        System.out.println("Vireaza Masina");
    }
    public void Franeaza(){
        System.out.println("Franeaza Masina");
    }
    public void Parcheaza(){
        System.out.println("Parcheaza Masina");
    }
    public void Porneste(){
        System.out.println("Porneste Masina");
    }
    public void Opreste(){
        System.out.println("Opreste Masina");
    }

}