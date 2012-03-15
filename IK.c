#include <stdio.h>
#include <math.h>

#define EL_WR 10.794 //length between elbow and wrist.
#define SH_EL 9.525  //length between shoulder and elbo.
#define WR_END 8.5725 // length between the wrist and end effector. 

float x = 5;
float y = 3;
float z = 2;
float pi = 3.14159265;

int main ()
{
  float xt = x; //x translation
  float I = sqrt((pow(x,2))+(pow(y,2))); 
  float tn = atan(y/x);
  float x = I;
  float Z = z + WR_END;
  float c = sqrt(pow(x,2)+(pow(Z,2)));
  float j2 = acos((pow(EL_WR,2)+(pow(SH_EL,2))-(pow(c,2)))/(2*EL_WR*SH_EL));
  float theta = acos((pow(c,2)+(pow(SH_EL,2))-(pow(EL_WR,2)))/(2*SH_EL*c));
  float ang = atan(Z/x) + theta;
  float j1 = atan (Z/x) + theta;
  float x1 = SH_EL*cos(ang);
  float Z1 = SH_EL*sin(ang);
  float d = sqrt((pow((x-x1),2))+(pow((Z-WR_END-Z1),2)));
  float j3 = acos((pow(EL_WR,2)+(pow(WR_END,2))-(pow(d,2)))/(2*EL_WR*WR_END));
  float base = atan(y/xt);
  
  float theta1 = 180 / pi * j1;
  float theta2 = 180 / pi * j2;
  float theta3 = 180 / pi * j3;
  float Base = 180 / pi * base;

  float servovalue1 = 11.11 * theta1 + 500;
  float servovalue2 = 11.11 * theta2 + 500;
  float servovalue3 = 11.11 * theta3 + 500;
  float servovalue4 = 11.11 * Base + 500;

   printf("\nangle 1 %f", theta1);
   printf("\nservo 1 %f", servovalue1);
   printf("\nangle 2 %f", theta2);
   printf("\nservo 2 %f", servovalue2);
   printf("\nangle 3 %f", theta3);
   printf("\nservo 3 %f", servovalue3);
   printf("\nangle 4 %f", Base);
   printf("\nservo 4 %f", servovalue4);
   printf("\n");
}
