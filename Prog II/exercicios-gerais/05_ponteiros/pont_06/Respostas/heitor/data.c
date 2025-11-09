#include "data.h"
#include <stdio.h>

/**
 * @brief Inicializa uma data com os valores passados como parâmetro.
 *
 * Esta função recebe como parâmetro o dia, mês e ano de uma data e inicializa a
 * estrutura tData correspondente com esses valores.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @param data Ponteiro para a estrutura tData que será inicializada.
 */
void InicializaDataParam(int dia, int mes, int ano, tData *data) {
  data->ano = ano;
  if (mes > 12) {
    data->mes = 12;
  } else if (mes < 1) {
    data->mes = 1;
  } else {
    data->mes = mes;
  }

  if (dia > InformaQtdDiasNoMes(data)) {
    data->dia = InformaQtdDiasNoMes(data);
  } else if (dia < 1) {
    data->dia = 1;
  } else {
    data->dia = dia;
  }
}

/**
 * @brief Lê uma data do usuário.
 *
 * Esta função lê do usuário o dia, mês e ano de uma data e armazena esses
 * valores na estrutura tData correspondente.
 *
 * @param data Ponteiro para a estrutura tData que será preenchida com os
 * valores lidos.
 */
void LeData(tData *data) {
  int dia, mes, ano;
  scanf("%d %d %d\n", &dia, &mes, &ano);

  InicializaDataParam(dia, mes, ano, data);
}

/**
 * @brief Imprime uma data na tela.
 *
 * Esta função recebe como parâmetro uma estrutura tData e imprime na tela o
 * dia, mês e ano correspondentes.
 *
 * @param data Ponteiro para a estrutura tData que será impressa.
 */
void ImprimeData(tData *data) {
  printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * Esta função recebe como parâmetro uma estrutura tData e verifica se o ano
 * correspondente é bissexto.
 *
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return 1 se o ano é bissexto, 0 caso contrário.
 */
int EhBissexto(tData *data) {
  return (data->ano % 4 == 0 && data->ano % 100 != 0) ||
         (data->ano % 100 == 0 && data->ano % 400 == 0);
}

/**
 * @brief Informa a quantidade de dias no mês de uma data.
 *
 * Esta função recebe como parâmetro uma estrutura tData e informa a quantidade
 * de dias no mês correspondente.
 *
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return Quantidade de dias no mês correspondente.
 */
int InformaQtdDiasNoMes(tData *data) {
  switch (data->mes) {
  case 1:
    return 31;
  case 2:
    if (EhBissexto(data)) {
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
  return -1;
}

/**
 * @brief Avança uma data para o dia seguinte.
 *
 * Esta função recebe como parâmetro uma estrutura tData e avança a data
 * correspondente para o dia seguinte.
 *
 * @param data Ponteiro para a estrutura tData que será avançada.
 */
void AvancaParaDiaSeguinte(tData *data) {
  data->dia++;
  if (data->dia > InformaQtdDiasNoMes(data)) {
    data->dia = 1;
    data->mes++;
  }
  if (data->mes > 12) {
    data->mes = 1;
    data->ano++;
  }
}

/**
 * @brief Verifica se duas datas são iguais.
 *
 * Esta função recebe como parâmetro duas estruturas tData e verifica se elas
 * representam a mesma data.
 *
 * @param data1 Ponteiro para a primeira estrutura tData que será comparada.
 * @param data2 Ponteiro para a segunda estrutura tData que será comparada.
 * @return 1 se as datas são iguais, 0 caso contrário.
 */
int EhIgual(tData *data1, tData *data2) {
  return data1->dia == data2->dia && data1->mes == data2->mes &&
         data1->ano == data2->ano;
}
