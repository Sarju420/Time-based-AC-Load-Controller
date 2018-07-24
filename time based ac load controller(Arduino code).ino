int segA = 13; //Display pin A
int segB = 12; //Display pin b
int segC = 11; //Display pin c
int segD = 10; //Display pin d
int segE = 9; //Display pin e
int segF = 8; //Display pin f
int segG = 7; //Display pin g

int digit1 = 2;
int digit2 = 3;
int digit3 = 4;
int digit4 = 5;

int btn1 = A0;
int btn2 = A1;
int btn3 = A2;

int Hour = 0;
int Minute = 0;
int second=0;
int millisecond=0;

int HourOnes = 0;
int HourTens = 0;

int MinuteOnes = 0;
int MinuteTens = 0;

int timerMinute = 0;
int timerHour = 0;

int feededTime = 0;
int timerTime = 0;

int timerHourOnes = 0;
int timerHourTens = 0;

int timerMinuteOnes = 0;
int timerMinuteTens = 0;

int  value1 =0;
int  value2 =0;
int  Start = 0;

int a = 80;
float d = 0.5;

int OFF=0;
int ON=1;
int Motor=6;

void setup()
{
  Serial.begin(9600);
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);

  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);

  pinMode(Motor,OUTPUT);
}

void segementNumber(int num)
{
  switch (num)
  {
    case 0:
      //0
      digitalWrite(segA, 1);
      digitalWrite(segB, 1);
      digitalWrite(segC, 1);
      digitalWrite(segD, 1);
      digitalWrite(segE, 1);
      digitalWrite(segF, 1);
      digitalWrite(segG, 0);
      //delay(1000);
      break;

    case 1:
      //1
      digitalWrite(segA, 0);
      digitalWrite(segB, 1);
      digitalWrite(segC, 1);
      digitalWrite(segD, 0);
      digitalWrite(segE, 0);
      digitalWrite(segF, 0);
      digitalWrite(segG, 0);
      //delay(1000);
      break;

    case 2:
      //2
      digitalWrite(segA, 1);
      digitalWrite(segB, 1);
      digitalWrite(segC, 0);
      digitalWrite(segD, 1);
      digitalWrite(segE, 1);
      digitalWrite(segF, 0);
      digitalWrite(segG, 1);
      //delay(1000);
      break;

    case 3:
      //3
      digitalWrite(segA, 1);
      digitalWrite(segB, 1);
      digitalWrite(segC, 1);
      digitalWrite(segD, 1);
      digitalWrite(segE, 0);
      digitalWrite(segF, 0);
      digitalWrite(segG, 1);
      //delay(1000);
      break;

    case 4:
      //4
      digitalWrite(segA, 0);
      digitalWrite(segB, 1);
      digitalWrite(segC, 1);
      digitalWrite(segD, 0);
      digitalWrite(segE, 0);
      digitalWrite(segF, 1);
      digitalWrite(segG, 1);
      //delay(1000);
      break;

    case 5:
      //5
      digitalWrite(segA, 1);
      digitalWrite(segB, 0);
      digitalWrite(segC, 1);
      digitalWrite(segD, 1);
      digitalWrite(segE, 0);
      digitalWrite(segF, 1);
      digitalWrite(segG, 1);
      //delay(1000);
      break;

    case 6:
      //6
      digitalWrite(segA, 1);
      digitalWrite(segB, 0);
      digitalWrite(segC, 1);
      digitalWrite(segD, 1);
      digitalWrite(segE, 1);
      digitalWrite(segF, 1);
      digitalWrite(segG, 1);
      //delay(1000);
      break;

    case 7:
      //7
      digitalWrite(segA, 1);
      digitalWrite(segB, 1);
      digitalWrite(segC, 1);
      digitalWrite(segD, 0);
      digitalWrite(segE, 0);
      digitalWrite(segF, 0);
      digitalWrite(segG, 0);
      //delay(1000);
      break;

    case 8:
      //8
      digitalWrite(segA, 1);
      digitalWrite(segB, 1);
      digitalWrite(segC, 1);
      digitalWrite(segD, 1);
      digitalWrite(segE, 1);
      digitalWrite(segF, 1);
      digitalWrite(segG, 1);
      //delay(1000);
      break;

    case 9:
      //9
      digitalWrite(segA, 1);
      digitalWrite(segB, 1);
      digitalWrite(segC, 1);
      digitalWrite(segD, 1);
      digitalWrite(segE, 0);
      digitalWrite(segF, 1);
      digitalWrite(segG, 1);
      //delay(1000);
      break;
  }
}

