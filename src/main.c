//This is the Ada Lovelace team's testing programs.

//Temporary Placement of defines
#define lift 0
#define claw 1
#define sweeper 3

#define lift_up 1065
#define lift_down 0

#define claw_open 1470
#define claw_close 556

//Included Libraries:
#include <kipr/botball.h>
#include "create_library.h"
#include "variables.h"

//Functions
void grabbing_botguy();
void start();
void stop();

int main()
{
    start();
    grabbing_botguy();
    stop();
    return 0;
}

void start() {
    create_connect();
    printf("blue\n");
}

void stop() {
    create_stop();
    create_disconnect();
}

void grabbing_botguy() {
    enable_servo(claw);
    enable_servo(lift);
    servo(lift, lift_up);
    msleep(1000);
    servo(claw, claw_open);
    msleep(1000);
    create_drive_direct(70, 70);
    msleep(8000);
    create_stop();
    servo(claw, claw_close);
    msleep(1000);
    create_drive_direct(-70, -70);
    msleep(3000);
    create_stop();
    servo(lift, lift_down);
    msleep(1000);
    servo(claw, claw_open);
    msleep(1000);
    create_stop();
}
