#include "data.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 *
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano) {
  tData data = {dia, mes, ano};
  return data;
}

/**
 * @brief Verifica se uma data é válida.
 *
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data) {
  if (data.dia < 1 || data.dia > NumeroDiasMes(data)) {
    return 0;
  }
  if (data.mes < 1 || data.mes > 12) {
    return 0;
  }
  return 1;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 *
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data) {
  switch (data.mes) {
  case 1:
    printf("Janeiro");
    return;
  case 2:
    printf("Fevereiro");
    return;
  case 3:
    printf("Marco");
    return;
  case 4:
    printf("Abril");
    return;
  case 5:
    printf("Maio");
    return;
  case 6:
    printf("Junho");
    return;
  case 7:
    printf("Julho");
    return;
  case 8:
    printf("Agosto");
    return;
  case 9:
    printf("Setembro");
    return;
  case 10:
    printf("Outubro");
    return;
  case 11:
    printf("Novembro");
    return;
  case 12:
    printf("Dezembro");
    return;
  }
}

/**
 * @brief Imprime uma data em formato extenso.
 *
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data) {
  printf("%02d de ", data.dia);
  ImprimeMesExtenso(data);
  printf(" de %4d\n", data.ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data) {
  return (data.ano % 4 == 0 && data.ano % 100 != 0) ||
         (data.ano % 100 == 0 && data.ano % 400 == 0);
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data) {
  switch (data.mes) {
  case 1:
    return 31;
  case 2:
    if (VerificaBissexto(data)) {
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
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se
 * as datas são iguais. A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData data1, tData data2) {
  if (data1.ano > data2.ano ||
      (data1.ano == data2.ano && data1.mes > data2.mes) ||
      (data1.ano == data2.ano && data1.mes == data2.mes &&
       data1.dia > data2.dia)) {
    return 1;
  } else if (data1.ano < data2.ano ||
             (data1.ano == data2.ano && data1.mes < data2.mes) ||
             (data1.ano == data2.ano && data1.mes == data2.mes &&
              data1.dia < data2.dia)) {
    return -1;
  }
  return 0;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data) {
  int dias = 0;
  for (int i = 1; i < data.mes; i++) {
    tData tmp = {0, i, data.ano};
    dias += NumeroDiasMes(tmp);
  }
  return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2) {
  int dias = 0;
  dias = abs(CalculaDiasAteMes(data1) + data1.dia -
             (CalculaDiasAteMes(data2) + data2.dia));

  if (data1.ano > data2.ano) {
    for (int i = data2.ano; i < data1.ano; i++) {
      tData tmp = {0, 0, i};
      if (VerificaBissexto(tmp)) {
        dias += 366;
        continue;
      }
      dias += 365;
    }
  } else {
    for (int i = data1.ano; i < data2.ano; i++) {
      tData tmp = {0, 0, i};
      if (VerificaBissexto(tmp)) {
        dias += 366;
        continue;
      }
      dias += 365;
    }
  }
  return dias;
}
