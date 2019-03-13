#include <kipr/botball.h>
#include "camera_files.h"

#define true 0
#define false 1
/*-----------------------------------------------------------------------------------------------------------
This code starts up the camera and takes 10 pictures for the camera to analyze
*/

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

/*-----------------------------------------------------------------------------------------------------------
This code identifies the area of an object and moves toward a desirable position
*/

void find_idealic_object_size_viacamera(int channel, int object_size, int smallest_distance, int largest_distance) {
    start_camera();
    point2 center;
    printf("%i\n", get_object_area(channel, object_size));
    while (true) {
        camera_update();
        center = get_object_center(channel, object_size);
        printf("%i\n", get_object_area(channel, object_size));
        if ((get_object_area(channel, object_size) < smallest_distance) && (center.x >= 90)) {
            printf("Veering Right!\n");
            create_drive_direct(100, 90);
        }
        else if ((get_object_area(channel, object_size) < smallest_distance) && (center.x <= 90)) {
            printf("Veering Left!\n");
            create_drive_direct(90, 100);
        }
        else if ((get_object_area(channel, object_size) > largest_distance) && (center.x <= 88)) {
            printf("Moving backward!\n");
            create_drive_direct(-70, -100);
        }
        else if ((get_object_area(channel, object_size) > largest_distance) && (center.x >= 88)) {
            printf("Moving backward!\n");
            create_drive_direct(-100, -70);
        }
        else {
            printf("Idealic object size found!\n");
            create_stop();
            break;
        }
        msleep(10);
    }
}

void find_idealic_object_size_viaET(int channel, int object_size, int port, int smallest_measurement, int largest_measurement){
    start_camera();
    point2 center;
    printf("%i\n", analog(port));
    while (true) {
        camera_update();
        center = get_object_center(channel, object_size);
        printf("%i\n", analog(port));
        if ((analog(port) < smallest_measurement) && (center.x >= 90)) {
            printf("Veering Right!\n");
            create_drive_direct(100, 90);
        }
        else if ((analog(port) < smallest_measurement) && (center.x <= 90)) {
            printf("Veering Left!\n");
            create_drive_direct(90, 100);
        }
        else if ((analog(port) > largest_measurement) && (center.x <= 88)) {
            printf("Moving backward!\n");
            create_drive_direct(-70, -100);
        }
        else if ((analog(port) > largest_measurement) && (center.x >= 88)) {
            printf("Moving backward!\n");
            create_drive_direct(-100, -70);
        }
        else {
            printf("Idealic object size found!\n");
            create_stop();
            break;
        }
        msleep(10);
    }
}