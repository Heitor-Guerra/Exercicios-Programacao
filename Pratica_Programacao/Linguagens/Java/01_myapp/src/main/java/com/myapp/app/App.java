package com.myapp.app;

import java.util.Scanner;

public class App {
    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.println("Enter a number: ");
        int number = scan.nextInt();
        System.out.println("\nNumber enterd: " + number);

        if (number % 2 == 0) {
            System.out.println("The number " + number + " is Even");
        } else {
            System.out.println("The number " + number + " is Odd");
        }
    }
}
