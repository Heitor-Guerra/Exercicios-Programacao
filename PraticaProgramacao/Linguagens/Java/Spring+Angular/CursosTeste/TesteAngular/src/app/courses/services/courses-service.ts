import { Injectable, inject } from '@angular/core';
import { Course } from '../model/course';
import { HttpClient } from '@angular/common/http';
import { Observable, first } from 'rxjs';

@Injectable({
  providedIn: 'root',
})
export class CoursesService {
  private http:HttpClient = inject(HttpClient);
  private readonly url:string = "http://localhost:8080/api/courses";

  private create(registry: Course): Observable<Course> {
    return this.http.post<Course>(this.url, registry).pipe (
      first(),
    );
  }

  private update(registry: Course ): Observable<Course> {
    return this.http.put<Course>(`${this.url}/${registry._id}`, registry).pipe (
      first(),
    );
  }

  findAll(): Observable<Course[]> {
    return this.http.get<Course[]>(this.url).pipe(
      first(),
    );
  }

  findById(id: string | null): Observable<Course> {
    return this.http.get<Course>(`${this.url}/${Number(id)}`).pipe(
      first(),
    );
  }

  save(registry: Course): Observable<Course> {
    if(registry._id) {
      console.log("update course");
      return this.update(registry);
    } else {
      console.log("adding course");
      return this.create(registry);
    }
  }

  delete(id: string): Observable<Course> {
    return this.http.delete<Course>(`${this.url}/${id}`).pipe(
      first(),
    );
  }

}
