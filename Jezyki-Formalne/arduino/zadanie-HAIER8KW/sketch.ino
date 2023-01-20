#define ButtonPin 2
#define Relay_CN23 4
#define Relay_CN22 3
#define Relay_CN21 7
#define Relay_3D 8

//------- STANY HAIER 8KW ---Zaczynamy w stanie 1! ---------
    bool CN23 = false;
    bool CN22 = false;
    bool CN21 = false;
    int D3 = 0; // 0 = CWW  | 1 = Podłoga
//------------------------------------


String tabState[] = {"" , " Program OFF" , " CWW" , " 50% - lato" , " 50% - zima" , " Podłoga - zima"};
String tabCN23[] = {" OFF" , " ON"};
String tabCN22[] = {" OFF" , " ON"};
String tabCN21[] = {" OFF" , " ON"};
String tab3D[] = {" CWW" , " Podłoga"};
String tabSeason[] = {"LATO" , "ZIMA"};


const float BETA = 3950; // do zmiany wartości analogowej na cyfrową.
float celsius;
byte button_on_off = 0; // button ON/OFF (press) 
int arduino_on_off = 1; //  1 = OFF  | 0 = ON  | 2 = start
int state = 1;
byte season; // 0 = summer  | 1 = winter

/*
     -- STANY: --
      1 -> OFF
      2 -> ON-CWW
      3 -> 50% Lato
      4 -> 50% Zima
      5 -> podłoga
*/

void ShutDown(){  //state 1
  state = 1;
  CN23 = false;
  CN22 = false;
  CN21 = false;
  D3 = 0;
  Serial.println("Program - Shut down!");
}

void Start(){ //początek programu - tylko raz podczas uruchamiania - stan 2
  state = 2;
  arduino_on_off = 0;
  CN23 = false;
  CN22 = true;
  CN21 = false;
  D3 = 0;
  Serial.println("Program - start!");
}

void setup() {
  Serial.begin(9600);
  pinMode(Relay_CN23, OUTPUT);  //Po prawej stronie również od najwyższego do najniższego.
  pinMode(Relay_CN22, OUTPUT);
  pinMode(Relay_CN21, OUTPUT);
  pinMode(Relay_3D, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ButtonPin, INPUT);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
}

void CWW(){ //stan 2
  state = 2;
  CN23 = false;
  CN22 = true;
  CN21 = false;
  D3 = 0;
}

void Summer(){ // stan 3
  CN23 = true;
  CN22 = false;
  CN21 = false;
  D3 = 0;
  if(celsius < 42){
    CWW();
  }
}

void Winter(){ //stan 4
  CN23 = true;
  CN22 = true;
  CN21 = true;
  D3 = 1;
}

void Floor(){ //stan 5
  CN23 = false;
  CN22 = false;
  CN21 = true;
  D3 = 1;
  if(celsius < 42){
     CWW();
  }
}



void Relay(){  //Zmiana na przekaźnikach
if(CN23 == true){
     digitalWrite(Relay_CN23, HIGH);
  }else{
    digitalWrite(Relay_CN23, LOW);
  }

  if(CN22 == true){
     digitalWrite(Relay_CN22, HIGH);
  }else{
    digitalWrite(Relay_CN22, LOW);
  }

  if(CN21 == true){
     digitalWrite(Relay_CN21, HIGH);
  }else{
    digitalWrite(Relay_CN21, LOW);
  }

  if(D3 == 0){
     digitalWrite(Relay_3D, HIGH);
  }else{
    digitalWrite(Relay_3D, LOW);
  }  
}

void program(){ //Program który się uruchamia za każdym razem gdy arduino jest "włączone"
  int analogValue = analogRead(A0);
  celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  if (state == 2){
        if ((season == 0) && (celsius > 46)) {
            state = 3;
            Summer();
        }
        else if ((season == 1) && (celsius > 46)){
            state = 4;
            Winter();
        }
  }
  else if (state == 3){
      Summer();
  }
  else if (state == 4){
      Winter();
      delay(4000);
      state = 5;
  }
  else if (state == 5){
      Floor();
  }
}

void loop() {
   season = digitalRead((6));
   button_on_off = digitalRead(ButtonPin);
   if(button_on_off == HIGH){
        arduino_on_off++;
        if(arduino_on_off == 1){
          delay(1000);
          ShutDown();
          return;
        }

        if(arduino_on_off == 2){
          delay(1000);
          Start();
        }
   }

  if(arduino_on_off == 0){
        program();
        digitalWrite(LED_BUILTIN, digitalRead((5)));
    }
  Relay();
  

   Serial.println("=========================");
   Serial.println(tabSeason[season]);
   Serial.print("STAN: ");
   Serial.print(state);
   Serial.println(tabState[state]);
   Serial.print("--> CN23:");
   //Serial.print(CN23);
   Serial.println(tabCN23[CN23]);
   Serial.print("--> CN22:");
   //Serial.print(CN22);
   Serial.println(tabCN22[CN22]);
   Serial.print("--> CN21:");
   //Serial.print(CN21);
   Serial.println(tabCN21[CN21]);
   Serial.print("-->  D3:");
   //Serial.print(D3);
   Serial.println(tab3D[D3]);
   Serial.print("Temperatura: ");
   Serial.print(celsius);
   Serial.println(" *C");
   Serial.println("=========================");
   delay(3000);
  
}
