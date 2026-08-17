import { ResolveFn } from '@angular/router';
import {Course} from '../model/course';
import {CoursesService} from '../services/courses-service';
import {inject} from '@angular/core';
import {Observable, of} from 'rxjs';

export const courseResolver: ResolveFn<Observable<Course>> = (route, state) => {
  const courseService: CoursesService = inject(CoursesService);
  if(route.params["id"]) {
    return courseService.findById(route.paramMap.get("id"));
  }
  return  of<Course>({_id: 0, name: '', description: '', category: ''});
};
