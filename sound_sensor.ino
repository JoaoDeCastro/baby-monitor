/*
 * Joao Decastro
 * 
 * Testing and using sound sensor and tuning on LED when MAX_SOUND is reached
 * 
 */

/* 
 *  variables and constants declaration
*/


const int SAMPLE_TIME = 10; // every 10 miliseconds its taking a sample
unsigned long currentMilli; // to hold the value of the current millisecond - unsigned since dont need negative values
unsigned long lastMilli = 0; // to hold the last milliseconds reading
unsigned long elapsedMilli = 0; // to hold how much time has past

const short GREEN_LED = 3; // green led at pin digital output 3
const short SENSOR_PIN = 8; // sensor at pin 8
const int MAX_SOUND = 200; // threshhold of sound

int sampleBufferValue = 0; // the amount of ones in a sample

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  currentMilli = millis(); // getting current milisencond
  elapsedMilli = currentMilli - lastMilli; // calculating how much time has passed

// test if the is a sound in the sample time increase samplebuffer
  if(digitalRead(SENSOR_PIN) == LOW)
  {
    sampleBufferValue++;
  }

// tests if the elpsed time reached 10 miliseconds and print
  if (elapsedMilli > SAMPLE_TIME)
  {
    Serial.println(sampleBufferValue);
    sampleBufferValue = 0;
    lastMilli = currentMilli;
  }

// tests if the sample value is greater then the threshold turn on lights
  if( sampleBufferValue > MAX_SOUND)
  {
    digitalWrite(GREEN_LED, HIGH);
    //delay(100);
    digitalWrite(GREEN_LED, LOW);
  
  }

}
