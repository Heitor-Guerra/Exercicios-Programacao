import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'category',
})

export class CategoryPipe implements PipeTransform {
  transform(value: string): string {
    switch(value) {
      case "Frontend": return "code";
      case "Backend": return "api";
      case "Software": return "data_object";
      case "Computer Structure": return "terminal_2";
      default: return "code_off"
    }
  }
}
