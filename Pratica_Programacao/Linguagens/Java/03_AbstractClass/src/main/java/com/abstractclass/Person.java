package com.abstractclass;

abstract class Person {
  private String name;
  private String id;
  private char sex;
  private int age;

  Person(String name, String id, char sex, int age) {
    this.name = name;
    this.id = id;
    this.sex = sex;
    this.age = age;
  }

  void changeName(String newName) {
    name = newName;
  }

  String getName() {
    return name;
  }

  int getAge() {
    return age;
  }

  boolean verifyMaiority() {
    return age >= 18;
  }

  abstract void print();

}
