//assigning the integers or names
  //electrochemical sensor
    int sensorPin = A0;  
    int sensorValue = 0;  
    int percent = 0;
  //vibration sensor
    int vibr_Pin=7;
    int LED_Pin=13;

void setup() {
  Serial.begin(9600);
  //Sets up the pin 
  pinMode(vibr_Pin,INPUT);
  pinMode(LED_Pin,OUTPUT);
}


long TP_init(){
  delay(50);
      long measurement=pulseIn (vibr_Pin, HIGH);  //wait for the pin to get HIGH and returns measurement
    return measurement;
}

int convertToPercent(int value)
{
  int percentValue = 0;
      percentValue = map(value, 1023, 465, 0, 100);
    return percentValue;
}

void loop(){
  long measurement =TP_init();
  delay(50);
    // Serial.print("measurment = ");
  
            //Sets the condition for the LED of the vibration sensor  
            {if (measurement > 1000){
                digitalWrite(LED_Pin, HIGH);  //when the vib sensor produced an output greater than 1000, the LED will light on
              }
              else{
                digitalWrite(LED_Pin, LOW);  //when there is no detection, the LED is off
              }
            delay(100);
  }
  
  //prints the result of the moisture sensor
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);
  Serial.print("\nPercent: ");
  Serial.print(percent);
  Serial.print("%");
  Serial.print("\nsoilcohesiveness: ");
  Serial.print(measurement); //displays the measurement of the vibration sensor
    delay(100); //time or interval for result to be displayed
  
}