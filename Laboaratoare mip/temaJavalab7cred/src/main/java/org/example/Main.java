package org.example;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;
import pachet.Masina;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ObjectMapper objectMapper = new ObjectMapper();
        File file = new File("masina.json");

        List<Masina> masini = new ArrayList<>();

        // Dacă fișierul există, citește datele existente
        if (file.exists()) {
            try {
                masini = objectMapper.readValue(file, new TypeReference<List<Masina>>() {});
            } catch (IOException e) {
                System.out.println("Eroare la citirea fișierului JSON: " + e.getMessage());
            }
        }

        while (true) {
            System.out.println("\nMeniu:");
            System.out.println("1. Introdu datele unei mașini");
            System.out.println("2. Citește toate masinile");
            System.out.println("3. Ieșire");
            System.out.print("Alege o opțiune: ");

            int optiune = scanner.nextInt();
            scanner.nextLine();

            switch (optiune) {
                case 1 -> {
                    System.out.print("Modelul mașinii: ");
                    String model = scanner.nextLine();

                    System.out.print("Anul mașinii: ");
                    int year = scanner.nextInt();
                    scanner.nextLine();

                    Masina masina = new Masina(model, year);
                    masini.add(masina);

                    try {
                        objectMapper.writeValue(file, masini);
                        System.out.println("Mașina a fost adăugată și salvată în fișierul JSON.");
                    } catch (IOException e) {
                        System.out.println("Eroare la salvarea fișierului JSON: " + e.getMessage());
                    }
                }
                case 2 -> {
                    // Citește și afișează toate mașinile din JSON
                    try {
                        List<Masina> masiniCitite = objectMapper.readValue(file, new TypeReference<List<Masina>>() {});
                        System.out.println("Datele citite din fișier:");
                        for (Masina m : masiniCitite) {
                            m.afiseazaDatele();
                        }
                    } catch (IOException e) {
                        System.out.println("Eroare la citirea fișierului JSON: " + e.getMessage());
                    }
                }
                case 3 -> {
                    System.out.println("ceau!");
                    System.exit(0);// ce face asta
                }
                default -> System.out.println("Optiune invalida. try iar again");
            }
        }
    }
}
