int PR1 = 0;
int PR2 = 1;
int green1 = 12;
int red1 = 11;
int green2 = 10;
int red2 = 9;

int raw= 0;
int Vin= 5;
float Vout= 0;
float buffer= 0;

void setup()
{
  Serial.begin(9600);
  pinMode(green1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red2, OUTPUT);  
}


void loop()
{
  raw= analogRead(PR1);
  if(raw) 
  {
    buffer= raw * Vin;
    Vout= (buffer)/1024.0;
    buffer= (Vin/Vout) -1;
    if(Vout > .5)
    {
      digitalWrite(green1, HIGH);
      digitalWrite(red1, LOW);
    } else {
      digitalWrite(red1, HIGH);
      digitalWrite(green1, LOW);
    }
    Serial.print("Vout1: ");
    Serial.println(Vout);
  }

  raw= analogRead(PR2);
  if(raw) 
  {
    buffer= raw * Vin;
    Vout= (buffer)/1024.0;
    buffer= (Vin/Vout) -1;
    if(Vout > .5)
    {
      digitalWrite(green2, HIGH);
      digitalWrite(red2, LOW);
    } else {
      digitalWrite(red2, HIGH);
      digitalWrite(green2, LOW);
    }
    Serial.print("Vout2: ");
    Serial.println(Vout);
  }
  delay(500);
}

