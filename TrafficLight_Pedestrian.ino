const int pinKendaraanMerah = 10;
const int pinKendaraanKuning = 9;
const int pinKendaraanHijau = 8;

const int pinPedMerah1 = 7;
const int pinPedHijau1 = 6;

const int pinPedMerah2 = 5;
const int pinPedHijau2 = 4;

const int pinTombol1 = 2;
const int pinTombol2 = 3;

volatile bool adaPenyeberang = false;

void setup() {
  pinMode(pinKendaraanMerah, OUTPUT);
  pinMode(pinKendaraanKuning, OUTPUT);
  pinMode(pinKendaraanHijau, OUTPUT);
  
  pinMode(pinPedMerah1, OUTPUT);
  pinMode(pinPedHijau1, OUTPUT);
  pinMode(pinPedMerah2, OUTPUT);
  pinMode(pinPedHijau2, OUTPUT);

  pinMode(pinTombol1, INPUT_PULLUP);
  pinMode(pinTombol2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pinTombol1), fungsiInterupsiTombol, FALLING);
  attachInterrupt(digitalPinToInterrupt(pinTombol2), fungsiInterupsiTombol, FALLING);

  setKondisiAwal();
}

void loop() {
  if (adaPenyeberang) {
    digitalWrite(pinKendaraanHijau, LOW);
    digitalWrite(pinKendaraanMerah, HIGH);
    
    digitalWrite(pinPedMerah1, LOW);
    digitalWrite(pinPedMerah2, LOW);
    digitalWrite(pinPedHijau1, HIGH);
    digitalWrite(pinPedHijau2, HIGH);
    
    delay(5000); 

    digitalWrite(pinPedHijau1, LOW);
    digitalWrite(pinPedHijau2, LOW);
    digitalWrite(pinPedMerah1, HIGH);
    digitalWrite(pinPedMerah2, HIGH);
    
    digitalWrite(pinKendaraanMerah, LOW);
    digitalWrite(pinKendaraanKuning, HIGH);
    
    delay(2000);

    digitalWrite(pinKendaraanKuning, LOW);
    setKondisiAwal(); 

    adaPenyeberang = false;
  }
}

void setKondisiAwal() {
  digitalWrite(pinKendaraanHijau, HIGH);
  digitalWrite(pinKendaraanKuning, LOW);
  digitalWrite(pinKendaraanMerah, LOW);

  digitalWrite(pinPedMerah1, HIGH);
  digitalWrite(pinPedHijau1, LOW);
  digitalWrite(pinPedMerah2, HIGH);
  digitalWrite(pinPedHijau2, LOW);
}

void fungsiInterupsiTombol() {
  adaPenyeberang = true;
}
