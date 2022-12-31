#ifndef MACROS_H_
#define MACROS_H_

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

#define CENTER_X SCREEN_WIDTH/2.0
#define CENTER_Y SCREEN_HEIGHT/2.0
#define LINE_NUM 8
#define PIXEL_LENGTH 600
#define DISTANCE 6

#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2

#define PI_M 3.14159265358979323846

typedef struct{
	double threeD_lines[LINE_NUM][3]; //assume center of the screen is 0,0
	double threeD_lines_rep[LINE_NUM][3];
	double flat_lines[LINE_NUM][2];

	int drawn_lines[LINE_NUM][2];

	float theta_d;
	float theta_b;

	float x_transform[3][3];
	float y_transform[3][3];
	float z_transform[3][3];

} cube_f;

#endif // MACROS_H_

