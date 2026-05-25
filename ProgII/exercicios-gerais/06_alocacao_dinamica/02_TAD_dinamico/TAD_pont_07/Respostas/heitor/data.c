#include "data.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna.
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 *
 * @return tData - Data "Vazia"
 */
tData *CriaData() {
  tData *data = (tData *)malloc(sizeof(tData));
  data->dia = -1;
  data->mes = -1;
  data->ano = -1;

  return data;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada
 * dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados.
 * Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData *data) {
  scanf("%d/%d/%d", &data->dia, &data->mes, &data->ano);
}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo
 * tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados.
 */
void LiberaData(tData *data) { free(data); }

/**
 * @brief Verifica se uma data é válida.
 *
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData *data) {
  return (data->mes > 0 && data->mes <= 12) &&
         (data->dia > 0 && data->dia <= NumeroDiasMes(data));
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 *
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData *data) {
  switch (data->mes) {
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
 * @brief Imprime uma data em formato extenso.
 *
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData *data) {
  printf("%02d de ", data->dia);
  ImprimeMesExtenso(data);
  printf(" de %04d\n", data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData *data) {
  return (data->ano % 4 == 0 && data->ano % 100 != 0) ||
         (data->ano % 100 == 0 && data->ano % 400 == 0);
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData *data) {
  switch (data->mes) {
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
  default:
    return 0;
  }
}

/**
 * @brief Compara duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se
 * as datas são iguais. A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData *data1, tData *data2) {
  if ((data1->ano > data2->ano) ||
      (data1->ano == data2->ano && data1->mes > data2->mes) ||
      (data1->ano == data2->ano && data1->mes == data2->mes &&
       data1->dia > data2->dia)) {
    return 1;
  } else if (data1->ano == data2->ano && data1->mes == data2->mes &&
             data1->dia == data2->dia) {
    return 0;
  }
  return -1;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData *data) {
  int soma = 0;
  for (int i = 1; i < data->mes; i++) {
    tData temp = {1, i, data->ano};
    soma += NumeroDiasMes(&temp);
  }
  return soma;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData *data1, tData *data2) {
  int dias = abs(CalculaDiasAteMes(data1) + data1->dia -
                 (CalculaDiasAteMes(data2) + data2->dia));

  int primeiroAno, segundoAno;
  if (data1->ano > data2->ano) {
    primeiroAno = data2->ano;
    segundoAno = data1->ano;
  } else {
    primeiroAno = data1->ano;
    segundoAno = data2->ano;
  }

  for (int i = primeiroAno; i < segundoAno; i++) {
    tData temp = {1, 1, i};
    if (VerificaBissexto(&temp)) {
      dias += 366;
    } else {
      dias += 365;
    }
  }

  return dias;
}
