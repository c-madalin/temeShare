package interfata;
import orderpack.Produs;
import java.util.List;

public interface iOrder {
    default void Order() {

    }

    void Order(String nume_comanda, int id_order, String nume_client);
    void addProdus(Produs produs);
    void eliminaProdus(String denumireProdus);
    void setDelivered(boolean delivered);
    boolean isDelivered();
    void afisarePretTotal();
    void showOrderDetails();
}
