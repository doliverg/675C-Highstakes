#include "main.h"
using namespace pros;

const int vel = 600;
bool Mogo_state = false;
bool Doinker_state = false;
bool DeployStealer_state = false;
bool StealerClamp_state = false;
bool sort_state = false;
bool hang_state = false;
bool outtake = false;
bool intakelift_state = false;
bool intake_state = false;
bool enableAutoClamp = true;
bool AutoClampEnable = true;

int intakes() {
    while (true) {
        

         if(isRingValid() == 1) controller.set_text(0, 0, "valid");
        else if(isRingValid() == 2) controller.set_text(0, 0, "error");
        else if (isRingValid() == 0) controller.set_text(0, 0, "nothing");
        
        std::string col = std::to_string(optical_sensor.get_hue());
        controller.set_text(0, 5, col);
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            conveyer.move_velocity(600);
            colorsorter();
         
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
            conveyer.move_velocity(-600);
            

        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            conveyer.move_velocity(600);
            redirect();
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
            conveyer.move_velocity(600);

        }
        else {
            conveyer.move_velocity(0);
            //intake.move_velocity(0);
            //convey.move_velocity(0);

        }
        delay(10);
        
    }
        delay(10);
    return 1;
}

void Arm() {
    Arms.set_brake_mode(MOTOR_BRAKE_HOLD);
    while (true) {
       
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) {
        Arms.move_absolute(0,600);//-----------------------------------------------------------try 0 and -600

        }
        else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
          Arms.move_absolute(3000,600);
        }

        
    }
        delay(10);
}


void ringsorter() {
    // extends/retracts pistons when button is pressed 
    while (true) {
        if ((controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN))) {
            if (sort_state == false) {  
                sort_state = !sort_state;
                moveSorter(sort_state);
            } else if (sort_state == true) {
                sort_state = !sort_state;
                moveSorter(sort_state);
            }
            

        delay(10);
        }   
    }
}
void MogoClamp() {
    // extends/retracts pistons when button is pressed 
    while (true) {
        if ((controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))) {
            if (Mogo_state == false) {  
                Mogo_state = !Mogo_state;
                moveMogo(Mogo_state);
            } else if (Mogo_state == true) {
                Mogo_state = !Mogo_state;
                moveMogo(Mogo_state);
            }
            

           delay(10);

        }   
    }
}

//code for hang

void StealerClamp(){
    while(true){
        if((controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y))) {
            if(StealerClamp_state == false){
             StealerClamp_state = !StealerClamp_state;
                 move_Stealerclamp(StealerClamp_state);
           // hangL.set_value(true);
            }
              else if (StealerClamp_state == true) {
                 StealerClamp_state = !StealerClamp_state;
                 move_Stealerclamp(StealerClamp_state);
             }
                     delay(10);
      
            }
       // else if ((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))){
        //    hangL.set_value(false);
        }

    }
    void Doinker(){
    while(true){
        if((controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))) {
            if(Doinker_state == false){
             Doinker_state = !Doinker_state;
                 move_Doinker(Doinker_state);
           // hangL.set_value(true);
            }
              else if (Doinker_state == true) {
                 Doinker_state = !Doinker_state;
                 move_Doinker(Doinker_state);
             }
                     delay(10);
   
            }
       // else if ((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))){
        //    hangL.set_value(false);
        }

    }void deploystealer(){
    while(true){
        if((controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))) {
            if(DeployStealer_state == false){
             DeployStealer_state = !DeployStealer_state;
                 move_Stealerdeploy(DeployStealer_state);
           // hangL.set_value(true);
            }
              else if (DeployStealer_state == true) {
                 DeployStealer_state = !DeployStealer_state;
                 move_Stealerdeploy(DeployStealer_state);
             }
        delay(10);
            }
       // else if ((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))){
        //    hangL.set_value(false);
        }

    }
//code for hang


/*int AutoClampEnabler(){
    while(AutoClampEnable){
    if((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))){
    enableAutoClamp = false; //Turns off auto clamp
    pros::delay(0);
    moveMogo(false);
    }
    else if ((master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A))){
        enableAutoClamp = true;
        pros::delay(0);
        pros::Task AutoClampT(AutoClamp);
  }
    pros::delay(ez::util::DELAY_TIME); 

    }
    return 1;
}*/
/*int AutoClamp(){
  while(enableAutoClamp){
    if(distance_sensor.get() < 65){
        pros::delay(300);
      moveMogo(true);
      
    }
    /*else if(distance_sensor.get() > 60){
    moveMogo(false);
    }
    pros::delay(ez::util::DELAY_TIME); 

  }
  return 1;
}*/