#include <kipr/botball.h>
#include "../include/Robot.h"
#include "2019-Defines.h"
extern int TOGGLE;


#define yellow 0
#define blue 1

#define LARGEST 0

#define lift 0
#define claw 1
#define sweeper 3

//Reconfigure every measurement of defines under this comment
#define lift_up 700
#define lift_up_2 250
#define lift_up_smaller_tower 1100
#define lift_up_smaller_tower_2 250

#define lift_down 0
#define lift_down_other 1500
#define lift_down_3 1754

#define claw_open 1200
#define claw_close 170
#define claw_start 2000

#define sweeper_close 10

void right_tower();
void middle_tower();
void left_tower();

void left_right();
void left_middle();                                                                                                                                               
void middle_right();

void all_towers();

void large_water();

void find_fire();

int main() //Calls all functiones
{
    //TOGGLE=TRUE;
    TOGGLE=FALSE;
    create_connect();
    set_servo_position(lift, lift_down);
    set_servo_position(claw, claw_start);
    set_servo_position(sweeper, sweeper_close);
    start();
    enable_servos();
    create_full();
    press_a();
    msleep(1000);
    //find_fire();
    //left_middle();
    //left_right();
    //middle_right();
    all_towers();
    //large_water();
    printf("Hoi\n");
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

void left_right() {
    //try switching the mayor and botguy
    enable_servos();
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(96, NORMAL_SPEED);
    forward_with_encoder(23, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(8, NORMAL_SPEED);
    spin_right_with_encoder(153, NORMAL_SPEED);
    backward_with_encoder(2, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    //add printfs
    servo(lift, lift_down);
    //''
    spin_left_with_encoder(45, 90); 
    forward_with_encoder(32, 90); 
    spin_left_with_encoder(101, 90);
    forward_with_encoder(6.5, 90); //
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(2, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_left_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(6, NORMAL_SPEED);
    spin_left_with_encoder(5, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_down);
}

void left_middle() {
    //TOGGLE=TRUE;
    enable_servos();
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(101, NORMAL_SPEED);
    forward_with_encoder(22.5, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10.5, NORMAL_SPEED);
    spin_right_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open); 
    servo(lift, lift_up);
    spin_left_with_encoder(48, NORMAL_SPEED);
    forward_with_encoder(16, NORMAL_SPEED);
    spin_left_with_encoder(90, NORMAL_SPEED); //changed right to left
    forward_with_encoder(14, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(200, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_up);
}

void middle_right() {
    //TOGGLE=TRUE;
    enable_servos();
    servo(lift, lift_up);
    msleep(20000);
    backward_with_encoder(6, NORMAL_SPEED);
    spin_right_with_encoder(90, NORMAL_SPEED);
    forward_with_encoder(28, NORMAL_SPEED);   
    servo(claw, claw_close);
    msleep(500);
    servo(lift, lift_up_2);
    backward_with_encoder(10.5, NORMAL_SPEED);
    spin_right_with_encoder(200, NORMAL_SPEED);
    servo(lift, lift_down_3);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(claw, claw_open);
    servo(lift, lift_up);
    spin_left_with_encoder(90, NORMAL_SPEED);
    forward_with_encoder(14, NORMAL_SPEED);
    spin_left_with_encoder(100, NORMAL_SPEED);
    forward_with_encoder(2, NORMAL_SPEED);
    servo(lift, lift_up_smaller_tower);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_left_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_down);
}

void all_towers() {
    enable_servos();
    servo(lift, lift_up_smaller_tower);
    forward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(98, NORMAL_SPEED);
    forward_with_encoder(22.5, NORMAL_SPEED);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10.5, NORMAL_SPEED);
    spin_right_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open); 
    servo(lift, lift_up);
    spin_left_with_encoder(48, NORMAL_SPEED);
    forward_with_encoder(16, NORMAL_SPEED);
    spin_left_with_encoder(85, NORMAL_SPEED); //changed right to left
    forward_with_encoder(14, NORMAL_SPEED);
    servo(claw, claw_close);
    msleep(1000);
    servo(lift, lift_up_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_right_with_encoder(200, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_open);
    servo(lift, lift_up);
    spin_left_with_encoder(90, NORMAL_SPEED);
    forward_with_encoder(14, NORMAL_SPEED);
    spin_left_with_encoder(105, NORMAL_SPEED);
    forward_with_encoder(2.5, NORMAL_SPEED);
    servo(lift, lift_up_smaller_tower);
    servo(claw, claw_close);
    servo(lift, lift_up_smaller_tower_2);
    backward_with_encoder(10, NORMAL_SPEED);
    spin_left_with_encoder(140, NORMAL_SPEED);
    backward_with_encoder(7, NORMAL_SPEED);
    servo(lift, lift_down_3);
    forward_with_encoder(4, NORMAL_SPEED);
    servo(claw, claw_open);
    servo(lift, lift_down);
    //
    spin_right_with_encoder(43, NORMAL_SPEED);
    forward_with_encoder(36, NORMAL_SPEED);
    spin_left_with_encoder(62.5, NORMAL_SPEED);
    forward_with_encoder(3, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_close);
    servo(lift, lift_up);
    backward_with_encoder(7, NORMAL_SPEED);
    spin_right_with_encoder(162, NORMAL_SPEED);
    servo(lift, lift_up_smaller_tower);
}

void large_water() {
    forward_with_encoder(6, NORMAL_SPEED);
    servo(lift, lift_down_3);
    servo(claw, claw_close);
    servo(lift, lift_up);
    backward_with_encoder(6, NORMAL_SPEED);
}

void find_fire() {
    start_camera();
    point2 center;
    camera_update();
    while(get_object_count(yellow) >= 1) {
        printf("Object found!\n");
        msleep(100);
        break;
    }
    printf("hello\n");
    center = get_object_center(yellow, LARGEST);
    printf("%d\n", center.x);



    //Left tower x = 38-44
    //Middle tower x = 50-66
    //Right tower x = 72-78

    if (center.x >= 48 && center.x <= 68) {
        printf("Left tower, right tower\n");
        left_right();
        //large_water();
        msleep(100);
    }
    else if (center.x <= 48) {
        printf("Middle tower, right tower\n");
        middle_right();
        //large_water();
        msleep(100);
    }
    else {
        printf("Left tower, middle tower\n");
        left_middle();
        //large_water();
        msleep(100);
    }
    msleep(100);
}

