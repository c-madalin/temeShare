import orderpack.Order;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static boolean StopComand(Scanner sc) {
        System.out.print("Dorești să continui? (y/n): ");
        String s = sc.nextLine();
        return s.equalsIgnoreCase("n");
    }

    public static Order initialize(int order_id, Scanner scanner) {
        System.out.println("Cine dorește să plaseze comanda?");
        String numeClient = scanner.nextLine();
        return new Order("Comanda" + order_id, order_id, numeClient);
    }

    public static void Meniu(Order order, Scanner scanner) {
        while (true) {
            System.out.println("\nCe dorești să faci?");
            System.out.println("1. Adăugare produs");
            System.out.println("2. Eliminare produs");
            System.out.println("3. Căutare comanda");
            System.out.println("4. Afisare Produse");
            System.out.println("5. Ieșire");

            int option;
            try {
                option = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Opțiune invalidă! Te rog să introduci un număr.");
                continue;
            }

            switch (option) {
                case 1:
                    System.out.println("Adăugare produs...");
                    order.Adauga_Produs(scanner);
                    break;
                case 2:
                    System.out.println("Eliminare produs...");
                    System.out.println("introdu nume");
                    String nume=scanner.nextLine();
                    order.Elimina_Produs(nume);
                    break;
                case 3:
                    System.out.println("Căutare comanda...");
                    // Implementare logică pentru căutare comandă
                    break;
                case 4:
                    System.out.println("Afisare lista de produse");
                    order.Show_List();
                    break;
                case 5:
                    System.out.println("Ieșire din meniu.");
                    return;
                default:
                    System.out.println("Opțiune invalidă.");
            }
        }
    }

    public static void main(String[] args) {
        int order_id = 1;
        List<Order> orders = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            // Creează o nouă comandă
            Order order = initialize(order_id++, scanner);
            Meniu(order, scanner); // Adaugă produse, elimină produse, afișează produse

            orders.add(order); // Adaugă comanda în lista de comenzi

            if (StopComand(scanner)) {
                break;
            }
        }

        // Afișare detalii comenzi după terminarea adăugării
        System.out.println("\nDetalii comenzi:");
        for (Order order : orders) {
            System.out.println("Nume comandă: " + order.getNume_comanda());
            System.out.println("ID comandă: " + order.getId_order());
            System.out.println("Client: " + order.getNume_client());
            System.out.println("Produse:");
            order.Show_List();
            System.out.println("///////////////////////////////////");
        }

        scanner.close();
    }
}
