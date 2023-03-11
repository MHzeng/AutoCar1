#include"const.h"

void CatchUp()
{
  servo2.write(90);
  delay(1000);
  servo1.write(55);
  delay(1000);
}

void PutDown()
{
  servo2.write(135);
  delay(1000);
  servo1.write(90);  
  delay(1000);
}