#include"const.h"

void ultrasonic()
{
int cm=100;
digitalWrite(TrigPin, LOW); //低高低电平发一个短时间脉冲去 TrigPin
delayMicroseconds(2);
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);
cm = pulseIn(EchoPin, HIGH) / 58; //将回波时间换算成 cm
cm = (int(cm * 100)) / 100; //保留两位小数
if(cnt>=10)
{
if(cm<=10)
{
  avoidstatu=1;
  detectcnt=cnt;
  detectstatu=0;
}
}
// Serial.println(cm);
}

void Avoid(void)
{
  int time1=100;
  int time2=20;
  int time3=100;
  int time4=100;
  int time5=100;
  int time6=30;
  int time7=100;
  if(cnt<=detectcnt+time1)
  {
    motor1.target=0;
    motor2.target=0;
    Serial.println(1);
  }
  if(cnt>=detectcnt+time1+1&&cnt<=detectcnt+time1+time2)
  {
    motor1.target=V;
    motor2.target=-V;
    Serial.println(2);
  }
  if(cnt>=detectcnt+time1+time2+1&&cnt<=detectcnt+time1+time2+time3)
  {
    motor1.target=0;
    motor2.target=0;
    Serial.println(3);
  }
  if(cnt>=detectcnt+time1+time2+time3+1&&cnt<=detectcnt+time1+time2+time3+time4)
  {
    motor1.target=V;
    motor2.target=V;
    Serial.println(4);
  }
  if(cnt>=detectcnt+time1+time2+time3+time4+1&&cnt<=detectcnt+time1+time2+time3+time4+time5)
  {
    motor1.target=0;
    motor2.target=0;
    Serial.println(5);
  }
  if(cnt>=detectcnt+time1+time2+time3+time4+time5+1&&cnt<=detectcnt+time1+time2+time3+time4+time5+time6)
  {
    motor1.target=-V;
    motor2.target=V;
    Serial.println(6);
  }
  if(cnt>=detectcnt+time1+time2+time3+time4+time5+time6&&cnt<=detectcnt+time1+time2+time3+time4+time5+time6+time7)
  {
    motor1.target=0;
    motor2.target=0;
    Serial.println(7);
  }
  if(cnt>=detectcnt+time1+time2+time3+time4+time5+time6+time7+1)
  {
    motor1.target=V;
    motor2.target=V;
    if(digitalRead(L4)==HIGH)
    {
      motor1.target=V;
      motor2.target=-V;
      avoidstatu=0;
    }
    Serial.println(8);
  }

}