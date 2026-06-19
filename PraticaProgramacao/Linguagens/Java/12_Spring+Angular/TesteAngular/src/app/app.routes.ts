import { Routes } from '@angular/router';
import { Courses } from './courses/courses';
import {courseResolver} from './courses/guards/course-resolver';

const coursesRoute: string = "courses";

export const routes: Routes = [
  {path: '', pathMatch:'full', redirectTo:'courses'},
  {
    path: coursesRoute,
    loadComponent: () => import('./courses/courses').then((m) => m.Courses),
    title: "Courses",
    // children: [
    //   {
    //     path: 'new',
    //     loadComponent: () => import('./courses/course-form/course-form').then((m) => m.CourseForm),
    //     title: "Add Course",
    //   }
    // ]
  },
  {
    path: coursesRoute+'/new',
    loadComponent: () => import('./courses/course-form/course-form').then((m) => m.CourseForm),
    title: "Add Course",
    resolve: {
      course: courseResolver,
    }
  },
  {
    path: coursesRoute+'/edit/:id',
    loadComponent: () => import('./courses/course-form/course-form').then((m) => m.CourseForm),
    title: "Edit Course",
    resolve: {
      course: courseResolver,
    }
  },
];
