/*Programme AlimRobotmobile
Ce programme permet de mesurer la tension des batteries et d'en déduire leur état de charge
*/


//Led RGB 1 elec
#define BLUE1 2
#define GREEN1 1
#define RED1 0

//Led RGB 2 power
#define BLUE2 5
#define GREEN2 4
#define RED2 3

#define powcheck 0 //24V puissance
#define eleccheck 3 //12V elec
#define powresistorfactor 0.18
#define elecresistorfactor 0.414

const int nelements=10;
const float ucharge=1.4;
const float unominale=1.25;
const float udecharge=1.1;
const float ucritique=0.9;
const float Ucharge=ucharge*nelements;//pour UNE batterie de 10 éléments soit environ 12V
const float Unominale=unominale*nelements;
const float Udecharge=udecharge*nelements;
const float Ucritique=ucritique*nelements;

void setup(){
  pinMode(BLUE1,OUTPUT);
  pinMode(GREEN1,OUTPUT);
  pinMode(RED1,OUTPUT);
  pinMode(BLUE2,OUTPUT);
  pinMode(GREEN2,OUTPUT);
  pinMode(RED2,OUTPUT);
  for(int i=0;i<10;i++){
    digitalWrite(BLUE1,1^(digitalRead(BLUE1)));
    digitalWrite(BLUE2,1^(digitalRead(BLUE2)));
    delay(100);
  }
}

void loop(){
  //----------------------
  float powval=float(analogRead(powcheck))*(5.0/1023)*(1/powresistorfactor);
  float elecval=float(analogRead(eleccheck))*(5.0/1023)*(1/elecresistorfactor);
  //-----------------------POWER-----------------------------------
  if(powval>2*Unominale){
    digitalWrite(RED2,LOW);
    digitalWrite(BLUE2,LOW);
    digitalWrite(GREEN2,HIGH);
  }else if((powval<2*Unominale)&&(powval>2*Udecharge)){
    digitalWrite(RED2,HIGH);
    digitalWrite(BLUE2,LOW);
    digitalWrite(GREEN2,HIGH);
  }else if((powval<2*Udecharge)&&(powval>2*Ucritique)){
    digitalWrite(RED2,HIGH);
    digitalWrite(BLUE2,LOW);
    digitalWrite(GREEN2,LOW);
  }else{
    digitalWrite(RED2,1^digitalRead(RED2));
    digitalWrite(BLUE2,LOW);
    digitalWrite(GREEN2,LOW);
  }
  //---------------------------ELEC----------------------------------
  if(elecval>Unominale){
    digitalWrite(RED1,LOW);
    digitalWrite(BLUE1,LOW);
    digitalWrite(GREEN1,HIGH);
  }else if((elecval<Unominale)&&(elecval>Udecharge)){
    digitalWrite(RED1,HIGH);
    digitalWrite(BLUE1,LOW);
    digitalWrite(GREEN1,HIGH);
  }else if((elecval<Udecharge)&&(elecval>Ucritique)){
    digitalWrite(RED1,HIGH);
    digitalWrite(BLUE1,LOW);
    digitalWrite(GREEN1,LOW);
  }else{
    digitalWrite(RED1,1^digitalRead(RED1));
    digitalWrite(BLUE1,LOW);
    digitalWrite(GREEN1,LOW);
  }
  delay(500);
}

