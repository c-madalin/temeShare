public class Main {
    public static void main(String[] args) {
        int varsta = 30;
        double salariu = 3500.75;
        char initiala = 'A';
        boolean angajat = true;
        String nume = "Maria";

        System.out.println("Nume: " + nume);
        System.out.println("Varsta: " + varsta);
        System.out.println("Salariu: " + salariu);
        System.out.println("Initiala: " + initiala);
        System.out.println("Este angajat: " + angajat);

        int numar1 = 10;
        int numar2 = 20;
        int suma = numar1 + numar2;
        int diferenta = numar2 - numar1;
        int produs = numar1 * numar2;
        double impartire = (double) numar2 / numar1;

        System.out.println("Suma dintre " + numar1 + " si " + numar2 + " este: " + suma);
        System.out.println("Diferenta dintre " + numar2 + " si " + numar1 + " este: " + diferenta);
        System.out.println("Produsul dintre " + numar1 + " si " + numar2 + " este: " + produs);
        System.out.println("Impartirea dintre " + numar2 + " si " + numar1 + " este: " + impartire);

        System.out.println("int + double " + ( numar1+impartire));
        System.out.println(" double+ int  " + ( impartire+numar1));
        System.out.println(nume+initiala);
        System.out.println(nume+numar2);

    }
}