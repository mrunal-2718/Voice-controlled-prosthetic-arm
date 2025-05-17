# Voice-Controlled Prosthetic Arm

A voice-activated prosthetic arm controlled using an Android app via Bluetooth. The arm responds to specific voice commands and performs physical movements using servo motors attached to 3D-printed fingers.

## 🛠️ Features
- Voice control via an Android app
- Wireless communication using HC-05 Bluetooth module
- Servo-based motion of prosthetic fingers
- Elastic-band tension system for finger reset

## 📦 Hardware Used
- Arduino Uno
- HC-05 Bluetooth Module
- Servo motors (SG90 or MG90S)
- 3D-Printed Prosthetic Arm
- Elastic bands
- Breadboard, jumper wires, and external power supply (if required)

## 💻 Software Used
- Arduino IDE
- Android app for sending voice commands (via Bluetooth)

## ⚙️ How It Works
1. The user speaks a command into the Android app.
2. The app converts speech to a text command and sends it via Bluetooth to the HC-05 module.
3. The Arduino receives the command and interprets it.
4. Based on the command, specific servo motors are activated.
5. The 3D-printed fingers, which are attached to the servo shafts, perform the desired movement.
6. Elastic bands help restore the fingers to their original positions after movement.

## 📁 Folder Structure
prosthetic-arm/
│
├── code/
│ └── prosthetic_arm/
│ └── prosthetic_arm.ino # Arduino code
│
├── schematics/
│ └── CircuitDiagram.jpeg # circuit diagram
│
├── README.md # This file
├── LICENSE # License file (MIT recommended)
└── .gitignore # Git ignore rules

## 🖼️ Circuit Diagram

![Circuit Diagram](Schematics/CircuitDiagram.jpeg)

## 📌 Notes
- All logic is implemented in the Arduino sketch (`prosthetic_arm.ino`).
- The prosthetic fingers are mechanically connected to servos, and return to rest position using elastic tension.

## 👤 Author

- Your Name: Mrunal Tambat
- GitHub Username: mrunal-2718
- Email:

## 📄 License

This project is licensed under the [MIT License](LICENSE).


