#include <Servo.h>

#include <LiquidCrystal.h>

Servo servoMotor;

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
const int RES=3;
const int RESS=2;
int contador=4;
int val=0;
int old_val=0;
int val2=0;
int old_val2=0;
Servo servo2;

void setup() {// Definimos la LCD con dimension 2x16 y definimos los caracteres que deben salir en las filas:
lcd.begin(16,2);
lcd.print("    Lugares    ");
lcd.setCursor(0,1);
lcd.print("Disponibles=");
servoMotor.attach(6);
servo2.attach(5);
pinMode (RES,INPUT);
pinMode (RESS,INPUT);
}  
void loop() {
  val=digitalRead(RES);
    lcd.setCursor(14,1);
    lcd.print(contador);
    if (contador>0){
  if ((val==HIGH) && (old_val == LOW)) {

  servoMotor.write(0);

  delay(1000);
  contador=contador-1;
  delay(1000);
}

else{ 
  
  servoMotor.write(90);

}
old_val=val;
  servoMotor.write(90);
    }
//Boton 2
  val2=digitalRead(RESS);
      if (contador<4){
  if ((val2==HIGH) && (old_val2 == LOW)) {

  servo2.write(0);

  delay(1000);
  contador=contador+1;
  delay(1000);
}

else{ 
  
  servo2.write(90);

}
old_val2=val2;
  servo2.write(90);
      }
    
       
  
  //Por último, hemos usado la parte activa del programa o bucle para que constantemente para cada variación recalcule los datos. 
  
}
