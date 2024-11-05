#include "main.h"
#include "lemlib/api.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors

    // the default rate is 50. however, if you need to change the rate, you
    // can do the following.
    // lemlib::bufferedStdout().setRate(...);
    // If you use bluetooth or a wired connection, you will want to have a rate of 10ms

    // for more information on how the formatting for the loggers
    // works, refer to the fmtlib docs

    // thread to for brain screen and position logging
    pros::Task screenTask([&]() {
        lemlib::Pose pose(0, 0, 0);
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
            // log position telemetry
            lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
            // delay to save resources
            pros::delay(50);
        }
    });
}

/**
 * Runs while the robot is disabled
 */
void disabled() {chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);}
/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {}

// get a path used for pure pursuit
// this needs to be put outside a function

/**
 * Runs during auto
 *
 * This is an example autonomous routine which demonstrates a lot of the features LemLib has to offer
 */
void autonomous() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  pros::c::motor_set_brake_mode(19, MOTOR_BRAKE_HOLD); //Arm motor brake
      redawp();

   
}

/**
 * Runs in driver control
 */
void opcontrol() {
    // controller
    // loop to continuously update motor
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    pros::c::motor_set_brake_mode(19, MOTOR_BRAKE_HOLD);

    pros::Task intakeT(intakes);
    //pros::Task catapultT(catapult);
    pros::Task MogoT(MogoClamp);
    pros::Task StealerdeployL(deploystealer);
    pros::Task DoinkerT(Doinker);
    pros::Task StealerClampL(StealerClamp);
    pros::Task ArmT(Arm);
    pros::Task ringsorterT(ringsorter);
    while (true) {
        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        // move the chassis with curvature drive
        chassis.curvature(leftY, rightX);
        // delay to save resources
        pros::delay(10);
    }
}