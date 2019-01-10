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


void setup() {
  pinMode(PS2_SEL, OUTPUT);
  digitalWrite(PS2_SEL, HIGH);
  PAD.init();

  Serial.begin(9600);
}

void loop() {
  PAD.poll();

  Serial.print("  A0:");
  if (PAD.read(PS_PAD::PAD_RIGHT) || PAD.read(PS_PAD::PAD_CIRCLE)) {
    Serial.print("L");
  } else {
    Serial.print("H");
  }

  Serial.print("  A1:");
  if (PAD.read(PS_PAD::PAD_TOP) || PAD.read(PS_PAD::PAD_TRIANGLE)) {
    Serial.print("L");
  } else {
    Serial.print("H");
  }

  Serial.print("  A2:");
  if (PAD.read(PS_PAD::PAD_BOTTOM) || PAD.read(PS_PAD::PAD_X)) {
    Serial.print("L");
  } else {
    Serial.print("H");
  }

  Serial.print("  A3:");
  if (PAD.read(PS_PAD::PAD_LEFT) || PAD.read(PS_PAD::PAD_SQUARE)) {
    Serial.print("L");
  } else {
    Serial.print("H");
  }

  Serial.print("  A4:");
  if (PAD.read(PS_PAD::PAD_R1) || PAD.read(PS_PAD::PAD_L1)) {
    Serial.print("L");
  } else {
    Serial.print("H");
  }

  Serial.print("  A5:");
  if (PAD.read(PS_PAD::PAD_R2) || PAD.read(PS_PAD::PAD_L2)) {
    Serial.print("L");
  } else {
    Serial.print("H");
  }

  Serial.print("  RESET:");
  if (PAD.read(PS_PAD::PAD_START) || PAD.read(PS_PAD::PAD_SELECT)) {
    Serial.print("L");
  } else {
    Serial.print("H");
  }

  Serial.println();
}
