#pragma once
#include "api.h"

void intaker(double v);
void intaker_wait(double v, int time);
void outtaker(double v);
void moveMogo(bool way);
void wait(int time);
void outtaker_wait(double v, int time);
void move_Doinker(bool state);
void move_Stealerdeploy(bool state);
void move_Stealerclamp(bool state);
int isRingValid();
void colorsorter();
void redirect();
void moveSorter(bool way);
void moveRelative(float distance, float maxSpeed, int timeout);
int isRingValidRedirect();
//void run_cata(int time);
