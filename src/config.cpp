#include "main.h"
using namespace pros;
pros::Motor intake(10, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor convey(17, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Arms(19,pros::E_MOTOR_GEARSET_06, pros::E_MOTOR_ENCODER_DEGREES);
pros::MotorGroup conveyer({-10, 17});
pros::Distance distance_sensor(18);
pros::Optical optical_sensor(12);
pros::ADIDigitalOut MogoClampL('A');
pros::ADIDigitalOut StealerClampL('C');
pros::ADIDigitalOut StealerdeployL('B');
pros::ADIDigitalOut DoinkerL('D');
pros::ADIDigitalOut SorterL('E');