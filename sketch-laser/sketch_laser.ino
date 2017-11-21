int MotionDetector = 0;
int PhotoResistor1 = 1;
int PhotoResistor2 = 2;

int GreenLED1 = 12;
int RedLED1 = 11;
int GreenLED2 = 10;
int RedLED2 = 9;
int Laser1 = 5;
int Laser2 = 6;

float Threshold = 0.5;

float raw = 0;
float pr1 = 0;
float pr2 = 0;
int Vin = 5;
float Vout = 0;
float buffer = 0;

void setup()
{
  // Serial.begin(9600);
  pinMode(GreenLED1, OUTPUT);
  pinMode(RedLED1, OUTPUT);
  pinMode(GreenLED2, OUTPUT);
  pinMode(RedLED2, OUTPUT); 
  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT); 
  digitalWrite(Laser1, LOW);
  digitalWrite(Laser2, LOW);
  digitalWrite(RedLED1, LOW);      
  digitalWrite(GreenLED1, LOW);      
  digitalWrite(RedLED2, LOW);      
  digitalWrite(GreenLED2, LOW);      
}


void loop()
{
  raw = analogRead(MotionDetector);
  if (raw>0)   
  {
    /* motion detected - power up the lasers */
    digitalWrite(Laser1, HIGH);
    digitalWrite(Laser2, HIGH);
    // Serial.print("MotionDetector: ");
    // Serial.println(Vout);

    /* check first photoresistor and measure how much light is present */
    pr1 = analogRead(PhotoResistor1);   
    if (pr1>0) 
    {
      buffer= pr1 * Vin;
      Vout= (buffer)/1024.0;
      if(Vout > Threshold)
      {
        digitalWrite(GreenLED1, HIGH);
        digitalWrite(RedLED1, LOW);
      } else {
        digitalWrite(GreenLED1, LOW);
        digitalWrite(RedLED1, HIGH);
      }
    } else {
      digitalWrite(GreenLED1, LOW);
      digitalWrite(RedLED1, HIGH);
    }
    // Serial.print("Vout1: ");
    // Serial.println(Vout);


    /* check second photoresistor and measure how much light is present */
    pr2 = analogRead(PhotoResistor2);
    if (pr2>0) 
    {
      buffer= pr2 * Vin;
      Vout= (buffer)/1024.0;
      if(Vout > Threshold)
      {
        digitalWrite(GreenLED2, HIGH);
        digitalWrite(RedLED2, LOW);
      } else {
        digitalWrite(GreenLED2, LOW);
        digitalWrite(RedLED2, HIGH);
      }
    } else {
      digitalWrite(GreenLED2, LOW);
      digitalWrite(RedLED2, HIGH);
    }
    // Serial.print("Vout2: ");
    // Serial.println(Vout);
  
  } else {
    /* no motion detected - power down the lasers & LEDs */
    digitalWrite(Laser1, LOW);
    digitalWrite(Laser2, LOW);
    digitalWrite(RedLED1, LOW);      
    digitalWrite(GreenLED1, LOW);      
    digitalWrite(RedLED2, LOW);      
    digitalWrite(GreenLED2, LOW);     
  }
  delay(500);
}

