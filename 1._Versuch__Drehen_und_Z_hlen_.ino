int SpR=1200;
int DirX=A0; 
int StepX=A3; 
int DT = 10; 
int a; 




void setup() 
{

pinMode(DirX, OUTPUT); 
pinMode(StepX, OUTPUT);

  Serial.begin(115200); 
  a = 1;
}

void loop() 
{
  while(a <= SpR)
  {
  digitalWrite(DirX, HIGH);
  digitalWrite(StepX, HIGH); 
  digitalWrite(StepX, LOW);
  Serial.println(a, DEC); 
  a = a + 1; 
  delayMicroseconds(DT);
  } 
}

