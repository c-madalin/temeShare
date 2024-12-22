package orderpack;
import interfata.iOrder;
import orderpack.Produs;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Order {
    private String nume_comanda;
    private int id_order;
    private boolean delivered;
    private String nume_client;
    private String file="";
    private int pret_total=0;
    private List<Produs> produse = new ArrayList<Produs>();


    public Order() {
        System.out.println("a fost comanda creata");
    }
    public Order(String nume_comanda, int id_order, String nume_client)
    {
        this.nume_comanda = nume_comanda;
        this.id_order = id_order;
        this.nume_client = nume_client;
    }
    public String getNume_comanda() {
        return nume_comanda;
    }
    public int getId_order() {
        return id_order;
    }
    public boolean isDelivered() {
        return delivered;
    }
    public String getNume_client() {
        return nume_client;
    }
    public List<Produs> getProduse() {
        return produse;
    }
    public void Adauga_Produs(Scanner sc)
    {
        System.out.println("introdu numele produsului");
        String name=sc.nextLine();
        System.out.println("introdu pretul produsului");
        int pret=sc.nextInt();
        System.out.println("introdu cantitatea produsului");
        int cantitate=sc.nextInt();
        Produs nouProdus=new Produs(name,pret,cantitate);
        produse.add(nouProdus);
    }
    public void Elimina_Produs(String nume)
    {
        for(int i=0;i<produse.size();i++)
        {
            if(produse.get(i).getDenumire().equals(nume))
            {
                produse.remove(produse.get(i));
            }
        }

    }
    public void Actualizare_Stare()
    {

    }
    public void Show_List()
    {
        int i=0;
        for(Produs produs:produse)
        {
            i++;

            System.out.print(i+" ."+ produs.getDenumire()+" pret  ");
            System.out.print(produs.getPret()+" cantitate ");
            System.out.print(produs.getCantitate()+" ");
            System.out.println(" ");

        }
    }
    public void Sterge_Comanda()
    {

    }
    public void Afisare_Pret()
    {

    }
    public void Export_Order()
    {

    }
    public void FInd_order()
    {

    }

}
