#ifndef _FRAME_H
#define _FRAME_H

typedef struct Frame Frame;

Frame* criaFrame(char *idVid, int idFrame, float timeStamp);

Frame* leFrame();

void printFrame(Frame* a);

void destroiFrame(Frame* a);

#endif


