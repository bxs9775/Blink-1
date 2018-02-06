//pins to recieve input from the photosensors
int analogInPins[] = {A2,A3,A4,A5};
//pin to recieve input from the switch
int digitalInPin = 2;
//pins for sending output to the LEDs
int ledDispPins[] = {11,9,5,3};

//runs once and sets up the program
void setup() {
  // sets up pins
  pinMode(digitalInPin,INPUT);
  for(int i = 0; i < 4; i++){
    pinMode(ledDispPins[i],OUTPUT);
  }

  //initialize serial communication
  Serial.begin(9600);
}

//runs the loop code, this method is called repeatedy until the program is stopped
void loop() {
  //read the input(s)
  int switchState = digitalRead(digitalInPin);

  //output processing
  int tempInVal = 0;
  int outVal = 0;
  for(int i = 0; i < 4; i++){
    tempInVal = analogRead(analogInPins[i]);
    outVal = map(tempInVal, 0, 1023, 0, 255);
    if (switchState == 1)
    {
      outVal = 255 - outVal;
    }
    analogWrite(ledDispPins[i],outVal);
  }

  //Add a short delay
  delay(5);
}
