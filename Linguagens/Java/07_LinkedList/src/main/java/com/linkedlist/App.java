package com.linkedlist;

public class App {
  public static void main(String[] args) {
    LinkedList list = new LinkedList(5);
    list.add(2);
    list.add(8);
    list.add(100);
    list.add(3);
    list.add(78);
    list.add(5);
    list.display();
    System.out.println(list.get(3));
    System.out.println();
    list.remove(2);
    list.display();
  }
}
