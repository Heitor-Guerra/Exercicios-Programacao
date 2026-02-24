package com.abstractclass;

class Employee extends Person {
  private int empId;
  private String position;
  private float salary;
  private int workload;

  Employee(String name, String id, char sex, int age, int empId, String position, float salary, int workload) {
    super(name, id, sex, age);
    this.empId = empId;
    this.position = position;
    this.salary = salary;
    this.workload = workload;
  }

  void print() {
    System.out.println("Name " + getName());
    System.out.println("Age " + getAge());
    System.out.println("Employee Id: " + empId);
    System.out.println("Position: " + position);
    System.out.println("Salary: R$" + salary);
    System.out.println("Workload: " + workload);
  }
}
