package store;
import java.util.List;
import interfaces.  Istore;
import java.util.Scanner;
import java.util.ArrayList;

public class Store implements Istore
{

    public Store(){
        m_produse = new ArrayList<>();
    }
    public void store(){
        for(int i=0;i<m_produse.size();i++)
        {
            System.out.println(m_produse.get(i));
        }
    }
    public void Cumparam(){
        System.out.println("Cumparam cate produse");
        Scanner scanner=new Scanner(System.in);
        int n= scanner.nextInt();
        for(int i=0;i<n;i++)
        {
            m_produse.add(scanner.next());
        }

        scanner.close();
    }

    public void Deschidem(){}
    private List<String> m_produse;


}
