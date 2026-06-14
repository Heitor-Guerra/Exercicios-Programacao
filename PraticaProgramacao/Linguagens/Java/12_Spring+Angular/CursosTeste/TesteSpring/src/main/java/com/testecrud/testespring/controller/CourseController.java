package com.testecrud.testespring.controller;

import com.testecrud.testespring.dto.CourseDto;
import com.testecrud.testespring.model.Course;
import com.testecrud.testespring.service.CourseService;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api/courses")
public class CourseController {

  private final CourseService courseService;

  public CourseController(CourseService courseService) {
    this.courseService = courseService;
  }

  @GetMapping
  public ResponseEntity<List<Course>> findAll() {
    return ResponseEntity.status(HttpStatus.OK).body(courseService.findAll());
  }

  @PostMapping
  @ResponseStatus
  public ResponseEntity<Object> save(@RequestBody CourseDto courseDto) {
    return courseService.save(courseDto);
  }

  @GetMapping("/{id}")
  public ResponseEntity<Object> findById(@PathVariable Long id) {
    return courseService.findById(id);
  }

  @PutMapping("/{id}")
  public ResponseEntity<String> update(@PathVariable Long id, @RequestBody CourseDto courseDto) {
    return courseService.update(id, courseDto);
  }

  @DeleteMapping("/{id}")
  public ResponseEntity<Object> delete(@PathVariable Long id) {
    return courseService.deleteById(id);
  }
}
