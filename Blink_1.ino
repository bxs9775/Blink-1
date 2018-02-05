//pin to recieve input from the photosensor
int analogInPin = A5;
//pin to recieve input from the switch
int digitalInPin = 7;
//two pins for sending output to the LEDs
int ledDispPin1 = 3;
int ledDispPin2 = 11;

//runs once and sets up the program
void setup() {
  // sets up pins
  pinMode(digitalInPin,INPUT);
  pinMode(ledDispPin1,OUTPUT);
  pinMode(ledDispPin2,OUTPUT);

  //initialize serial communication
  Serial.begin(9600);
}

//runs the loop code, this method is called repeatedy until the program is stopped
void loop() {
  //read the input(s)
  int switchState = digitalRead(digitalInPin);
  int anInVal = analogRead(analogInPin);
  
  //Serial.print("Switch: ");
  //Serial.print(switchState);
  //Serial.print(", Analog Value: ");
  //Serial.println(anInVal);

  //Preparing output
  int anOut1 = map(anInVal, 0, 1023, 0, 255);
  int anOut2 = 0;
  if (switchState == 0)
  {
    anOut2 = anOut1;
  }
  else
  {
    anOut2 = 255 - anOut1;
  }

  Serial.print("Out 1: ");
  Serial.print(anOut1);
  Serial.print(", Out 2: ");
  Serial.println(anOut2);
  
  //Sending values as output
  analogWrite(ledDispPin1,anOut1);
  analogWrite(ledDispPin2,anOut2);

  //Add a short delay
  delay(5);
}
