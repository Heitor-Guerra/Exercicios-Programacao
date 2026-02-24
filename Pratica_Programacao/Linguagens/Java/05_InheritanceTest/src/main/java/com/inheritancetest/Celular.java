package com.inheritancetest;

/**
 * Hello world!
 */
public class Celular extends Dispositivo {
  private String chip;

  public Celular(int tension, String manufacturer, String model, String chip) {
    super(tension, manufacturer, model);
    this.chip = chip;
  }

  public void setChip(String t) {
    chip = t;
  }

  public String getChip() {
    return chip;
  }

  public void print() {
    System.out.println(getModel() + " " + getManufacturer() + " (" + chip + ")");
  }

  public boolean compare(Dispositivo d2) {
    return getModel() == d2.getModel() && getManufacturer() == d2.getManufacturer();
  }
}
