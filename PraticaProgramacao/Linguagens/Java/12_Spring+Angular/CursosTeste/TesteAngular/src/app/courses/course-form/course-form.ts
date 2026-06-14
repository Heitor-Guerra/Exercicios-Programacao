import {Component, inject} from '@angular/core';
import { Location} from '@angular/common';
import {FormBuilder, FormControl, FormGroup, ReactiveFormsModule} from '@angular/forms';
import {MatFormFieldModule} from '@angular/material/form-field';
import {MatInput} from '@angular/material/input';
import {MatButtonModule} from '@angular/material/button';
import {MatCardModule} from '@angular/material/card';
import {MatSelectModule} from '@angular/material/select';
import {MatSnackBar} from '@angular/material/snack-bar';
import {CoursesService} from '../services/courses-service';
import {Course} from '../model/course';
import {ActivatedRoute} from '@angular/router';

@Component({
  selector: 'app-course-form',
  imports: [ReactiveFormsModule, MatFormFieldModule, MatInput, MatButtonModule, MatCardModule, MatSelectModule, ],
  templateUrl: './course-form.html',
  styleUrl: './course-form.scss',
})
export class CourseForm {
  private formBuilder: FormBuilder = inject(FormBuilder);
  private service: CoursesService = inject(CoursesService);
  private location: Location = inject(Location);
  private snackBar: MatSnackBar = inject(MatSnackBar);
  private route: ActivatedRoute = inject(ActivatedRoute);

  formGroup: FormGroup =  this.formBuilder.group({
    _id: new FormControl<number>(0),
    name: new FormControl<string>('', {nonNullable: true}),
    description: new FormControl<string>('', {nonNullable: true}),
    category: new FormControl<string>('', {nonNullable:true}),
  });

  constructor() {
    const course: Course = this.route.snapshot.data["course"];

    console.log(course);
    this.formGroup.setValue( {
      _id: course._id,
      name: course.name,
      description: course.description,
      category: course.category,
    });
  }

  onCancel(): void {
    this.location.back();
  }

  onSubmit(): void {
    this.service.save(this.formGroup.value).subscribe({
      next: (result: Course): void => {
        let message:string = "Course created successfully";
        if(result === null) {
          message = "Course updated successfully";
        }
        this.snackBar.open(message, '', {
          duration: 5000,
        });
      },
      error: (err: any): void=> {
        console.error('something wrong occurred: ', err);
        this.snackBar.open("There was an error creating the course", '', {
          duration: 5000,
        });
      },
    });
  }
}
