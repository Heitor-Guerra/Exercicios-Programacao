#include "locadora.h"
#include <stdio.h>

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora() {
  tLocadora locadora;
  locadora.numFilmes = 0;
  locadora.lucro = 0;

  return locadora;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado(tLocadora locadora, int codigo) {
  for (int i = 0; i < locadora.numFilmes; i++) {
    if (ehMesmoCodigoFilme(locadora.filme[i], codigo)) {
      return 1;
    }
  }
  return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
 */
tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme) {
  if (!verificarFilmeCadastrado(locadora, obterCodigoFilme(filme))) {
    printf("Filme cadastrado %d - ", obterCodigoFilme(filme));
    imprimirNomeFilme(filme);
    printf("\n");
    locadora.filme[locadora.numFilmes] = filme;
    locadora.numFilmes++;
  } else {
    puts("Filme ja cadastrado no estoque");
  }
  return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o
 * cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora(tLocadora locadora) {
  int codigo;
  while (scanf("%d", &codigo) == 1) {
    scanf(",");
    tFilme filme = leFilme(codigo);
    locadora = cadastrarFilmeLocadora(locadora, filme);
  }
  return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora(tLocadora locadora, int *codigos,
                               int quantidadeCodigos) {
  int custo = 0, filmeNaoCadastrado, filmesAlugados = 0;
  for (int i = 0; i < quantidadeCodigos; i++) {
    filmeNaoCadastrado = 1;
    for (int j = 0; j < locadora.numFilmes; j++) {
      if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
        if (obterQtdEstoqueFilme(locadora.filme[j]) > 0) {
          locadora.filme[j] = alugarFilme(locadora.filme[j]);
          filmesAlugados++;
          custo += obterValorFilme(locadora.filme[j]);
        } else {
          printf("Filme %d - ", codigos[i]);
          imprimirNomeFilme(locadora.filme[j]);
          puts(" nao disponivel no estoque. Volte mais tarde.");
        }
        filmeNaoCadastrado = 0;
        break;
      }
    }
    if (filmeNaoCadastrado) {
      printf("Filme %d nao cadastrado.\n", codigos[i]);
    }
  }

  if (filmesAlugados > 0) {
    printf("Total de filmes alugados: %d com custo de R$%d\n", filmesAlugados,
           custo);
  }

  return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os
 * aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora(tLocadora locadora) {
  int codigos[MAX_FILMES];
  int numCodigos = 0;
  while (scanf("%d", &codigos[numCodigos]) == 1) {
    numCodigos++;
  }
  locadora = alugarFilmesLocadora(locadora, codigos, numCodigos);
  return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora(tLocadora locadora, int *codigos,
                                 int quantidadeCodigos) {
  int filmeNaoCadastrado, lucro = 0;
  for (int i = 0; i < quantidadeCodigos; i++) {
    filmeNaoCadastrado = 1;
    for (int j = 0; j < locadora.numFilmes; j++) {
      if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
        if (obterQtdAlugadaFilme(locadora.filme[j]) > 0) {
          printf("Filme %d - ", codigos[i]);
          imprimirNomeFilme(locadora.filme[j]);
          puts(" Devolvido!");
          lucro += obterValorFilme(locadora.filme[j]);
          locadora.filme[j] = devolverFilme(locadora.filme[j]);
        } else {
          printf("Nao e possivel devolver o filme %d - ", codigos[i]);
          imprimirNomeFilme(locadora.filme[j]);
          puts(".");
        }
        filmeNaoCadastrado = 0;
        break;
      }
    }
    if (filmeNaoCadastrado) {
      printf("Filme %d nao cadastrado.\n", codigos[i]);
    }
  }
  locadora.lucro += lucro;
  return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e
 * os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora(tLocadora locadora) {
  int codigos[MAX_FILMES];
  int numCodigos = 0;
  while (scanf("%d", &codigos[numCodigos]) == 1) {
    numCodigos++;
  }
  locadora = devolverFilmesLocadora(locadora, codigos, numCodigos);
  return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora(tLocadora locadora) {
  int terminou = 0;
  tFilme tmp;
  while (!terminou) {
    for (int i = 1; i < locadora.numFilmes; i++) {
      if (compararNomesFilmes(locadora.filme[i - 1], locadora.filme[i]) > 0) {
        tmp = locadora.filme[i - 1];
        locadora.filme[i - 1] = locadora.filme[i];
        locadora.filme[i] = tmp;
      }
    }
    terminou = 1;
    for (int i = 1; i < locadora.numFilmes; i++) {
      if (compararNomesFilmes(locadora.filme[i - 1], locadora.filme[i]) > 0) {
        terminou = 0;
      }
    }
  }
  return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora(tLocadora locadora) {
  puts("~ESTOQUE~");
  for (int i = 0; i < locadora.numFilmes; i++) {
    printf("%d - ", obterCodigoFilme(locadora.filme[i]));
    imprimirNomeFilme(locadora.filme[i]);
    printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
  }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora(tLocadora locadora) {
  if (locadora.lucro > 0) {
    printf("\nLucro total R$%d\n", locadora.lucro);
  }
}
