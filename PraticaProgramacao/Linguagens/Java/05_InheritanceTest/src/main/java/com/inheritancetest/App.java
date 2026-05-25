package com.inheritancetest;

/**
 * Hello world!
 */
public class App {
    public static void main(String[] args) {
        Dispositivo d1 = new Computador(127, "Asus", "Rog", "Ryzen 7 7735HS", "Radeon 680M");
        Dispositivo d2 = new Celular(12, "Samsung", "S25", "Snapdragon");
        d1.print();
        d2.print();
        // d1.setProcessor("Intel i7"); // Computador method (not acessible through
        // Dispositivo variable)

        Computador c1 = new Computador(127, "Asus", "Rog", "Ryzen 7 7735HS", "Radeon 680M");
        c1.setGraphicsCard("Radeon 780M");

        PC p1 = new PC(127, "Asus", "Rog", "Ryzen 7 7735HS", "Radeon 680M", true);
        p1.setModel("TUF"); // Dispositivo method
        p1.setGraphicsCard("4060 Ti"); // Computador method
        p1.print(); // PC method (Polymorphism)
        c1.print(); // Computador method
        d1.print(); // Computador method (ABSTRACT)

        System.out.println("Is same: " + d1.compare(d2));

    }
}
