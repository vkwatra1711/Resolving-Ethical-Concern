#include <GSM.h>
#define PINNUMBER ""
GSM gsmAccess;
GSM_SMS sms;
int led = 6;
int pir = 5;
int buzzer = 4;
int catchpin = 2;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pir, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(catchPin, OUTPUT);
  Serial.println("SMS Messages Sender");
  // connection state
  bool notConnected = true;

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while (notConnected) {
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  Serial.println("GSM initialized");
}

void loop()
{
  int remoteNum = 0452603505;
  char txtMsg[200] = "Rat has been trapped";
  if(digitalRead(5)== HIGH)
    {
      Serial.println("Object Detected");
      digitalWrite(led, HIGH);
      analogWrite(buzzer, 200);
      digitalWrite(catchPin, HIGH);
      sms.beginSMS(remoteNum);
      sms.print(txtMsg);
      sms.endSMS();
    } 
 else
  {
    Serial.println("No Object Detected");
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(catchPin, LOW);
  }
   delay(1000);
}
