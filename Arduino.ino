  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27, 16, 2);


  int g_beforeData = 0;

  void setup() {
    // put your setup code here, to run once:
    lcd.init();
    lcd.backlight();
    Serial.begin(9600);
  }

  void loop() {
    // put your main code here, to run repeatedly:
    int potentiometerData = analogRead(A0);
    Serial.println(String() + F("Potentiometer Data : ") + potentiometerData);
    if (g_beforeData != potentiometerData){
      lcd.clear();
      lcd.setCursor(0, 0);
      g_beforeData = potentiometerData;
      lcd.print("Potentiometer");
      lcd.setCursor(0, 1);
      lcd.print(g_beforeData);
    }
  }
