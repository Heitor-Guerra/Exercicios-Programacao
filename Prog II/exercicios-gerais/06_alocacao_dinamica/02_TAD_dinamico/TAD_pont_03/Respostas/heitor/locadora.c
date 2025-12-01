#include "locadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_INCREMENTO 1

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL,
 * numFilmes como 0 e lucro como 0.
 *
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou
 * encerra o programa caso não haja memória suficiente.
 */
tLocadora *CriarLocadora() {
  tLocadora *locadora = (tLocadora *)malloc(sizeof(tLocadora));
  locadora->filme = NULL;
  locadora->numFilmes = 0;
  locadora->lucro = 0;
  return locadora;
}

/**
 * @brief Destrói uma instância de tLocadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora(tLocadora *locadora) {
  for (int i = 0; i < locadora->numFilmes; i++) {
    DestruirFilme(locadora->filme[i]);
  }
  free(locadora->filme);
  free(locadora);
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado(tLocadora *locadora, int codigo) {
  for (int i = 0; i < locadora->numFilmes; i++) {
    if (EhMesmoCodigoFilme(locadora->filme[i], codigo)) {
      return 1;
    }
  }
  return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme) {
  if (VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))) {
    printf("Filme ja cadastrado no estoque\n");
    DestruirFilme(filme);
    return;
  }

  printf("Filme cadastrado %d - ", ObterCodigoFilme(filme));
  ImprimirNomeFilme(filme);
  printf("\n");
  locadora->filme = (tFilme **)realloc(locadora->filme,
                                       (locadora->numFilmes + TAM_INCREMENTO) *
                                           sizeof(tFilme *));
  locadora->filme[locadora->numFilmes] = filme;
  locadora->numFilmes++;
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 *
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora(tLocadora *Locadora) {
  int codigo;
  while (scanf("%d", &codigo) == 1) {
    scanf(",");
    tFilme *filme = CriarFilme();
    LeFilme(filme, codigo);
    CadastrarFilmeLocadora(Locadora, filme);
  }
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora(tLocadora *locadora, int *codigos,
                          int quantidadeCodigos) {
  int totalAlugado = 0, custo = 0, filmeCadastrado;
  for (int i = 0; i < quantidadeCodigos; i++) {
    filmeCadastrado = 0;
    for (int j = 0; j < locadora->numFilmes; j++) {
      if (EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
        if (ObterQtdEstoqueFilme(locadora->filme[j]) > 0) {
          AlugarFilme(locadora->filme[j]);
          totalAlugado++;
          custo += ObterValorFilme(locadora->filme[j]);
        } else {
          printf("Filme %d - ", codigos[i]);
          ImprimirNomeFilme(locadora->filme[j]);
          printf(" nao disponivel no estoque. Volte mais tarde.\n");
        }
        filmeCadastrado = 1;
        break;
      }
    }
    if (!filmeCadastrado) {
      printf("Filme %d nao cadastrado.\n", codigos[i]);
    }
  }

  if (totalAlugado > 0) {
    printf("Total de filmes alugados: %d com custo de R$%d\n", totalAlugado,
           custo);
  }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os
 * aluga na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora(tLocadora *locadora) {
  int *codigos = NULL, numCodigos = 0;

  int temp;
  while (1) {
    if (scanf("%d", &temp) != 1) {
      break;
    }
    codigos =
        (int *)realloc(codigos, (numCodigos + TAM_INCREMENTO) * sizeof(int));

    codigos[numCodigos] = temp;
    numCodigos++;
  }
  AlugarFilmesLocadora(locadora, codigos, numCodigos);
  free(codigos);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora(tLocadora *locadora, int *codigos,
                            int quantidadeCodigos) {
  int lucro = 0, filmeCadastrado;
  for (int i = 0; i < quantidadeCodigos; i++) {
    filmeCadastrado = 0;
    for (int j = 0; j < locadora->numFilmes; j++) {
      if (EhMesmoCodigoFilme(locadora->filme[j], codigos[i])) {
        if (ObterQtdAlugadaFilme(locadora->filme[j]) > 0) {
          printf("Filme %d - ", codigos[i]);
          ImprimirNomeFilme(locadora->filme[j]);
          printf(" Devolvido!\n");
          DevolverFilme(locadora->filme[j]);
          lucro += ObterValorFilme(locadora->filme[j]);
        } else {
          printf("Nao e possivel devolver o filme %d - ", codigos[i]);
          ImprimirNomeFilme(locadora->filme[j]);
          printf(".\n");
        }
        filmeCadastrado = 1;
        break;
      }
    }
    if (!filmeCadastrado) {
      printf("Filme %d nao cadastrado.\n", codigos[i]);
    }
  }

  locadora->lucro += lucro;
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na
 * locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora(tLocadora *locadora) {
  int *codigos = NULL, numCodigos = 0;

  int temp;
  while (1) {
    if (scanf("%d", &temp) != 1) {
      break;
    }
    codigos =
        (int *)realloc(codigos, (numCodigos + TAM_INCREMENTO) * sizeof(int));

    codigos[numCodigos] = temp;
    numCodigos++;
  }
  DevolverFilmesLocadora(locadora, codigos, numCodigos);
  free(codigos);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora(tLocadora *locadora) {
  int terminou = 0;
  while (!terminou) {
    for (int i = 1; i < locadora->numFilmes; i++) {
      if (CompararNomesFilmes(locadora->filme[i - 1], locadora->filme[i]) > 0) {
        tFilme *temp = locadora->filme[i - 1];
        locadora->filme[i - 1] = locadora->filme[i];
        locadora->filme[i] = temp;
      }
    }
    terminou = 1;
    for (int i = 1; i < locadora->numFilmes; i++) {
      if (CompararNomesFilmes(locadora->filme[i - 1], locadora->filme[i]) > 0) {
        terminou = 0;
        break;
      }
    }
  }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora(tLocadora *locadora) {
  printf("~ESTOQUE~\n");
  for (int i = 0; i < locadora->numFilmes; i++) {
    printf("%d - ", ObterCodigoFilme(locadora->filme[i]));
    ImprimirNomeFilme(locadora->filme[i]);
    printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
  }
}

/**
 * @brief Consulta o lucro da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora(tLocadora *locadora) {
  if (locadora->lucro > 0) {
    printf("\nLucro total R$%d\n", locadora->lucro);
  }
}
