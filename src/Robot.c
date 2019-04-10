#include <kipr/botball.h>
#include "../include/Robot.h"

int TOGGLE=FALSE;
void start_camera() {
    int k;

    printf("Initializing the camera...\n");
    camera_open();
    for (k = 0; k < 10; k = k + 1) {
        printf("  Taking a picture...\n");
        camera_update();
    }
    printf("  Initializing the camera is DONE!\n");
}

void start(){
    printf("Trying connect to the create\n");
    //create_connect();
    printf("Connected to the create\n");
    //set_servo_position(ORANGE_POM_SERVO, ORANGE_POM_OPEN);
    wait_for_light(LIGHT_PORT);
    shut_down_in(119);
    //enable_servo(ORANGE_POM_SERVO);
}

//This function uses the A button to continue program
void press_a(){
    if(TOGGLE==TRUE){
        printf("Press A to continue\n");
        while (TRUE){
        	if (a_button() == 1){
            	printf("Hands-off\n");
            	msleep(1000);
            	break;
        	}
        	msleep(10);
    	}
   }else {
        msleep(500);
    }
}

//This function uses encoders to drive the Create forward
void forward_with_encoder(float inches, float power){
    set_create_distance(0);
    int distance_in_MM = inches * MM_PER_INCH;
    while(TRUE){
        if(get_create_distance() <= distance_in_MM){
            create_drive_direct(.8*power, power);
            //printf("Inches Traveld: %0.2f\n", get_create_distance()/MM_PER_INCH);
        }
        else{
            create_stop();
            break;
        }
        msleep(20);
    }
    printf("Inches Traveled: %0.2f\n", get_create_distance()/MM_PER_INCH);
    press_a();
}

//This function uses encoders to drive the Create backward
void backward_with_encoder(float inches, float power){
    set_create_distance(0);
    int distance_in_MM = inches * MM_PER_INCH;
    while(TRUE){
        if(-get_create_distance() <= distance_in_MM){
            create_drive_direct(-.8*power, -power);
            //printf("Inches Traveld: %0.2f\n", get_create_distance()/MM_PER_INCH);
        }
        else{
            create_stop();
            break;
        }
        msleep(20);
    }
    printf("Inches Traveled: %0.2f\n", get_create_distance()/MM_PER_INCH);
    press_a();
}

//This function spins the creat right X degrees using encoders
void spin_right_with_encoder(float degrees, float power){
    int TURNED;
    set_create_total_angle(0);
    create_spin_CW(power);
    while(TRUE){
        TURNED = -get_create_total_angle();
        if(TURNED >= degrees){
            create_stop();
            break;
        }
        msleep(20);
    }
    printf("Degrees Traveld: %d\n", TURNED);
    press_a();
}

//This function spins the creat left X degrees using encoders
void spin_left_with_encoder(float degrees, float power){
    int TURNED;
    set_create_total_angle(0);
    create_spin_CCW(power);
    while(TRUE){
        TURNED = get_create_total_angle();
        if(TURNED >= degrees){
            create_stop();
            break;
        }
        msleep(20);
    }
    printf("Degrees Traveld: %d\n", TURNED);
    press_a();
}

//This function will spin the creat right until it sees a black line
void spin_right_till_tape(int power){
    int right;
    int left;
    while(TRUE){
        right = get_create_rfcliff_amt();
        left = get_create_lfcliff_amt();
        if(left >= BLACK_LINE){
            create_spin_CW(power);
            printf("Searching for line, Left: %d Right: %d\n", left, right);
        }
        else{
            create_stop();
            printf("I found the line, Left: %d Right: %d\n", left, right);
            break;
        }
        msleep(20);
    }
}

//This function will spin the creat right until it sees a black line
void spin_left_till_tape(int power){
    int left;
    int right;
    while(TRUE){
        right = get_create_rfcliff_amt();
        left = get_create_lfcliff_amt();
        if(right >= BLACK_LINE){
            create_spin_CCW(power);
            printf("I found the line, Left: %d Right: %d\n", left, right);
        }
        else{
            create_stop();
            break;
        }
        msleep(20);
    }
}

