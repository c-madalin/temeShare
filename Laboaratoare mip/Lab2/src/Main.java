import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Vector;

//Enunț: Scrie un program care citește un număr întreg de la utilizator și verifică dacă acesta este un număr prim.
//Enunț: Scrie un program care citește un număr întreg n de la utilizator și calculează factorialul lui n (n!).
//Enunț: Scrie un program care citește o propoziție de la utilizator și afișează propoziția inversată.
//Enunț: Scrie un program care citește n numere întregi de la utilizator, le stochează într-un vector și afișează cel mai mare număr din acel vector.
//Enunț: Scrie un program care citește un cuvânt de la utilizator și verifică dacă acesta este palindrom (se citește la fel și de la stânga la dreapta, și de la dreapta la stânga).

public class Main
{
    public static void este_prim()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("introdu un numar ");
        System.out.println("\n");
        int n = sc.nextInt();

        if(n==1)
            System.out.println("nu e prim");

        if(n==2)
            System.out.println("e prim");
        int ok=0;
        for(int i=2;i<n && ok==0;i++)
        {
            if(n%i==0)
            {
                System.out.println("nu este prim");
                ok=1;
            }
        }
        if(ok==0)
            System.out.println("este prim");
        sc.close();
    }
    public static int factorial()
    {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int aux=1;
        for(int i=1;i<=n;i++)
        {
            aux=aux*i;
        }
        sc.close();
        return aux;
    }

    public static void invers()
    {
        System.out.println("baga propozitia");
        Scanner sc = new Scanner(System.in);
        String propozitie=sc.nextLine();
        String [] vect_cuv=propozitie.split(" ");
        for(int i=vect_cuv.length-1;i>=0;i--)
        {
            System.out.print(vect_cuv[i]+" ");
        }

        sc.close();
    }

    public static void cel_mare()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("introdu numarul de numere");
        int n=sc.nextInt();
        int []numere=new int[n];
        int max=0;
        for(int i=0;i<n;i++)
        {
            numere[i]=sc.nextInt();
            if(numere[i]>max) {
                max = numere[i];
            }
        }
        System.out.println("cel mai mare numar este" + max);
        sc.close();

    }
    public static boolean palindrom()
    {
        Scanner sc = new Scanner(System.in);
        String sir=sc.nextLine();
        sc.close();
        for(int i=0;i<sir.length();i++)
        {
            if(sir.charAt(i)!=sir.charAt(sir.length()-1-i))
                return false;
        }

        return true;
    }

    public static void main(String[] args)
    {
      // este_prim();
        //System.out.println(factorial());
    //invers();
       // cel_mare();
       if( palindrom())
           System.out.println("palindrom");
       else
           System.out.println("not palindrom");
    }
}

