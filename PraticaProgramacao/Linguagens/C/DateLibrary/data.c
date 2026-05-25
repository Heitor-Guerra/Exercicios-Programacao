#include "data.h"
#include <stdio.h>
#include <stdlib.h>

#define NUMERO_DIAS_ANO_NORMAL 365
#define NUMERO_DIAS_ANO_BISSEXTO NUMERO_DIAS_ANO_NORMAL + 1

/**
 * @brief Verifica se uma data é válida.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano) {
  if (mes > 12 || mes < 0) {
    return 0;
  }
  if (dia > numeroDiasMes(mes, ano) || dia < 0) {
    return 0;
  }
  return 1;
}

/**
 * @brief Imprime o nome do mês por extenso.
 *
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes) {
  switch (mes) {
  case 1:
    printf("Janeiro");
    break;
  case 2:
    printf("Fevereiro");
    break;
  case 3:
    printf("Marco");
    break;
  case 4:
    printf("Abril");
    break;
  case 5:
    printf("Maio");
    break;
  case 6:
    printf("Junho");
    break;
  case 7:
    printf("Julho");
    break;
  case 8:
    printf("Agosto");
    break;
  case 9:
    printf("Setembro");
    break;
  case 10:
    printf("Outubro");
    break;
  case 11:
    printf("Novembro");
    break;
  case 12:
    printf("Dezembro");
    break;
  }
}

/**
 * @brief Imprime a data por extenso.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano) {
  printf("%02d de ", dia);
  imprimeMesExtenso(mes);
  printf(" de %d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano) {
  if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 100 == 0 && ano % 400 == 0)) {
    return 1;
  }
  return 0;
}

/**
 * @brief Calcula o número de dias de um mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano) {
  switch (mes) {
  case 1:
    return 31;
  case 2:
    if (verificaBissexto(ano)) {
      return 29;
    }
    return 28;
  case 3:
    return 31;
  case 4:
    return 30;
  case 5:
    return 31;
  case 6:
    return 30;
  case 7:
    return 31;
  case 8:
    return 31;
  case 9:
    return 30;
  case 10:
    return 31;
  case 11:
    return 30;
  case 12:
    return 31;
  }
  return 0;
}

/**
 * @brief Compara duas datas.
 *
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a
 * primeira data é menor que a segunda e 0 se as datas são iguais. A data ser
 * "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
  if (ano1 > ano2 || (ano1 == ano2 && mes1 > mes2) ||
      (ano1 == ano2 && mes1 == mes2 && dia1 > dia2)) {
    return 1;
  }
  if (ano1 < ano2 || (ano1 == ano2 && mes1 < mes2) ||
      (ano1 == ano2 && mes1 == mes2 && dia1 < dia2)) {
    return -1;
  }
  return 0;
}

/**
 * @brief Calcula o número de dias até o mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
 */
int calculaDiasAteMes(int mes, int ano) {
  int dias = 0;
  for (int i = 1; i < mes; i++) {
    dias += numeroDiasMes(i, ano);
  }
  return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2,
                         int ano2) { // Talvez
  int dias = 0;

  dias += abs(calculaDiasAteMes(mes2, ano2) + dia2 -
              (calculaDiasAteMes(mes1, ano1) + dia1));

  if (ano1 < ano2) {
    for (int i = ano1; i < ano2; i++) {
      if (verificaBissexto(i)) {
        dias += NUMERO_DIAS_ANO_BISSEXTO;
      } else {
        dias += NUMERO_DIAS_ANO_NORMAL;
      }
    }
  } else if (ano2 < ano1) {
    for (int i = ano2; i < ano1; i++) {
      if (verificaBissexto(i)) {
        dias += NUMERO_DIAS_ANO_BISSEXTO;
      } else {
        dias += NUMERO_DIAS_ANO_NORMAL;
      }
    }
  }
  return dias;
}

/**
 * @brief Imprime a próxima data no formato DD/MM/AAAA.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeProximaData(int dia, int mes, int ano) {
  dia++;
  if (dia > numeroDiasMes(mes, ano)) {
    dia = 1;
    mes++;
    if (mes > 12) {
      mes = 1;
      ano++;
    }
  }
  printf("%02d/%02d/%d", dia, mes, ano);
}
