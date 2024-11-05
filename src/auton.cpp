#include "main.h"
#include "pros/adi.h"
#include "lemlib/api.hpp"
#include <future>   
using namespace pros;
bool isRedTeam = true;
bool enableredirect = true;
ASSET(test_txt);
ASSET(amazing_txt);
ASSET(strai_txt);
ASSET(faster_txt);
ASSET(turn_txt);
ASSET(ultim_txt);
ASSET(final_txt);

void redirectauton(){//Can be replaced with piston color sorter I just used intake stop color sorter for testing
    while(enableredirect){

    
    if(isRingValidRedirectauton() == 2){
        conveyer.move_velocity(600);
        pros::delay(250);
        conveyer.move_velocity(0);
        pros::delay(200);
        conveyer.move_velocity(600);
    /*Color sorter with piston (not tuned yet)
    moveSorter(true);
    wait(1000);
    moveSorter(false);*/
    }
}
}
int isRingValidRedirectauton() {
    while(enableredirect){


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
      return 1;

}
void redawp() {     
    //I copied this auton route https://discord.com/channels/703422250212261939/1061727355426578533/1300264079327232133
    
    pros::Task redirectT(redirectauton);//activates redirect 
    pros::Task ringvalidT(isRingValidRedirectauton);//activates conditions
    intaker(-600);
    chassis.moveToPoint(0, 1.5, 1000,{.forwards = true, .maxSpeed = 127});
    chassis.waitUntilDone();
    move_Doinker(true);
    wait(100);
    moveRelative(-8,127,2000);
    chassis.waitUntilDone();
    move_Doinker(false);
    chassis.turnToHeading(-15, 1000);
    chassis.waitUntilDone();
    moveRelative(10,127,2000);
    chassis.waitUntilDone();
    intaker(0);
    moveRelative(-2,127,500);
    chassis.waitUntilDone();
    chassis.turnToHeading(45,1000);
    chassis.waitUntilDone();
    Arms.move_absolute(1500,600);
    moveRelative(15,127,3000);
    chassis.waitUntilDone();
    Arms.move_absolute(0,600);
    chassis.moveToPoint(-30, -12, 4000,{.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    moveRelative(-8,30,4000);
    moveMogo(true);
    intaker(-600);
    chassis.turnToHeading(180,1000);
    chassis.waitUntilDone();
    moveRelative(15,127,2000);
    chassis.waitUntilDone();
    moveRelative(-7,127,2000);
    chassis.waitUntilDone();
    chassis.turnToHeading(250,1000);
    chassis.waitUntilDone();
    moveRelative(15,127,2000);
    chassis.waitUntilDone();
    moveRelative(-10,127,2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-48, -37, 4000,{.forwards = true, .maxSpeed = 127});
    chassis.waitUntilDone();
    chassis.moveToPoint(-25, -19, 4000,{.forwards = false, .maxSpeed = 127});
    chassis.waitUntilDone();
    chassis.turnToHeading(135,1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-35, 7.7, 4000,{.forwards = false, .maxSpeed = 127});
    chassis.waitUntilDone();

}
void blueawp() {
    pros::Task redirectT(redirectauton);
    pros::Task ringvalidT(isRingValidRedirectauton);
    intaker(-600);
    move_Doinker(true);
    wait(100);
    chassis.turnToHeading(-7, 1000);
    chassis.waitUntilDone();
    chassis.turnToHeading(5, 1000);
    chassis.waitUntilDone();
    move_Doinker(false);
    moveRelative(10,127,2000);
    chassis.waitUntilDone();
    intaker(0);

    chassis.turnToHeading(-135, 1000);
    chassis.waitUntilDone();
    Arms.move_absolute(1500,600);
    wait(0);
    moveRelative(10,127,2000);
    chassis.waitUntilDone();
    Arms.move_absolute(0,600);
    wait(0);
    chassis.moveToPoint(19, 28, 4000,{.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    moveRelative(-8,30,4000);
    moveMogo(true);
    intaker(-600);
    chassis.turnToHeading(90,1000);
    chassis.waitUntilDone();
    moveRelative(15,127,2000);
    chassis.waitUntilDone();
    moveRelative(-7,127,2000);
    chassis.waitUntilDone();
    chassis.turnToHeading(8,1000);
    chassis.waitUntilDone();
    moveRelative(15,127,2000);
    chassis.waitUntilDone();
    moveRelative(-10,127,2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(41, 48, 4000,{.forwards = true, .maxSpeed = 127});
    chassis.waitUntilDone();
    chassis.moveToPoint(-15, -28 , 4000,{.forwards = false, .maxSpeed = 127});
    chassis.waitUntilDone();
    chassis.turnToHeading(135,1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(7.7, 35, 4000,{.forwards = false, .maxSpeed = 127});
    chassis.waitUntilDone();
}
void redrush() {

}
void bluerush() {

}
void redfull() {
//Copy this auton route https://discord.com/channels/703422250212261939/900591595315929098/1299140629808414773
}
void bluefull() {
    
}

void skills() {
    //Copy this auton route https://youtu.be/vWLhzK4SKWo?si=z82Haol58B-TNvxa
}



/*Reference commands-----------------------------------------------------------------------------------------------------
    // example movement: Move to x: 20 and y: 15, and face heading 90. Timeout set to 4000 ms
    chassis.moveToPose(20, 15, 90, 4000);
    // example movement: Move to x: 0 and y: 0 and face heading 270, going backwards. Timeout set to 4000ms
    chassis.moveToPose(0, 0, 270, 4000, {.forwards = false});
    // cancel the movement after it has travelled 10 inches
    chassis.waitUntil(10);
    chassis.cancelMotion();
    // example movement: Turn to face the point x:45, y:-45. Timeout set to 1000
    // dont turn faster than 60 (out of a maximum of 127)
    chassis.turnToPoint(45, -45, 1000, {.maxSpeed = 60});
    // example movement: Turn to face a direction of 90º. Timeout set to 1000
    // will always be faster than 100 (out of a maximum of 127)
    chassis.turnToHeading(90, 1000, {.minSpeed = 100});
    // example movement: Follow the path in path.txt. Lookahead at 15, Timeout set to 4000
    // following the path with the back of the robot (forwards = false)
    // see line 116 to see how to define a path */
    //chassis.follow(path_jerryio_txt, 15, 4000, false);
    // wait until the chassis has travelled 10 inches. Otherwise the code directly after
    // the movement will run immediately
    // Unless its another movement, in which case it will wait
    //chassis.waitUntil(10);
    //pros::lcd::print(4, "Travelled 10 inches during pure pursuit!");
    // wait until the movement is done
    //chassis.waitUntilDone();
    //pros::lcd::print(4, "pure pursuit finished!");*/