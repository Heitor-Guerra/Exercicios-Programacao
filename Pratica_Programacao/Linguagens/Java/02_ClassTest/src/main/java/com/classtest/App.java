package com.classtest;

import com.otherpackage.*;
import other.*;
import com.classtest.utils.*;

public class App {
    public static void main(String[] args) {
        Student s = new Student(1, "Heitor", 1);
        s.grade = 8;
        s.print();
        Car car = new Car(2016, "AMG", "Mercedes");
        car.print();
        House house = new House("Av. Estudante Jose Julio de Souza");
        house.print();
        System.out.println("Hello World!");
    }
}
