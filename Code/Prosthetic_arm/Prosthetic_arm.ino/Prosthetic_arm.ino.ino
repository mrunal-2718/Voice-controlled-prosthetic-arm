#include <Servo.h>

Servo servos[5];
int servoPins[5] = {5, 6, 9, 10, 11}; // 0: Thumb, 1: Index, 2: Middle, 3: Ring, 4: Wrist

String inputCommand = "";
int activeFinger = -1;
int angle = 0;
bool isMoving = false;
bool goingForward = true;
bool isWave = false;

void setup() {
  Serial.begin(9600); // For Bluetooth communication

  for (int i = 0; i < 5; i++) {
    servos[i].attach(servoPins[i]);
    servos[i].write(0); // Initial position
  }

  Serial.println("Send 'thumb', 'index', 'middle', 'ring', 'wrist', 'openarm', 'closearm', or 'wave'.");
}

void loop() {
  // Check for serial input
  if (Serial.available()) {
    inputCommand = Serial.readStringUntil('\n');
    inputCommand.trim();
    inputCommand.toLowerCase();

    if (inputCommand == "thumb") activeFinger = 0;
    else if (inputCommand == "index") activeFinger = 1;
    else if (inputCommand == "middle") activeFinger = 2;
    else if (inputCommand == "ring") activeFinger = 3;
    else if (inputCommand == "little" || inputCommand == "wrist") activeFinger = 4;

    if (activeFinger != -1) {
      isMoving = true;
      angle = 0;
      goingForward = true;
      Serial.print("Moving ");
      Serial.println(inputCommand);
    }

    // Open arm
    if (inputCommand == "openarm") {
      Serial.println("Opening all fingers...");
      for (int pos = 180; pos >= 0; pos--) {
        for (int i = 0; i < 5; i++) {
          servos[i].write(pos);
        }
        delay(10);
      }
      Serial.println("Arm opened.");
    }

    // Close arm
    else if (inputCommand == "closearm") {
      Serial.println("Closing all fingers...");
      for (int pos = 0; pos <= 180; pos++) {
        for (int i = 0; i < 5; i++) {
          servos[i].write(pos);
        }
        delay(10);
      }
      Serial.println("Arm closed.");
    }

    // Wave motion
    else if (inputCommand == "wave") {
      Serial.println("Performing wave gesture...");
      for (int i = 0; i < 5; i++) {
        for (int pos = 0; pos <= 180; pos++) {
          servos[i].write(pos);
          delay(5);
        }
        for (int pos = 180; pos >= 0; pos--) {
          servos[i].write(pos);
          delay(5);
        }
      }
      Serial.println("Wave complete.");
    }

    // Reset for next command
    if (inputCommand == "openarm" || inputCommand == "closearm" || inputCommand == "wave") {
      inputCommand = "";
      activeFinger = -1;
    }
  }

  // Animate finger movement (individual)
  if (isMoving && activeFinger != -1) {
    if (goingForward) {
      angle++;
      if (angle >= 180) goingForward = false;
    } else {
      angle--;
      if (angle <= 0) {
        isMoving = false;
        activeFinger = -1;
        Serial.println("Movement complete.");
      }
    }

    servos[activeFinger].write(angle);
    delay(10); // Smooth motion
  }
}
