#include"const.h"

void Stop(void)
{
  motor1.target=0;
  motor2.target=0;
  stopstatu=1;
}

void End(void)
{
  long begincnt=cnt;
  int time1=20;
  int time2=80;
  int time3=30;
  int time4=70;
  if(cnt>=begincnt+time1&&cnt<=begincnt+time1+time2)
  {
    motor1.target=V;
    motor2.target=-V;
  }
  if(cnt==begincnt+time1+time2+1)
  {
    motor1.target=0;
    motor2.target=0;
  }
  if(cnt==begincnt+time1+time2+time3)
  {
    servo2.write(135);
  }
  if(cnt==begincnt+time1+time2+time3+time4)
  {
    servo1.write(90);  
  }
  if(cnt>begincnt+time1+time2+time3+time4)
  {
    exit(0);
  }
}