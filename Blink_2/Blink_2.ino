//pins to recieve input from the photosensors
int analogInPins[] = {A2,A3,A4,A5};
//pin to recieve input from the switch
int digitalInPin = 2;
//pins for sending output to the LEDs
int ledDispPins[] = {11,9,5,3};

//output storage
int nextOut1[] = {0,0,0,0};
int nextOut2[] = {0,0,0,0};
int nextOut3[] = {0,0,0,0};
int currOut[] = {0,0,0,0};

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
  for(int i = 0; i < 4; i++){
    currOut[i] = nextOut3[i];
    nextOut3[i] = nextOut2[i];
    nextOut2[i] = nextOut1[i];
    
    tempInVal = analogRead(analogInPins[i]);
    nextOut1[i] = map(tempInVal, 0, 1023, 0, 255);
    if (switchState == 1)
    {
      nextOut1[i] = 255 - nextOut1[i];
    }
    analogWrite(ledDispPins[i],currOut[i]);
  }

  //Add a short delay
  delay(15);
}
