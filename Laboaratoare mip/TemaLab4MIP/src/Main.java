import Interfaces.iMasina;
import Models.Masina;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        iMasina masina = new Masina();
        masina.Accelereaza();
        masina.Opreste();
    }
}