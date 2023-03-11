#include"const.h"

void Stop(void)
{
  motor1.target=V;
  motor2.target=-V;
  

  motor1.target=0;
  motor2.target=0;
  PutDown();





  exit(1);
}