void digit(int digitNum)
{
  switch (digitNum)
  {
    case 1:
      digitalWrite(digit1, LOW);
      break;

    case 2:
      digitalWrite(digit2, LOW);
      break;

    case 3:
      digitalWrite(digit3, LOW);
      break;

    case 4:
      digitalWrite(digit4, LOW);
      break;
  }
}

void Display(int digitNumber, int digitValue)
{
  int p = a;
  switch (digitNumber)
  {
    case 1:
      while (p > 0)
      {
        digitalWrite(digit2, HIGH);
        digitalWrite(digit3, HIGH);
        digitalWrite(digit4, HIGH);
        digit(1);
        segementNumber(digitValue);
        p--;
      }
      delay(d);
      break;

    case 2:
      while (p > 0)
      {
        digitalWrite(digit1, HIGH);
        digitalWrite(digit3, HIGH);
        digitalWrite(digit4, HIGH);
        digit(2);
        segementNumber(digitValue);
        p--;
      }
      delay(d);
      break;

    case 3:
      while (p > 0)
      {
        digitalWrite(digit1, HIGH);
        digitalWrite(digit2, HIGH);
        digitalWrite(digit4, HIGH);
        digit(3);
        segementNumber(digitValue);
        p--;
      }
      delay(d);
      break;


    case 4:
      while (p > 0)
      {
        digitalWrite(digit1, HIGH);
        digitalWrite(digit2, HIGH);
        digitalWrite(digit3, HIGH);
        digit(4);
        segementNumber(digitValue);
        p--;
      }
      delay(d);
      break;
  }
}

void loop()
{
  
  //---------------------------timer Feeder-----------------------------
  
  value1 = digitalRead(btn1);
  if (value1 == 1)
  {
    Hour = Hour + 1;
    if (Hour == 13)
    {
      Hour = 1;
    }
  }

  value2 = digitalRead(btn2);
  if (value2 == 1)
  {
    Minute = Minute + 1;
    if (Minute == 60)
    {
      Minute = 0;
      Hour = Hour + 1;
      if (Hour == 13)
      {
        Hour = 1;
      }
    }
  }
  if (Start ==0)
  {
    digitalWrite(Motor,OFF);
    HourOnes = (Hour % 10);
    HourTens = (Hour / 10) % 10;

    Display(1, HourTens);
    Display(2, HourOnes);

    MinuteOnes = Minute % 10;
    MinuteTens = (Minute / 10) % 10;

    Display(3, MinuteTens);
    Display(4, MinuteOnes);
  }
  //----------------=========Feeder end----------------------

  int feededTime = (HourTens * 1000) + (HourOnes * 100) + (MinuteTens * 10) + MinuteOnes;

  timerTime = (timerHourTens * 1000) + (timerHourOnes * 100) + (timerMinuteTens * 10) + timerMinuteOnes;

  Serial.print("  Value1  ");
  Serial.print(value1);
  Serial.print("  Value2  ");
  Serial.print(value2);
  Serial.print("  FeededTiime  ");
  Serial.print(HourTens * 10 + HourOnes );
  Serial.print(":");
  Serial.print(MinuteTens * 10+ MinuteOnes);

  Serial.print("  Timer  ");
  Serial.print((timerHourTens * 10) + timerHourOnes);
  Serial.print(":");
  Serial.print((timerMinuteTens * 10) + timerMinuteOnes);

  Start = digitalRead(btn3);
  Serial.print("  Start  ");
  Serial.println(Start);

  //===============================Timer=====================================

  if (feededTime == timerTime)
  {
    digitalWrite(Motor,OFF);
    Display(1, timerHourTens);
    Display(2, timerHourOnes);
    Display(3, timerMinuteTens);
    Display(4, timerMinuteOnes);
    
  }

  else if (Start == 1 && feededTime != timerTime)
  {
    digitalWrite(Motor,ON);
    
    second=0;
    if(millisecond!=1367)
    {
      second=second+millisecond;
    }
    while(second<1367&&Start==1)
    {
      Serial.print("  second  ");
      Serial.print(second);
      Serial.print("  Start  ");
      Serial.println(Start);
      Display(1, timerHourTens);
      Display(2, timerHourOnes);
      Display(3, timerMinuteTens);
      Display(4, timerMinuteOnes);
      Start = digitalRead(btn3);
      second++;
      millisecond=second;
    }
        

    if(millisecond==1367)
    {
      timerMinute = timerMinute + 1;  
    }
  
    if (timerMinute == 60)
    {
      timerMinute = 0;
      timerHour = timerHour + 1;
      if (timerHour == 13)
      {
        timerHour = 1;
      }
    }
 
    timerMinuteOnes = (timerMinute % 10);
    timerMinuteTens = (timerMinute / 10) % 10;

    timerHourOnes = timerHour % 10;
    timerHourTens = timerHour / 10 % 10;

       
  }
  
}