//This function drive the create forward until it sees the line
void forward_until_tape(){
    int left;
    int right;

    while(TRUE){
        left = get_create_lfcliff_amt();
        right = get_create_rfcliff_amt();

        create_drive_direct(100, 100);

        if(left <= BLACK_LINE || right <= BLACK_LINE){
            printf("I found the line, Left: %d Right: %d\n", left, right);
            create_stop();
            break;
        }
        msleep(20);
    }
}

//This function drive the create backward until it sees the line
void backward_until_tape(){
    int left;
    int right;

    while(TRUE){
        left = get_create_lfcliff_amt();
        right = get_create_rfcliff_amt();

        create_drive_direct(-100, -100);

        if(left <= BLACK_LINE || right <= BLACK_LINE){
            printf("I found the line, Left: %d Right: %d\n", left, right);
            create_stop();
            break;
        }
        msleep(20);
    }
}

//This function will follow(avoid) the black line for X inches
void line_follow_for_distance(int inches){
    int left;
    int right;
    int distance_in_MM = inches * MM_PER_INCH;
    set_create_distance(0);
    printf("Ready to follow line/n");
    while(get_create_distance() <= distance_in_MM)
    {
        left = get_create_lfcliff_amt();
        right = get_create_rfcliff_amt();

        if(left >= BLACK_LINE && right >= BLACK_LINE){
            printf("Going Straight, Left: %d Right: %d\n", left, right);
            create_drive_direct(200, 200);

        }
        else if(left <= BLACK_LINE && right >= BLACK_LINE){
            printf("Going Left, Left: %d Right: %d\n", left, right);
            create_drive_direct(75, 200);

        }
        else if(left >= BLACK_LINE && right <= BLACK_LINE){
            printf("Going Right, Left: %d Right: %d\n", left, right);
            create_drive_direct(200, 75);

        }

        else if(left <= BLACK_LINE && right <= BLACK_LINE){
            printf("I'm not stradling the tape anymore!!!!, Left: %d Right: %d\n", left, right);
            spin_left_with_encoder(3, 50);

        }
        msleep(20);
    }
    create_stop();
}

//This function will follow tape line until it crosses another tape line
void line_follow_till_tape(){
    int left;
    int right;
    printf("Ready to follow line/n");
    while(TRUE)
    {
        left = get_create_lfcliff_amt();
        right = get_create_rfcliff_amt();

        if(left >= BLACK_LINE && right >= BLACK_LINE){
            printf("Going Straight, Left: %d Right: %d\n", left, right);
            create_drive_direct(200, 200);

        }
        else if(left <= BLACK_LINE && right >= BLACK_LINE){
            printf("Going Left, Left: %d Right: %d\n", left, right);
            create_drive_direct(75, 200);

        }
        else if(left >= BLACK_LINE && right <= BLACK_LINE){
            printf("Going Right, Left: %d Right: %d\n", left, right);
            create_drive_direct(200, 75);

        }

        else if(left <= BLACK_LINE && right <= BLACK_LINE){
            printf("I have crossed another black line, Left: %d Right: %d\n", left, right);
            create_stop();
            break;
        }
        msleep(20);
    }
}

//This function will move a servo SLOWLY to its desired position.
void servo(int port, int desired_position)
{
    servo_slowly(port, desired_position, NORMAL_SERVO_SPEED);
}

// Speed is servo units to move each time through the loop.
void servo_slowly(int port, int desired_position, int speed)
{
    int position;
    int step = speed;

    enable_servo(port);

    if (get_servo_position(port) > desired_position)
    {
        while (TRUE)
        {
            position = get_servo_position(port);
            if (position <= desired_position + step)
            {
                break;
            }
            set_servo_position(port, position - step);
            msleep (50);
        }

    } else
    {
        while (TRUE)
        {
            position = get_servo_position(port);
            if (position >= desired_position - step)
            {
                break;
            }
            set_servo_position(port, position + step);
            msleep (50);
        }
    }
    msleep(50);
    set_servo_position(port, desired_position);
    msleep(50);
}

//This function will drive the create backward until it hits the bump sensor
void backward_till_bump(int speed){
    create_drive_straight(speed);
    while(TRUE){
        if(get_create_lbump() || get_create_rbump()){
            create_stop();
            break;
        }
        msleep(20);
    }
}
