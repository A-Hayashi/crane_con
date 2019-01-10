#include "PS_PAD.h"

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

#define A5 19
#define A4 18
#define A3 17
#define A2 16
#define A1 15
#define A0 14

#define PS2_SEL A4
PS_PAD PAD(PS2_SEL);


#define S_A0  3
#define S_A1  4
#define S_A2  5
#define S_A3  6
#define S_A4  7
#define S_A5  8
#define S_RESET 9

void setup() {
  pinMode(PS2_SEL, OUTPUT);
  digitalWrite(PS2_SEL, HIGH);
  PAD.init();

  pinMode(S_A0, INPUT);
  pinMode(S_A1, INPUT);
  pinMode(S_A2, INPUT);
  pinMode(S_A3, INPUT);
  pinMode(S_A4, INPUT);
  pinMode(S_A5, INPUT);
  pinMode(S_RESET, INPUT);
  Serial.begin(9600);
}

void loop() {
  PAD.poll();

  Serial.print("  A0:");
  if (PAD.read(PS_PAD::PAD_RIGHT) || PAD.read(PS_PAD::PAD_CIRCLE)) {
    Serial.print("L");
    digitalWrite(S_A0, LOW);
    pinMode(S_A0, OUTPUT);
  } else {
    Serial.print("H");
    pinMode(S_A0, INPUT);
  }

  Serial.print("  A1:");
  if (PAD.read(PS_PAD::PAD_TOP) || PAD.read(PS_PAD::PAD_TRIANGLE)) {
    Serial.print("L");
    digitalWrite(S_A1, LOW);
    pinMode(S_A1, OUTPUT);
  } else {
    Serial.print("H");
    pinMode(S_A1, INPUT);
  }

  Serial.print("  A2:");
  if (PAD.read(PS_PAD::PAD_BOTTOM) || PAD.read(PS_PAD::PAD_X)) {
    Serial.print("L");
    digitalWrite(S_A2, LOW);
    pinMode(S_A2, OUTPUT);
  } else {
    Serial.print("H");
    pinMode(S_A2, INPUT);
  }

  Serial.print("  A3:");
  if (PAD.read(PS_PAD::PAD_LEFT) || PAD.read(PS_PAD::PAD_SQUARE)) {
    Serial.print("L");
    digitalWrite(S_A3, LOW);
    pinMode(S_A3, OUTPUT);
  } else {
    Serial.print("H");
    pinMode(S_A3, INPUT);
  }

  Serial.print("  A4:");
  if (PAD.read(PS_PAD::PAD_R1) || PAD.read(PS_PAD::PAD_L1)) {
    Serial.print("L");
    digitalWrite(S_A4, LOW);
    pinMode(S_A4, OUTPUT);
  } else {
    Serial.print("H");
    pinMode(S_A4, INPUT);
  }

  Serial.print("  A5:");
  if (PAD.read(PS_PAD::PAD_R2) || PAD.read(PS_PAD::PAD_L2)) {
    Serial.print("L");
    digitalWrite(S_A5, LOW);
    pinMode(S_A5, OUTPUT);
  } else {
    Serial.print("H");
    pinMode(S_A5, INPUT);
  }

  Serial.print("  RESET:");
  if (PAD.read(PS_PAD::PAD_START) || PAD.read(PS_PAD::PAD_SELECT)) {
    Serial.print("L");
    digitalWrite(S_RESET, LOW);
    pinMode(S_RESET, OUTPUT);
  } else {
    Serial.print("H");
    pinMode(S_RESET, INPUT);
  }

  Serial.println();
}
