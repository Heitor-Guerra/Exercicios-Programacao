package com.otherpackage;

public class Car {
  private int year;
  private String model;
  private String manufacturer;

  public Car(int year, String model, String manufacterer) {
    this.year = year;
    this.model = model;
    this.manufacturer = manufacterer;
  }

  public void print() {
    System.out.println(manufacturer + ' ' + model + ' ' + year);
  }
}
