#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3);  // RX pin, TX pin for Bluetooth module

int A = 5;    // dark green
int B = 6;
int speed = 0;

char input;     // to store input character received via BT.

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);  // Initialize Bluetooth communication
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(5, OUTPUT); // dark green 3rd and 4th motor
  pinMode(6, OUTPUT); // red 1st and 2nd motor
}

void loop()
{
  while (bluetooth.available())
  {
    input = bluetooth.read();
    Serial.println(input);
    if (input == 'F')
    {
      forward();
    }
    else if (input == 'R')
    {
      right();
    }
    else if (input == 'L')
    {
      left();
    }
    else if (input == 'G')
    {
      backward();
    }
    else if (input == 'S')
    {
      stop();
    }
  }

  speed = analogRead(A0);
  speed = map(speed, 0, 1023, 0, 255); // Map analog input range (0-1023) to PWM range (0-255)

  analogWrite(A, speed);
  analogWrite(B, speed);
}

void forward()
{
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void stop()
{
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void backward()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}

void right()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void left()
{
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
}
