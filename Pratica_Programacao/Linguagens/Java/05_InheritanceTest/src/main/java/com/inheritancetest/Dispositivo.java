package com.inheritancetest;

/**
 * Hello world!
 */
abstract class Dispositivo {
  private int tension;
  private String manufacturer;
  private String model;

  Dispositivo(int tension, String manufacturer, String model) {
    this.manufacturer = manufacturer;
    this.model = model;
    this.tension = tension;
  }

  public void setTension(int t) {
    tension = t;
  }

  public void setManufacturer(String t) {
    manufacturer = t;
  }

  public void setModel(String t) {
    model = t;
  }

  public int getTension() {
    return tension;
  }

  public String getManufacturer() {
    return manufacturer;
  }

  public String getModel() {
    return model;
  }

  abstract void print();

  abstract boolean compare(Dispositivo d2);
}
