#include <stdio.h>

#define TAM_MAXIMO_MENSAGEM 10

typedef struct {
    int idMensagem;
    int idPacote;
    int tamConteudo;
    char mensagem[TAM_MAXIMO_MENSAGEM];
    int codErro;
} tPacote;

tPacote LePacote() {
    tPacote pacote;
    int i;
    scanf("%3d %3d %1d", &pacote.idMensagem, &pacote.idPacote, &pacote.tamConteudo);
    for(i = 0; i < pacote.tamConteudo; i++) {
        scanf("%c", &pacote.mensagem[i]);
    }
    pacote.mensagem[i] = '\0';
    scanf("%*[^ ]");
    scanf("%4d", &pacote.codErro);
    scanf("%*[^\n]");
    scanf("\n");

    return pacote;
}

void TrocaPosicaoPacote(tPacote vet[], int pos1, int pos2) {
    tPacote aux;
    aux = vet[pos1];
    vet[pos1] = vet[pos2];
    vet[pos2] = aux;
}

int VerificaSemErroPacote(tPacote pacote) {
    int i;
    int soma = 0;
    soma = pacote.idMensagem + pacote.idPacote + pacote.tamConteudo;
    for(i = 0; i < pacote.tamConteudo; i++) {
        soma += (int)pacote.mensagem[i];
    }
    return soma == pacote.codErro;
}

void OrdenarPacotes(tPacote pacote[], int tam) {
    int i, pronto = 0;
    while(!pronto) {
        for(i = 1; i < tam; i++) {
            if(pacote[i-1].idMensagem > pacote[i].idMensagem) {
                TrocaPosicaoPacote(pacote, i-1, i);
            }
            else if((pacote[i-1].idMensagem == pacote[i].idMensagem) && (pacote[i-1].idPacote > pacote[i].idPacote)){
                TrocaPosicaoPacote(pacote, i-1, i);
            }
        }
        pronto = 1;
        for(i = 1; i < tam; i++) {
            if((pacote[i-1].idMensagem > pacote[i].idMensagem) || ((pacote[i-1].idMensagem == pacote[i].idMensagem) && (pacote[i-1].idPacote > pacote[i].idPacote))) {
                pronto = 0;
                break;
            }
        }
    }
}

void VerificaFimMensagem(tPacote pacote[], int iteracao) {
    if((pacote[iteracao-1].idMensagem != pacote[iteracao].idMensagem) && iteracao != 0) {
        printf("\n");
    }
}

void ImprimePacote(tPacote pacote) {
    printf("PCT: %d,%d,%d,%s,%d\n", pacote.idMensagem, pacote.idPacote, pacote.tamConteudo, pacote.mensagem, pacote.codErro);
}

void ImprimeMensagemPacote(tPacote pacote) {
    printf("%s", pacote.mensagem);
}


int main() {
    int i;
    int numPacotes = 0;
    scanf("%d", &numPacotes);
    tPacote pacotes[numPacotes];

    for(i = 0; i < numPacotes; i++) {
        pacotes[i] = LePacote();
    }
    OrdenarPacotes(pacotes, numPacotes);
    for(i = 0; i < numPacotes; i++) {
        VerificaFimMensagem(pacotes, i);
        if(VerificaSemErroPacote(pacotes[i])){
            ImprimeMensagemPacote(pacotes[i]);
        }
        else{
            printf("##FALHA##");
        }
    }

    return 0;
}