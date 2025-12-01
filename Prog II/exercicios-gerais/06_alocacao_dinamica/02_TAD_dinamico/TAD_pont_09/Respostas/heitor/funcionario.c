#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Cria um funcionario "vazio"
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso
 * contrário
 * @return TFuncionario Ponteiro para Funcionario criado a partir do nome e
 * salario fornecidos.
 */
tFuncionario *CriaFuncionario() {
  tFuncionario *func = (tFuncionario *)malloc(sizeof(tFuncionario));
  func->id = -1;
  func->salario = -1;
  return func;
}

/**
 * @brief Libera a memória alocada dinamicamente por um funcionário
 * @param funcionario Ponteiro para Funcionario que terá sua memória liberada
 */
void ApagaFuncionario(tFuncionario *funcionario) { free(funcionario); }

/**
 * @brief Le os dados de um funcionario da entrada padrao.
 *
 * @param funcionario Funcionario criado a partir dos dados lidos.
 */
void LeFuncionario(tFuncionario *funcionario) {
  scanf("%d %f\n", &funcionario->id, &funcionario->salario);
}

/**
 * @brief Obtem o Id de um funcionario.
 *
 * @param funcionario Funcionario que deseja obter o id.
 * @return int representando o id do funcionario fornecido.
 */
int GetIdFuncionario(tFuncionario *funcionario) { return funcionario->id; }

/**
 * @brief Imprime todos os dados de um funcionario.
 *
 * @param funcionario Funcionario a ser impresso no terminal.
 */
void ImprimeFuncionario(tFuncionario *funcionario) {
  printf("- Funcionario %d: RS %.2f\n", funcionario->id, funcionario->salario);
}
