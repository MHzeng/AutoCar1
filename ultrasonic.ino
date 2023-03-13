#include"const.h"

void ultrasonic()
{

digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去 TrigPin
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);
cm = pulseIn(EchoPin, HIGH) / 58; //将回波时间换算成 cm
cm = (int(cm * 100)) / 100; //保留两位小数
if(cm<=50)
{
  avoidstatu=1;
}
}

void Avoid(void)
{
  volatile long begincnt=cnt;
  if(cnt<=begincnt+10)
  {
    motor1.target=V;
    motor2.target=-V;
  }
  if(cnt>=begincnt+11&&cnt<=begincnt+60)
  {
    motor1.target=V;
    motor2.target=V;
  }
  if(cnt>=begincnt+61&&cnt<=begincnt+80);
  {
    motor1.target=-V;
    motor2.target=V;
  }
  if(cnt>=begincnt+81)
  {
    motor1.target=V;
    motor2.target=V;
    if(digitalRead(L4)==HIGH)
    {
      motor1.target=V;
      motor2.target=-V;
      avoidstatu=0;
      detectstatu=0;
    }
  }

}