#include "frame.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Frame {
    char idVid[50];
    int idFrame;
    float timeStamp;
};

Frame* criaFrame(char *idVid, int idFrame, float timeStamp) {
    Frame* f = (Frame*)malloc(sizeof(Frame));
    strcpy(f->idVid, idVid);
    f->idFrame = idFrame;
    f->timeStamp = timeStamp;
    return f;
}

Frame* leFrame() {
    char idVid[50];
    int idFrame;
    float timeStamp;

    scanf("%s %d %f", idVid, &idFrame, &timeStamp);
    return criaFrame(idVid, idFrame, timeStamp);
}

void printFrame(Frame* a) {
    printf("ID: %d, Timestamp: %.2f\n", a->idFrame, a->timeStamp);
}

void destroiFrame(Frame* a) {
    free(a);
}