#include "./macros.h"
#include "./spin.h"

#include <math.h>
#include <stdlib.h>
#include<stdio.h>


void flatten(cube_f *cube);
void translate(cube_f *cube);

void spin(cube_f *cube, enum rotation_t rotation){
	for(int i = 0;i < 8; i++){
		for(int j = 0; j < 3; j++){
			cube->threeD_lines_rep[i][j] = 0.0;
		}
	}

    double rotation_matrix[6][3][3] = {
        {
            {COS_T, 0,N_SIN},
            {0, 1, 0},
			{SIN_T, 0, COS_T}
        },
        {
            {COS_T, 0,SIN_T},
            {0, 1, 0},
			{N_SIN, 0, COS_T}
        },
        {
            {COS_T, N_SIN, 0},
            {SIN_T, COS_T, 0},
            {0, 0, 1},
        },
        {
            {COS_T, SIN_T, 0},
            {N_SIN, COS_T, 0},
            {0, 0, 1},
        },
        {
            {1, 0, 0},
            {0, COS_T, N_SIN},
            {0, SIN_T, COS_T}
        },
        {
            {1, 0, 0},
            {0, COS_T, SIN_T},
            {0, N_SIN, COS_T}
        },
    };

	for(int i = 0; i < LINE_NUM; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				cube->threeD_lines_rep[i][j] += cube->threeD_lines[i][k] * rotation_matrix[rotation][2-j][2-k];
			}
		}
	}
	
	for(int i = 0;i < 8; i++){
		for(int j = 0; j < 3; j++){
			cube->threeD_lines[i][j] = cube->threeD_lines_rep[i][j];
		}
    }

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
		if(cube->threeD_lines[i][Z_AXIS] == 0){
            z_divizor = DISTANCE/2.0;
		}
		else{
			z_divizor = (cube->threeD_lines[i][Z_AXIS] + DISTANCE)/2;
		}

		printf("\nzdivizors %lf\n", z_divizor);
		cube->flat_lines[i][X_AXIS] = (cube->threeD_lines[i][X_AXIS] / z_divizor);
		cube->flat_lines[i][Y_AXIS] = (cube->threeD_lines[i][Y_AXIS] / z_divizor);

		cube->drawn_lines[i][X_AXIS] = fabs(PIXEL_LENGTH * cube->flat_lines[i][X_AXIS] - CENTER_X);
		cube->drawn_lines[i][Y_AXIS] = fabs(PIXEL_LENGTH * cube->flat_lines[i][Y_AXIS] + CENTER_Y);
	}
	for(int i = 0; i < 8; i++){
		printf("\n3D: [%lf, %lf, %lf]", cube->threeD_lines[i][X_AXIS], cube->threeD_lines[i][Y_AXIS], cube->threeD_lines[i][Z_AXIS]);
	}
	printf("\n");
}

