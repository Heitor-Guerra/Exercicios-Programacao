#ifndef _PROGRAM_H
#define _PROGRAM_H

typedef struct Program Program;

Program *program_construct(char *nome, char *tipo, int prio, int carga, int inicio);

char* program_get_name(Program* p);
char* program_get_tipo(Program* p);
int program_get_prio(Program* p);
int program_get_carga(Program* p);
int program_get_inicio(Program* p);
int program_get_fim(Program* p);

void program_carga_decrement(Program* p);
void program_set_fim(Program* p, int fim) ;

int program_compare(const void* a, const void* b);

void program_destroy(Program* p);

#endif