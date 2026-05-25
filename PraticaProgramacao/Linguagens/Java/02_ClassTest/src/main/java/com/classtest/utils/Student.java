package com.classtest.utils;

import com.classtest.Person;

public class Student extends Person {
  private int mat;
  public int grade;

  public Student(int mat, String name, int age) {
    super(name, age);
    super.card = 0;
    this.mat = mat;
    this.grade = 0;
  }

  public void print() {
    super.print();
    System.out.println("Id: " + mat);
    System.out.println("Grade: " + grade);
  }

}
