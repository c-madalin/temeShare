package org.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Scanner;

public class Main {
    // Configurația bazei de date
    private static final String URL = "jdbc:postgresql://localhost:5432/testdb";
    private static final String USER = "postgres";
    private static final String PASSWORD = "madalin250405";

    public static void main(String[] args) {
        // Încercare de conectare la baza de date
        Scanner scanner = new Scanner(System.in);
        try (Connection connection = DriverManager.getConnection(URL, USER, PASSWORD)) {
            System.out.println("Conexiunea la baza de date a fost realizată cu succes!");

            int opt = 0;
            while (opt != 4) {
                // Meniu
                System.out.println("\nAlege ce dorești să faci:");
                System.out.println("1. Adaugă utilizator");
                System.out.println("2. Șterge utilizator");
                System.out.println("3. Afișează utilizatori");
                System.out.println("4. Ieși");
                System.out.print("Opțiunea ta: ");
                opt = scanner.nextInt();
                scanner.nextLine(); // Consumă linia rămasă

                switch (opt) {
                    case 1:
                        // Adăugare utilizator
                        System.out.print("Introduceți numele: ");
                        String name = scanner.nextLine();
                        System.out.print("Introduceți email-ul: ");
                        String email = scanner.nextLine();

                        String insertQuery = "INSERT INTO users (name, email) VALUES (?, ?)";
                        try (PreparedStatement preparedStatement = connection.prepareStatement(insertQuery)) {
                            preparedStatement.setString(1, name);
                            preparedStatement.setString(2, email);
                            preparedStatement.executeUpdate();
                            System.out.println("Utilizator adăugat cu succes!");
                        }
                        break;

                    case 2:
                        // Ștergere utilizator
                        System.out.print("Introduceți ID-ul utilizatorului de șters: ");
                        int id = scanner.nextInt();

                        String deleteQuery = "DELETE FROM users WHERE id = ?";
                        try (PreparedStatement preparedStatement = connection.prepareStatement(deleteQuery)) {
                            preparedStatement.setInt(1, id);
                            int rowsAffected = preparedStatement.executeUpdate();
                            if (rowsAffected > 0) {
                                System.out.println("Utilizator șters cu succes!");
                            } else {
                                System.out.println("Nu există utilizator cu acest ID.");
                            }
                        }
                        break;

                    case 3:
                        // Afișare utilizatori
                        String selectQuery = "SELECT * FROM users";
                        try (PreparedStatement preparedStatement = connection.prepareStatement(selectQuery);
                             ResultSet resultSet = preparedStatement.executeQuery()) {

                            System.out.println("\nLista utilizatorilor:");
                            while (resultSet.next()) {
                                System.out.println("ID: " + resultSet.getInt("id") +
                                        ", Nume: " + resultSet.getString("name") +
                                        ", Email: " + resultSet.getString("email"));
                            }
                        }
                        break;

                    case 4:
                        // Ieșire
                        System.out.println("La revedere!");
                        break;

                    default:
                        System.out.println("Opțiune invalidă! Încercați din nou.");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            scanner.close();
        }
    }
}
