#ifndef CREATE_BOTBALL_2019_ROBOT_H
#define CREATE_BOTBALL_2019_ROBOT_H

#define TRUE 1
#define FALSE 0

#define INCHES_PER_SECOND 5
#define MM_PER_INCH 25.4
#define DEGREES_PER_SECOND 8

#define TRUE 1 //Channel for while true loops
#define FALSE 0 //Channel for while true loops
#define RED 0 //Channel for camera color use
#define YELLOW 1 //Channel for camera color use
#define GREEN 2 //Channel for camera color use
#define NO_COLOR -1 //Channel for camera color use

#define ORANGE_POM_SERVO 2
#define ORANGE_POM_CLOSE 2000
#define ORANGE_POM_OPEN 0

#define LEFT_TRACK 2
#define RIGHT_TRACK 3

#define LIGHT_PORT 0
#define BLACK_LINE 2000

//Servo Movement Definitions (Units are servo steps per loop iteration)
#define NORMAL_SLOW_SERVO_SPEED  10
#define NORMAL_SERVO_SPEED 20

#define DRIVE_SPEED 150
#define NORMAL_SPEED 90

void start();
void press_a();
void forward_with_encoder(float inches, float power);
void backward_with_encoder(float inches, float power);
void spin_right_with_encoder(float degrees, float power);
void spin_left_with_encoder(float degrees, float power);
void line_follow_for_distance(int inches);
void line_follow_till_tape();
void spin_right_till_tape(int power);
void spin_left_till_tape(int power);
void forward_until_tape();
void backward_until_tape();
void servo(int port, int desired_position);
void servo_slowly(int port, int desired_position, int speed);
void collect_orange_poms();
void push_orange_poms();
void backward_till_bump(int speed);

#endif //CREATE_BOTBALL_2019_ROBOT_H
