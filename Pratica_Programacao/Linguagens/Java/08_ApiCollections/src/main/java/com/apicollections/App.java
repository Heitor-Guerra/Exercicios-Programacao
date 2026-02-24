package com.apicollections;

import java.util.*;

/**
 * Hello world!
 */
public class App {
    public static void main(String[] args) {
        // ------------------------------ Shuffling ------------------------------ //
        // List<Integer> list = new ArrayList<Integer>();
        // list.add(1);
        // list.add(2);
        // list.add(3);
        // list.add(4);
        // list.add(5);
        // list.add(6);
        //
        // System.out.println(list);
        //
        // Collections.shuffle(list);
        //
        // System.out.println(list);

        // ---------------------------- Binary Search ---------------------------- //
        // List<Integer> list = new ArrayList<Integer>();
        // list.add(1);
        // list.add(2);
        // list.add(2);
        // list.add(6);
        // list.add(8);
        // list.add(10);
        //
        // System.out.println(list);
        // int a = Collections.binarySearch(list, 6);
        // if (a >= 0) {
        // System.out.println("Found at " + a);
        // } else {
        // System.out.println("Not found");
        // }

        // ------------------------------- Sorting ------------------------------- //
        List<Integer> list = new ArrayList<Integer>();
        list.add(12);
        list.add(56);
        list.add(5);
        list.add(7564);
        list.add(8);
        list.add(10);

        System.out.println(list);
        Collections.sort(list);
        System.out.println(list);
    }

}
