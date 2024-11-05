#pragma once
#include "api.h"

// extern void intake_power(double percent);

int intakes();
void MogoClamp();
void StealerClamp();
void Doinker();
void deploystealer();
void Arm();
void ringsorter();
int isRingValid();
void colorsorter();
void moveRelative(float distance, float maxSpeed, int timeout);