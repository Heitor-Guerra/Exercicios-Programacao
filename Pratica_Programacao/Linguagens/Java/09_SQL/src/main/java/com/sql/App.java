package com.sql;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * Hello world!
 */
public class App {
    public static void main(String[] args) throws SQLException {
        String uname = "Heitor-Guerra";
        String query1 = "INSERT INTO EngineeringStudents VALUES (DEFAULT, 'CT', 'Arthur', 2018), (DEFAULT, 'CT', 'Igor', 2025)";
        String query2 = "SELECT * FROM EngineeringStudents WHERE department LIKE 'CT'";
        String url = "jdbc:mysql://localhost:3306/university";

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        try {
            Connection con = DriverManager.getConnection(url, uname, null);
            Statement stat = con.createStatement();
            stat.executeUpdate(query1); // Update Database
            ResultSet result = stat.executeQuery(query2); // Select from database
            while (result.next()) {
                String UniversityData = "";
                for (int i = 1; i <= 4; i++) {
                    UniversityData += result.getString(i) + ":";
                }
                System.out.println(UniversityData);
            }
            con.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
}
