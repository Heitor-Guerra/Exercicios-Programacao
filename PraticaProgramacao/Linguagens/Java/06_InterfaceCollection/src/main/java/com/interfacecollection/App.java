package com.interfacecollection;

import java.util.*;

public class App {
    public static void main(String[] args) {

        // ------------------------- List ------------------------- //
        List<String> list = new ArrayList<String>();
        list.add("Heitor");
        list.add("Sophie");
        list.add("Arthur");
        list.add("Heitor"); // Allows Duplicates
        System.out.println(list);
        for (String i : list) { // For-Each loop
            System.out.println(i);
        }
        System.out.println("\n");
        System.out.println(list.getLast());

        System.out.println(list.get(2));
        System.out.println(list.indexOf("Sophie"));

        // -------------------------- Map -------------------------- //
        // Map<Integer, String> map = new HashMap<Integer, String>();
        // map.put(1, "One");
        // map.put(10, "Ten");
        // map.put(100, "Hundred");
        // map.put(1000, "Thousand");
        // map.put(1000000, "Million");
        //
        // for (Map.Entry<Integer, String> v : map.entrySet()) {
        // System.out.println(v.getKey() + ": " + v.getValue());
        // }
        //
        // TreeMap<Integer, String> sortedMap = new TreeMap<Integer, String>(map); //
        // Ascending Order
        // System.out.println(sortedMap);
        // for (Map.Entry<Integer, String> v : sortedMap.entrySet()) {
        // System.out.println(v.getKey() + ": " + v.getValue());
        // }

        // ------------------------- Queue ------------------------- //
        // Queue<String> q = new LinkedList<String>(); // First in, First Out
        // q.add("Banana");
        // q.add("Apple");
        // q.add("Grapes");
        // q.add("Strawberry");
        // System.out.println(q);
        // System.out.println("First: " + q.element()); // Return the head element of
        // the queue
        // System.out.println("Queue Size: " + q.size());
        // System.out.println("Queue include 'Apple': " + q.contains("Apple"));
        // q.remove("Apple");
        // System.out.println(q);
        // System.out.println("First: " + q.element()); // Return the head element of
        // the queue
        // System.out.println("Queue Size: " + q.size());
        // System.out.println("Queue include 'Apple': " + q.contains("Apple"));
        //
        // q.clear();

        // -------------------------- SET -------------------------- //
        // int[] count = { 21, 23, 43, 53, 22, 65, 43 }; // Don't allow Duplicates
        // Set<Integer> set = new HashSet<Integer>();
        // try {
        // for (int i = 0; i < 7; i++) {
        // set.add(count[i]);
        // }
        // System.out.println(set);
        // TreeSet<Integer> sortedSet = new TreeSet<Integer>(set);
        // System.out.println("Sorted:");
        // System.out.println(sortedSet);
        //
        // } catch (Exception e) {
        // System.out.println(e);
        // }

        // ------------------------ Dequeue ------------------------ //
        // Deque<String> q = new ArrayDeque<String>();
        // q.add("Banana");
        // q.addLast("Grapes");
        // q.addLast("Strawberry");
        // q.addFirst("Apple");
        // System.out.println(q);
        // System.out.println("First: " + q.getFirst());
        // System.out.println("Last: " + q.getLast());
        // System.out.println("Queue Size: " + q.size());
        // String a = q.remove();
        // System.out.println("Element removed: " + a);
        //
        // String b = q.removeLast();
        // System.out.println("Element removed: " + b);
        //
        // System.out.println(q);
        //
        // q.clear();

        // ------------------------- Array ------------------------- //
        // int[] count = { 21, 23, 43, 53, 22, 65, 43 };
        // int[] count2 = new int[count.length]; // Primitive way
        // for (int i = 0; i < count.length; i++) {
        // count2[i] = count[i];
        // }

    }
}
