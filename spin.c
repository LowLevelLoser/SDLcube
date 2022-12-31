#include "./macros.h"
#include "./spin.h"

#include <math.h>
#include <stdlib.h>
#include<stdio.h>


void flatten(cube_f *cube);
void translate(cube_f *cube);


void spinX(cube_f *cube){
	for(int i = 0;i < 8; i++){
		for(int j = 0; j < 3; j++){
			cube->threeD_lines_rep[i][j] = 0.0;
		}
	}

	double rotate_X[3][3] = {{cos(cube->theta_d), 0,sin(cube->theta_d)},
						  {0, 1, 0},
						  {-1*sin(cube->theta_d), 0, cos(cube->theta_d)}};

	for(int i = 0; i < LINE_NUM; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				cube->threeD_lines_rep[i][j] += cube->threeD_lines[i][k] * rotate_X[k][j];  
			}
		}
	}
	
	for(int i = 0;i < 8; i++){
		for(int j = 0; j < 3; j++){
			cube->threeD_lines[i][j] = cube->threeD_lines_rep[i][j];
		}
	}
//*/
 	flatten(cube);
}
void spinY(cube_f *cube){
	for(int i = 0;i < 8; i++){
		for(int j = 0; j < 3; j++){
			cube->threeD_lines_rep[i][j] = 0.0;
		}
	}

	double rotate_Y[3][3] = {{1, 0, 0},
					  {0, cos(cube->theta_d), -1*sin(cube->theta_d)},
					  {0, sin(cube->theta_d), cos(cube->theta_d)}};

	for(int i = 0; i < LINE_NUM; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				cube->threeD_lines_rep[i][j] += cube->threeD_lines[i][k] * rotate_Y[k][j];  
			}
		}
	}
	
	for(int i = 0;i < 8; i++){
		for(int j = 0; j < 3; j++){
			cube->threeD_lines[i][j] = cube->threeD_lines_rep[i][j];
		}
	}
//*/
 	flatten(cube);
}

void spinZ(cube_f *cube){
	for(int i = 0;i < 8; i++){
		for(int j = 0; j < 3; j++){
			cube->threeD_lines_rep[i][j] = 0.0;
		}
	}

	double rotate_Z[3][3] = {{cos(cube->theta_d), sin(cube->theta_d), 0},
					  	{ -1*sin(cube->theta_d), cos(cube->theta_d),0},
					  	{0, 0, 1}};


	for(int i = 0; i < LINE_NUM; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				cube->threeD_lines_rep[i][j] += cube->threeD_lines[i][k] * rotate_Z[k][j];  
			}
		}
	}
	
	for(int i = 0;i < 8; i++){
		for(int j = 0; j < 3; j++){
			cube->threeD_lines[i][j] = cube->threeD_lines_rep[i][j];
		}
	}
//*/
 	flatten(cube);
}

void flatten(cube_f *cube){
	for(int i = 0; i < LINE_NUM; i++){
		cube->threeD_lines[i][Z_AXIS] = roundf(cube->threeD_lines[i][Z_AXIS] * 100000.0)/100000;
		cube->threeD_lines[i][X_AXIS] = roundf(cube->threeD_lines[i][X_AXIS] * 100000.0)/100000;
		cube->threeD_lines[i][Y_AXIS] = roundf(cube->threeD_lines[i][Y_AXIS] * 100000.0)/100000;
	}

	for(int i = 0; i < LINE_NUM; i++){
		double z_divizor;
		if(cube->threeD_lines[i][Z_AXIS] < 0){
			z_divizor = (cube->threeD_lines[i][Z_AXIS]+ DISTANCE)/2;
		}
		else if(cube->threeD_lines[i][Z_AXIS] > 0){
			z_divizor = (cube->threeD_lines[i][Z_AXIS] + DISTANCE)/2;
		}
		else {z_divizor = DISTANCE/2.0;}

		printf("\nzdivizors %lf\n", z_divizor);
		cube->flat_lines[i][X_AXIS] = (cube->threeD_lines[i][X_AXIS] / z_divizor);
		cube->flat_lines[i][Y_AXIS] = (cube->threeD_lines[i][Y_AXIS] / z_divizor);

		cube->drawn_lines[i][X_AXIS] = fabs(PIXEL_LENGTH * cube->flat_lines[i][X_AXIS] - CENTER_X);
		cube->drawn_lines[i][Y_AXIS] = fabs(PIXEL_LENGTH * cube->flat_lines[i][Y_AXIS] + CENTER_Y);
	}
	for(int i = 0; i < 8; i++){
		printf("\n3D: [%lf, %lf, %lf]", cube->threeD_lines[i][X_AXIS], cube->threeD_lines[i][Y_AXIS], cube->threeD_lines[i][Z_AXIS]);
	//	printf("flat: %lf, %lf\n", cube->flat_lines[i][X_AXIS], cube->flat_lines[i][Y_AXIS]);
	//	printf("drawn: %d, %d\n", cube->drawn_lines[i][X_AXIS], cube->drawn_lines[i][Y_AXIS]);
	}//*/
	printf("\n");
}

