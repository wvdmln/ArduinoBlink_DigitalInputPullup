/*
  Blink LED_BUILTIN + "Schakelaar" die "Lampje" stuurt

  LED_BUILTIN gaat aan voor 5s, daarna uit voor 5 s, herhalend.
  Schakelaar bedient INPUT 2 (wordt hier gebruikt met de ingebouwde pullup-weerstand)
  Wanneer de schakelaar (INPUT 2) bediend wordt, willen we dat het lampje brandt (OUTPUT 12)

  We stellen vast dat die programma niet werkt zoals we zouden verwachten.
  Lampje reageert heel traag op het signaal van de schakelaar.

  */
  
#define LED_BUILTIN 13
#define Lampje 12
#define Schakelaar 2

// de setup-functie runt 1 keer na reset of power-on

void setup() {
  //start de seriële connectie (monitorfunctie)
  Serial.begin(9600);
  // initialiseer inputs en outputs
  // schakelaar kan ook met een gewone INPUT geïnitialiseerd worden
  // Let wel: PULLUP-ingang is LOW als de schakelaar bediend wordt >> Ingang wordt verbonden met GND (werkt dus omgekeerd)
  // Voordeel: Input is niet zwevend wanneer de schakelaar open is
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Lampje, OUTPUT);
  pinMode(Schakelaar, INPUT_PULLUP);
  
}

// de loop-function runt telkens opnieuw
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // LED ON
  delay(5000);                       // wacht 5 seconden
  digitalWrite(LED_BUILTIN, LOW);    // LED OFF 
  delay(5000);                       // wacht 5 seconden

  //lees de status van de schakelaar in een variabele
  int sensorVal = digitalRead(Schakelaar);
  //print de waarde in de seriële monitor (0 of 1)
  Serial.println(sensorVal);
  
  //Het Lampje reageert met een vertraging op het bedienen van de schakelaar ==> HOE KAN DAT?
  //Het probleem is de delay-functie. Tijdens delay doet de Arduino niets en checkt bijgevolg dus ook de status van de input niet meer
     if (sensorVal == HIGH) {
    digitalWrite(Lampje, LOW); // Pullup-ingang werkt omgekeerd >> HIGH > LOW
  } else {
    digitalWrite(Lampje, HIGH);
  }
}
