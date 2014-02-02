const byte PIN_ANALOG_X = 0;
const byte PIN_ANALOG_Y = 1;

void setup() {

  Serial.begin(9600);
}

void loop() {


  Serial.print("x:");

  Serial.print(analogRead(PIN_ANALOG_X));

  Serial.print(" ");


  Serial.print("y:");

  Serial.print(analogRead(PIN_ANALOG_Y));

  Serial.print(" ");


  Serial.println();
}
