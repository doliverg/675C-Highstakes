#include "main.h"

void intaker_wait(double v,int time) {
    conveyer.move_velocity(-v);
    pros::delay(time);
    conveyer.move_velocity(0);
}

void intaker(double v) {
    conveyer.move_velocity(-v);
}

void outtaker(double v) {
    conveyer.move_velocity(v);
}

void moveMogo(bool way) {
    MogoClampL.set_value(way);
  //  MogoClampR.set(way);
}
void wait(int time){
  pros::delay(time);
}

void outtaker_wait(double v, int time){
    conveyer.move_velocity(v);
    pros::delay(time);
    conveyer.move_velocity(0);
}
void move_Doinker(bool state){
    DoinkerL.set_value(state);
 //   hangR.set(state);
}
void move_Stealerdeploy(bool state){
    StealerdeployL.set_value(state);
 //   hangR.set(state);
}
void move_Stealerclamp(bool state){
    StealerClampL.set_value(state);
  //  IntakeLiftR.set(state);
}
void moveSorter(bool way) {
    SorterL.set_value(way);
  //  MogoClampR.set(way);
}
//--------------------------------------------------------------------------------------------------------------------
void colorsorter(){
    if(isRingValid() == 2){
    moveSorter(true);
    wait(1000);
    moveSorter(false);
}
}

void redirect(){
    if(isRingValidRedirect() == 2){
        conveyer.move_velocity(600);
        pros::delay(80);//might need more tuning after bot is done
        conveyer.move_velocity(-600);
        pros::delay(1000);
        conveyer.move_velocity(0);

    }
}

int isRingValid() {
    bool isRedTeam = true;
    optical_sensor.set_led_pwm(100);

    if (isRedTeam){
        if(optical_sensor.get_hue() < 22) return 1; //1 means the ring is the right color
        else if(optical_sensor.get_hue() > 140 && optical_sensor.get_hue() < 250) return 2; //2 means its the color of the opposite team
        else return 0;// 0 means there's nothing there
    }
    else{
        if(optical_sensor.get_hue() > 140 && optical_sensor.get_hue() < 250) return 1;
        else if(optical_sensor.get_hue() < 22) return 2;
        else return 0;
    }
    }

    int isRingValidRedirect() {
    bool isRedTeam = false;
    optical_sensor.set_led_pwm(100);

    if (isRedTeam){
        if(optical_sensor.get_hue() < 22) return 1; //1 means the ring is the right color
        else if(optical_sensor.get_hue() > 140 && optical_sensor.get_hue() < 250) return 2; //2 means its the color of the opposite team
        else return 0;// 0 means there's nothing there
    }
    else{
        if(optical_sensor.get_hue() > 140 && optical_sensor.get_hue() < 250) return 1;
        else if(optical_sensor.get_hue() < 22) return 2;
        else return 0;
    }
    }

void moveRelative(float distance, float maxSpeed, int timeout) {
    double headingRadians = chassis.getPose(true).theta;
    double startingX = chassis.getPose().x;
    double startingY = chassis.getPose().y;
    double deltaX = distance * sin(headingRadians);
    double deltaY = distance * cos(headingRadians);
    double newX = startingX + deltaX;
    double newY = startingY + deltaY;
    if (distance > 0) {
        chassis.moveToPoint(newX, newY, timeout, {.forwards=true, .maxSpeed=maxSpeed});
    }
    else if (distance < 0) {
        chassis.moveToPoint(newX, newY, timeout, {.forwards=false, .maxSpeed=maxSpeed});
    }
}
