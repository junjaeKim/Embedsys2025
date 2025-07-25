#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include "accelMagGyro.h"
#define accel_t 500000

const double RADIAN_TO_DEGREE = 180.0 / 3.141592;

int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;
double angle_x, angle_y, angle_z;
double angle[3];


void calcAngle() // 각도 계산
{
    getAccel(angle);

    AcX = angle[0];
    AcY = angle[1];
    AcZ = angle[2];
//
    //AcX = angle[0] << 8 | angle[0];
    //AcY = angle[1] << 8 | angle[1];
    //AcZ = angle[2] << 8 | angle[2];
    
   // printf("Accel : %d %d %d \n", angle[0], angle[1], angle[2]);
   // printf("Accel : %d %d %d \n", AcX, AcY, AcZ);

    angle[1] = atan(-AcX / sqrt( pow(AcY, 2) + pow(AcZ, 2) ));
  //  printf("\nAngle x : %d , Angle y :%d \n", angle[0], angle[1]);
    angle[1] *= RADIAN_TO_DEGREE;
    angle[0] = atan(AcY/ sqrt( pow(AcX, 2) + pow(AcZ, 2) ));
  //  printf("\nAngle x : %d , Angle y :%d \n", angle[0], angle[1]);
    angle[0] *= RADIAN_TO_DEGREE; 
  //  printf("\nAngle x : %d , Angle y :%d \n", angle[0], angle[1]);
}


int main(void)
{
    int accel[3];
    int magnet[3];
    int gyro[3];
 
	getAccel(accel);
	getGyro(gyro);
	getMagnet(magnet);

	printf("I read Accel     %d, %d, %d\n", accel[0], accel[1], accel[2]);
	printf("I read Magneto   %d, %d, %d\n", magnet[0], magnet[1], magnet[2]);
	printf("I read Gyroscope %d, %d, %d\n", gyro[0], gyro[1], gyro[2]);
            return 0;
}
       
    
 
