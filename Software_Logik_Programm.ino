// Software-Logik für boolesche Funktion, Ausgabe von Z auf LED

// Pins für Taster
const int pinA   = 5;  // A → D5
const int pinB   = 4;  // B → D4
const int pinC   = 3;  // C → D3
const int pinD   = 2;  // D → D2

// LED für Z
const int zLedPin = 13;

void setup() {
  // Taster mit internem Pull-Up
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(pinC, INPUT_PULLUP);
  pinMode(pinD, INPUT_PULLUP);

  // LED als Ausgang
  pinMode(zLedPin, OUTPUT);

}

void loop() {
  // Eingänge lesen (HIGH = gedrückt → invertieren)
  bool A = digitalRead(pinA);
  bool B = digitalRead(pinB);
  bool C = digitalRead(pinC);
  bool D = digitalRead(pinD);

  // Logikfunktion
  bool Z = (B && D) || (A && !C) || (C && !A) || (D && !C);

  // LED-Ausgabe
  digitalWrite(zLedPin, Z);
}
