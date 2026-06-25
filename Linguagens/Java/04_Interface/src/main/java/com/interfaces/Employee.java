package com.interfaces;

/**
 * Hello world!
 */
public class Employee implements Person {
  private String name;
  private String id;
  private int age;
  private int empId;
  private boolean employed;

  Employee(String name, String id, int age, int empId, boolean isEmployed) {
    this.name = name;
    this.age = age;
    this.empId = empId;
    this.employed = isEmployed;
    this.id = id;
  }

  public void print() {
    System.out.println("Name: " + name);
    System.out.println("Id: " + id);
    System.out.println("Age: " + age);
    System.out.println("Employee Id: " + empId);
    System.out.println("Is employed: " + employed);
  }

  public void employ() {
    employed = true;
  }

}
