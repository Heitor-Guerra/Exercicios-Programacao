package com.inheritancetest;

public class PC extends Computador {
  private boolean limited;

  public PC(int tension, String manufacturer, String model, String processor, String gpu, boolean limit) {
    super(tension, manufacturer, model, processor, gpu);
    limited = limit;
  }

  public void print() { // Polymorphism
    super.print();
    System.out.println("Limited: " + limited);
  }
}
