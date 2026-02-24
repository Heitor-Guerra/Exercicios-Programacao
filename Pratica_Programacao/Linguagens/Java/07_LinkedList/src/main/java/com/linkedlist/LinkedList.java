package com.linkedlist;

/**
 * Hello world!
 */
class Node {
    private int data;
    private Node next;

    Node(int v) {
        data = v;
        next = null;
    }

    void print() {
        System.out.print(data);
    }

    void setNext(Node n) {
        next = n;
    }

    Node getNext() {
        return next;
    }

    int getData() {
        return data;
    }
}

public class LinkedList {
    private Node head;

    public LinkedList(int v) {
        head = new Node(v);
    }

    public void add(int v) {
        Node n = head;
        while (n.getNext() != null) {
            n = n.getNext();
        }
        n.setNext(new Node(v));
    }

    public int get() { // get first
        return head.getData();
    }

    public int get(int index) {
        Node n = head;
        for (int i = 0; i < index && n.getNext() != null; i++) {
            n = n.getNext();
        }
        return n.getData();
    }

    public void remove() { // remove last
        Node n = head;
        while (n.getNext().getNext() != null) {
            n = n.getNext();
        }
        n.setNext(null);
    }

    public void remove(int index) {
        if (index == 0) {
            Node next = head.getNext();
            head.setNext(null);
            head = next;
            return;
        }
        Node n = head;
        for (int i = 0; i < index - 1 && n.getNext().getNext() != null; i++) {
            n = n.getNext();
        }
        Node removed = n.getNext();
        Node next = removed.getNext();
        removed.setNext(null);
        n.setNext(next);
    }

    public void display() {
        Node n = head;
        while (n.getNext() != null) {
            n.print();
            System.out.print(" -> ");
            n = n.getNext();
        }
        n.print();
        System.out.println();
    }
}
