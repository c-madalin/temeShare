import java.util.HashSet;
import java.util.Set;

public class Main {
    public static int suma_cifrelor(int numar)
    {
        int aux=0;
        while(numar>0)
        {
            aux=aux+numar%10;
            numar=numar/10;
        }
        return aux;
    }
    public static int lcm(int n, int m)
    {
        while(n != m)
            if(n > m)
                n -= m;
            else
                m -= n;

        return n;
    }
    public static void duplicate(int[] vector)
    {
        int[] aux;
        for(int i=0;i<vector.length;i++)
        {

        }
    }
    public static void main(String[] args)
    {
        int  numar=23454;
        //System.out.println(suma_cifrelor(numar));
        // System.out.println(lcm(43,21));

    }
}