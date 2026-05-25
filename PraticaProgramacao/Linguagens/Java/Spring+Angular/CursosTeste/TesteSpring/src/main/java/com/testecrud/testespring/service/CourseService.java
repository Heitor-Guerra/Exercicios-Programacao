package com.testecrud.testespring.service;

import com.testecrud.testespring.dto.CourseDto;
import com.testecrud.testespring.model.Course;
import com.testecrud.testespring.repository.CourseRepository;
import org.jspecify.annotations.NonNull;
import org.springframework.beans.BeanUtils;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CourseService {
  private final CourseRepository courseRepository;

  public CourseService(CourseRepository courseRepository) {
    this.courseRepository = courseRepository;
  }

  public List<Course> findAll() {
    return courseRepository.findAll();
  }

  public ResponseEntity<Object> save(@NonNull CourseDto courseDto) {
    if(courseDto.isNotValid()) {
      return ResponseEntity.status(HttpStatus.NOT_ACCEPTABLE).body("Not Blank");
    }
    Course course = new Course();
    BeanUtils.copyProperties(courseDto, course);
    courseRepository.save(course);
    return ResponseEntity.status(HttpStatus.CREATED).body(course);
  }

  public ResponseEntity<Object> findById(Long id) {
    return courseRepository.findById(id).<ResponseEntity<Object>>
            map(value -> ResponseEntity.status(HttpStatus.OK).body(value)).
        orElseGet(() -> ResponseEntity.status(HttpStatus.NOT_FOUND).body("ID not found"));
  }

  public ResponseEntity<String> update(Long id, CourseDto courseDto) {
    if (courseDto.isNotValid()) {
      return ResponseEntity.status(HttpStatus.NOT_ACCEPTABLE).body("Not Blank");
    } else if(courseRepository.findById(id).isEmpty()) {
      return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Id not found");
    }
    Course found = courseRepository.findById(id).get();
    BeanUtils.copyProperties(courseDto, found);
    courseRepository.save(found);
    return ResponseEntity.status(HttpStatus.OK).body("");
  }

  public ResponseEntity<Object> deleteById(Long id) {
    return courseRepository.findById(id).
        map(value -> {
          courseRepository.deleteById(id);
          return ResponseEntity.status(HttpStatus.NO_CONTENT).build();
        }).
        orElseGet(() -> ResponseEntity.status(HttpStatus.NOT_FOUND).body("Id not found"));
  }
}
