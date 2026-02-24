package com.classtest;

public class Person {
  private String name;
  private int age;
  protected int card;

  public Person(String name, int age) {
    this.name = name;
    this.age = age;
  }

  public void print() {
    System.out.println("Name: " + name);
    System.out.println("Age: " + age);
  }

}
