
int DirX = A0; 
int StepX = A3; 
int Hallsensor = 7;

int Steps = 4800;
int Steptime = 1000; 
int timeout = 200;
int a, HSTime;




void setup() 
{

pinMode(DirX, OUTPUT); 
pinMode(StepX, OUTPUT);
pinMode(Hallsensor, INPUT);

  Serial.begin(115200); 
  a = 1;
}

void loop() 
{
  while(a <= Steps)
  {
    digitalWrite(DirX, HIGH);
    digitalWrite(StepX, HIGH); 
    digitalWrite(StepX, LOW);
    if(Serial.available()>0)
      {
      Serial.println(a, DEC); 
      }
    a = a + 1; 
    delayMicroseconds(Steptime);
    HSTime = pulseIn(Hallsensor, LOW, timeout); 
    if(HSTime == 0)
      {
        Steps = a; 
        Serial.println("Anschlag");
      } 
  }
}
