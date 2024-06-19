#include <Servo.h>
Servo myservo_1;     // motor 1
Servo myservo_2;     // motor 2
const int buttonPin = 2; // Pin where the button is connected
int buttonState = 0;     // Variable for reading the button status
boolean flag = true;    // Define the flag and initialize it to false

void setup() {
  myservo_1.attach(9);    // motor 1
  myservo_2.attach(10);   // motor 2
  // Serial.begin(9600);
  pinMode(buttonPin, INPUT); // Initialize the button pin as an input

  myservo_1.write(90); // move servos to center position -> 90°
  myservo_2.write(70); // move servos to center position -> 90°
  delay(500);
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the state of the button
  // Serial.println(buttonState);
  if (buttonState == HIGH) { // If the button is pressed
    flag = !flag;            // Reverse the flag
    delay(500);              // Debounce delay to prevent multiple toggles
  }

  // Use the flag in your logic
  if (flag == true && buttonState == true) {
      Serial.println("Flag is true");
      // step 1: 90, 80
      myservo_1.write(90); // move servos to center position -> 90°
      myservo_2.write(70); // move servos to center position -> 70°
      delay(500);
      // step 2: 90, 90
      myservo_1.write(90); // move servos to center position -> 90°
      myservo_2.write(90); // move servos to center position -> 90°
      delay(500);
      // step 3: 180, 90
      myservo_1.write(180); // move servos to center position -> 180°
      myservo_2.write(90);  // move servos to center position -> 90°
      delay(500);
      // step 4: 180, 80
      myservo_1.write(180); // move servos to center position -> 180°
      myservo_2.write(70);  // move servos to center position -> 70°
      delay(500);
  } else if (flag == false && buttonState == true) {
    Serial.println("Flag is false");
    // step 4: 180, 80
    myservo_1.write(180); // move servos to center position -> 180°
    myservo_2.write(70);  // move servos to center position -> 70°
    delay(500);
    // step 3: 180, 90
    myservo_1.write(180); // move servos to center position -> 180°
    myservo_2.write(90);  // move servos to center position -> 90°
    delay(500);
    // step 2: 90, 90
    myservo_1.write(90); // move servos to center position -> 90°
    myservo_2.write(90); // move servos to center position -> 90°
    delay(500);
    // step 1: 90, 80
    myservo_1.write(90); // move servos to center position -> 90°
    myservo_2.write(70); // move servos to center position -> 70°
    delay(500);
  }

  delay(100); // Small delay to prevent flooding the serial monitor
}
  // if (buttonState == HIGH) { // If the button is pressed
  //   // // step 1: 90, 80
  //   // myservo_1.write(90); // move servos to center position -> 90°
  //   // myservo_2.write(70); // move servos to center position -> 70°
  //   // delay(500);
  //   // // step 2: 90, 90
  //   // myservo_1.write(90); // move servos to center position -> 90°
  //   // myservo_2.write(90); // move servos to center position -> 90°
  //   // delay(500);
  //   // // step 3: 180, 90
  //   // myservo_1.write(180); // move servos to center position -> 180°
  //   // myservo_2.write(90);  // move servos to center position -> 90°
  //   // delay(500);
  //   // // step 4: 180, 80
  //   // myservo_1.write(180); // move servos to center position -> 180°
  //   // myservo_2.write(70);  // move servos to center position -> 70°
  //   // delay(500);
  // } else {
  //   // If the button is not pressed, move the servos to the center position
  //   myservo_1.write(90);
  //   myservo_2.write(90);
  // }
// }
