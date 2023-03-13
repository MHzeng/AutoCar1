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
  if(cnt>=begincnt+20&&cnt<=begincnt+100)
  {
    motor1.target=V;
    motor2.target=-V;
  }
  if(cnt==begincnt+101)
  {
    motor1.target=0;
    motor2.target=0;
  }
  if(cnt==begincnt+130)
  {
    servo2.write(135);
  }
  if(cnt==begincnt+200)
  {
    servo1.write(90);  
  }
  if(cnt>=begincnt+200)
  {
    exit(0);
  }
}