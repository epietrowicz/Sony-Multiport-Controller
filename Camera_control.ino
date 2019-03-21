
int shutter = 13; //Assign the base of the transistors to digital pins
int focus = 12;
int pwr = 11;
String command;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(shutter, OUTPUT);
  pinMode(focus, OUTPUT);      
  pinMode(pwr, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  while(Serial.available()==0){}
  command = Serial.readString();
  if (command == "pwr"){
    command = " ";
    powerOn();
  } 
  if (command == "pic"){
    command = " ";
    takeImage();
    delay(5000);
  }
}

void powerOn(){
  digitalWrite(pwr, HIGH);    //PWR pin shorts to GND.
  delay(5000);                //wait 5 seconds for the camera to turn on. 
  digitalWrite(pwr, LOW);
}

void takeImage(){
  digitalWrite(focus,HIGH);   //FOCUS pin shorts to GND.
  delay(2);
  digitalWrite(shutter,HIGH); //SHUTTER pin shorts to GND.
  delay(100);                  //Give time for camera to respond. 
  digitalWrite(focus, LOW);   
  digitalWrite(shutter, LOW); 
}

