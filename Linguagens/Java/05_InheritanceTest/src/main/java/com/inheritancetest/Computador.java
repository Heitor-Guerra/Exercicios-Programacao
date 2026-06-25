package com.inheritancetest;

/**
 * Hello world!
 */
public class Computador extends Dispositivo {
  private String processor;
  private String graphicsCard;

  public Computador(int tension, String manufacturer, String model, String processor, String gpu) {
    super(tension, manufacturer, model);
    this.processor = processor;
    graphicsCard = gpu;
  }

  public void setProcessor(String t) {
    processor = t;
  }

  public void setGraphicsCard(String t) {
    graphicsCard = t;
  }

  public String getProcessor() {
    return processor;
  }

  public String getGraphicsCard() {
    return graphicsCard;
  }

  public void print() {
    System.out.println(getModel() + " " + getManufacturer() + " (" + processor + '/' + graphicsCard + ")");
  }

  public boolean compare(Dispositivo d2) {
    return getModel() == d2.getModel() && getManufacturer() == d2.getManufacturer();
  }
}
