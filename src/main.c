#include <kipr/botball.h>
#include "../include/Robot.h"


#define lift 0
#define claw 1
#define sweeper 3

#define lift_up 980
#define lift_up_2 650
#define lift_up_smaller_tower 1325
#define lift_up_smaller_tower_2 1100
#define lift_down 0
#define lift_down_other 1700

#define claw_open 1470
#define claw_close 556
#define claw_start 2000

#define sweeper_close 10

void right_tower();
void middle_tower();
void left_tower();

int main() //Calls all functions
{
    create_connect();
    set_servo_position(lift, lift_down);
    set_servo_position(claw, claw_start);
    set_servo_position(sweeper, sweeper_close);
    enable_servos();
    middle_tower();
    disable_servos();
    create_stop();
    create_disconnect();
    return 0;
}

void right_tower() {
    servo(lift, lift_up_smaller_tower);
    backward_with_encoder(18, NORMAL_SPEED);
    spin_right_with_encoder(98, NORMAL_SPEED);
    forward_with_encoder(33, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(180, NORMAL_SPEED);
    servo(lift, lift_down);
    servo(claw, claw_open);
}

void middle_tower() {
    //change last lift_down to lowest other way
    enable_servos();
    servo(lift, lift_up);
    backward_with_encoder(6, NORMAL_SPEED);
    spin_right_with_encoder(98, NORMAL_SPEED);
    forward_with_encoder(32, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(200, NORMAL_SPEED);
    servo(lift, lift_down_other);
    servo(claw, claw_open);
    servo(lift, lift_up);
    //Right Tower
    spin_left_with_encoder(90, 90);
    forward_with_encoder(12, 90);
    spin_left_with_encoder(100, 90);
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(1, 90);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_left_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_other);
    servo(claw, claw_open);
    servo(lift, lift_down);
}

void left_tower(){
    enable_servos();
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(101, NORMAL_SPEED);
    forward_with_encoder(22, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_other);
    servo(claw, claw_open);
    servo(lift, lift_down);
}
