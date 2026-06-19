package com.testecrud.testespring;

import com.testecrud.testespring.model.Course;
import com.testecrud.testespring.repository.CourseRepository;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

@SpringBootApplication
public class TesteSpringApplication {

  public static void main(String[] args) {
    SpringApplication.run(TesteSpringApplication.class, args);
  }

  @Bean
  CommandLineRunner initDatabase(CourseRepository courseRepository) {
    return args -> {
      courseRepository.deleteAll();

      Course course1 = new Course();
      course1.setName("HTML");
      course1.setCategory("Frontend");
      course1.setDescription("Curso de HTML");

      Course course2 = new Course();
      course2.setName("CSS");
      course2.setCategory("Frontend");
      course2.setDescription("Curso de CSS");

      Course course3 = new Course();
      course3.setName("Spring");
      course3.setCategory("Backend");
      course3.setDescription("Curso de Spring");

      Course course4 = new Course();
      course4.setName("Java");
      course4.setCategory("Software");
      course4.setDescription("Curso de Java");

      Course course5 = new Course();
      course5.setName("Linux");
      course5.setCategory("Kernel");
      course5.setDescription("Curso de Linux");

      courseRepository.save(course1);
      courseRepository.save(course2);
      courseRepository.save(course3);
      courseRepository.save(course4);
      courseRepository.save(course5);

    };
  }

}
