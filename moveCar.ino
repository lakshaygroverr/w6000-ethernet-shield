#define in1 5 //L298n Motor Driver pins.
#define in2 6
#define in3 10
#define in4 11
#define LED 13
int command; //Int to store app command state.
int Speedsec;
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED, OUTPUT); //Set the LED pin.
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); //Initialize with motors stoped.
    Serial.println(command);
    switch (command) {
      case 70:
        forward();
        break;
      case 66:
        back();
        break;
      case 76:
        left();
        break;
      case 82:
        right();
        break;
      
    }
    
  }
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
}

void back() {
  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in3, HIGH);
}

void right() {
  digitalWrite(in1, HIGH);
}
void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}



Vibration sensor
int vib_pin=7;
int led_pin=13;
void setup() {
  pinMode(vib_pin,INPUT);
  pinMode(led_pin,OUTPUT);
}

void loop() {
  int val;
  val=digitalRead(vib_pin);
  if(val==1)
  {
    digitalWrite(led_pin,HIGH);
    delay(1000);
    digitalWrite(led_pin,LOW);
    delay(1000);
   }
   else
   digitalWrite(led_pin,LOW);
}
