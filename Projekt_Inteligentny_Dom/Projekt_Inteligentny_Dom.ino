/*
1. Zapala lampę (diodę) po podaniu sygnału z określonego pinu
2. Gasi lampe (diodę) po podaniu sygnału z określonego pinu
3. Zapala lampę (diodę) po podaniu sygnału z wyłącznika (symulacja przycisku dzwonkowego)
4. Gasi lampę (diodę) po podaniu sygnału z wyłącznika (symulacja przycisku dzwonkowego)

************Zmiana sposobu zarządzania przyciskami***********
Funkcja pinMode(pin, INPUT_PULLUP);
//DO SPRAWDZENIA
*/

#define diodaLed 13
#define przycisk 7
boolean stanLamp = false;
int test = 0;

void setup()
{
  Serial.begin(9600); //Rozpoczęcie transmisji portu szeregowego/transmission begin
  pinMode(diodaLed, OUTPUT); //ustawienie pinu nr 13 jako wyjście /set pin13 as output
  pinMode(przycisk, INPUT); //ustawienie pinu nr 7 jako wejście /set pin7 as input
  
  //Ustawienie stanu początkowego jako wyłączone swiatła
  digitalWrite(diodaLed, LOW);
  digitalWrite(przycisk, LOW);
}

void ZalaczPrzycisk()
{
  if (stanLamp == false) //Naciśnięcie przycisku//press the button stanLamp
  {
    digitalWrite(diodaLed, HIGH); //zalacza diodę (lampy) //turn on LED (Lamps)
    stanLamp = true; //ustawia flagę załączonych lamp na true (lampy załączone) //set changing lamp flag on true (the lamps are on)
    //digitalWrite.przycisk(LOW);
    delay(500);
  }
  if (stanLamp == true)
  {
    digitalWrite(diodaLed, LOW); //wylacza diodę/ turn off LED
    stanLamp = false; //ustawia flage załączenia lamp na false (lampy wyłączone) //set changing lamp flag on false (the lamps are off)
    //digitalWrite.przycisk(LOW);
    delay(500);
  }
}
void ZalaczSygnal(int zmienna)
{
  
    if ((zmienna == 49) && (stanLamp == false))
     {
       digitalWrite(diodaLed, HIGH);
       stanLamp = true;
     
       //test = Serial.read();
       Serial.print("pierwszy if. Stan zmiennej test = ");
       Serial.println(zmienna);
       delay(500);
     } 
   if ((zmienna == 48) && (stanLamp == true))
   {
     digitalWrite(diodaLed, LOW);
     stanLamp = false;
     //test = Serial.read();
     Serial.print("drugi if. Stan zmiennej test = ");
     Serial.println(zmienna);
     delay(500);
   }
    //test = Serial.read();
    //Serial.println(test);
    //digitalWrite(diodaLed, HIGH);
    //stanLamp = true;
    //delay(500);  
}
void loop()
{
  //ZalaczPrzycisk();
  if (Serial.available() > 0)
  {
    int test = Serial.read();
    Serial.flush(); //usuwa ewentualne stare dane
    ZalaczSygnal(test);
  }
  if ((digitalRead(przycisk)) == HIGH && (stanLamp == false))
  {
    Serial.println("Wcisnięto przycisk");
    digitalWrite(diodaLed, HIGH);
    stanLamp = true;
    delay(500);
    //ZalaczPrzycisk();
  }
  if ((digitalRead(przycisk)) == HIGH && (stanLamp == true))
  {
    Serial.println("Wcisnięto przycisk");
    digitalWrite(diodaLed, LOW);
    stanLamp = false;
    delay(500);
  }
}
