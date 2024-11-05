// controller
#include "api.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
using namespace pros;
extern Controller controller;

// drive motors
extern Motor lF;
extern Motor lM;
extern Motor lB;
extern Motor rF;
extern Motor rM;
extern Motor rB;

// motor groups
extern MotorGroup leftMotors;
extern MotorGroup rightMotors;
// Inertial Sensor on port 2
extern Imu imu;
extern lemlib::Chassis chassis;


