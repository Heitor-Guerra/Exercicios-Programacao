import { Component, inject } from '@angular/core';
import { catchError, Observable, of } from 'rxjs';
import { CommonModule } from '@angular/common';
import {ActivatedRoute, Router} from '@angular/router';

import { MatCardModule } from '@angular/material/card';
import { MatToolbarModule } from '@angular/material/toolbar';
import { MatTableModule } from '@angular/material/table';
import { MatProgressSpinnerModule } from '@angular/material/progress-spinner';
import {MatDialog, MatDialogRef} from '@angular/material/dialog';
import { MatIconModule } from '@angular/material/icon';
import { MatButtonModule } from '@angular/material/button';

import { Course } from './model/course';
import { CoursesService } from './services/courses-service';
import { ErrorDialog } from '../shared/error-dialog/error-dialog';
import { CategoryPipe } from '../shared/pipes/category-pipe';
import {MatSnackBar} from '@angular/material/snack-bar';
import {ConfirmDialog} from '../shared/confirm-dialog/confirm-dialog/confirm-dialog';


@Component({
  selector: 'app-courses',
  imports: [MatTableModule, MatCardModule, MatToolbarModule, MatProgressSpinnerModule, MatIconModule, CommonModule, CategoryPipe, MatButtonModule],
  templateUrl: './courses.html',
  styleUrl: './courses.scss',
})
export class Courses {
  displayedColumns: string[] = ['_id', 'name', 'description', 'category', 'actions'];
  dataSource$: Observable<Course[]> = new Observable<Course[]>();
  private dialog:MatDialog = inject(MatDialog);
  private router: Router = inject(Router);
  readonly route: ActivatedRoute = inject(ActivatedRoute);
  private snackBar: MatSnackBar = inject(MatSnackBar);
  private coursesService: CoursesService = inject(CoursesService);

  constructor() {
    this.refresh();
  }

  private refresh(): void {
    this.dataSource$ = this.coursesService.findAll().pipe(
      catchError(error  => {
        console.log(error);
        this.onError("There was an error loading the courses");
        return of([]);
      }));
  }

  private processDelete(id: string):void {
    this.coursesService.delete(id).subscribe({
      next: (): void => {
        let message:string = "Course removed successfully";
        this.snackBar.open(message, 'X', {
          verticalPosition: "top",
          duration: 5000,
        });
        this.refresh();
      },
      error: (err: any): void => {
        console.error("something wrong occurred: ", err);
        this.snackBar.open("There was an error removing the course", '', {
          duration: 5000,
        });
      },
    });
  }

  private onError(errorMsg: string): void {
    this.dialog.open(ErrorDialog, {
      data: errorMsg
    });
  }

  onAdd(): void {
    this.router.navigate(['new'], {relativeTo: this.route}).then(() => {});
  }

  onUpdate(id: number): void {
    this.router.navigate(['edit', id], {relativeTo: this.route}).then(() => {});
  }

  onDelete(id: string): void {
    const dialog: MatDialogRef<ConfirmDialog> = this.dialog.open(ConfirmDialog);
    dialog.afterClosed().subscribe(result => {
      if(result) {
        this.processDelete(id);
      }
    });


  }
}
