package com.test;

import java.util.*;
import java.io.*;

/**
 * Hello world!
 */
public class App {
    public static void main(String[] args) {
        // HashMap<String, String> map = new HashMap<String, String>();
        // map.put("Samsung", "Galaxy");
        // map.put("Apple", "iPhone");
        // map.put("Xiaomi", "RealMe");
        // map.put("Microsoft", "Phone");
        //
        // for (Map.Entry<String, String> v : map.entrySet()) {
        // System.out.println(v.getKey() + ": " + v.getValue());
        // }
        //
        // System.out.println(map);

        try {
            FileReader file = new FileReader(
                    "/home/Heitor-Guerra/Documents/Pratica_Programacao/Linguagens/Java/Test/src/main/java/com/test/entry.txt");
            BufferedReader buffer = new BufferedReader(file);
            System.out.println(buffer.readLine());
            buffer.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not Found: " + e);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
