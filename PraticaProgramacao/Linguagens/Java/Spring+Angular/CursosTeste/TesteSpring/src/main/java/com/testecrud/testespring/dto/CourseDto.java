package com.testecrud.testespring.dto;


public record CourseDto( String name,
                         String description,
                         String category) {
  public  boolean isNotValid() {
    return name.isEmpty() || category.isEmpty() || description.isEmpty();
  }
}