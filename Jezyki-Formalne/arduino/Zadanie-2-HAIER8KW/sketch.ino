#define ButtonPin 2
#define Relay_CN23 4
#define Relay_CN22 3
#define Relay_CN21 7
#define Relay_3D 8

//------- STANY HAIER 8KW ---Zaczynamy w stanie 1! ---------
    bool CN23 = false;
    bool CN22 = false;
    bool CN21 = false;
    byte D3 = 0; // 0 = CWW  | 1 = Podłoga
//------------------------------------
bool heatingCO = true;
bool heatingCWU = true;

const float BETA = 3950; // do zmiany wartości analogowej na cyfrową.
float celsius;
byte button_on_off = 0; // button ON/OFF
int arduino_on_off = 1; //  1 = OFF  | 0 = ON  | 2 = start
int state = 1;
byte season; // 0 = summer | 1 = winter
char *polecenie[150];
int tempStart = 42;
int tempStop = 46; 

void ShutDown(){ //state 1
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
  CN22 = heatingCWU;
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
  CN22 = heatingCWU;
  CN21 = false;
  D3 = 0;
}

void Summer(){ // stan 3
state = 3;
  CN23 = true;
  CN22 = false;
  CN21 = false;
  D3 = 0;
  if(celsius < tempStart){
    CWW();
  }
}

void Winter(){ //stan 4
state = 4;
  CN23 = true;
  CN22 = heatingCWU;
  CN21 = true;
  D3 = 1;
}

void Floor(){ //stan 5
state = 5;
  CN23 = false;
  CN22 = false;
  CN21 = true;
  D3 = 1;
  if(celsius < tempStart){
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

void program(){ //Program który się uruchamia wtw, gdy arduino jest "włączone"
  int analogValue = analogRead(A0);
  celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  if (state == 2){
    CWW();
        if ((season == 0 || (heatingCO == false && season == 1)) && celsius > tempStop) {
            state = 3;
            Summer();
        }
        else if ((season == 1 && heatingCO == true) && celsius > tempStop){
            state = 4;
            Winter();
            
        }
  }
  else if (state == 3){
      Summer();
  }
  else if (state == 4){
      Winter();
      
      state = 5;
  }
  else if (state == 5){
      Floor();
  }
  else{
    CWW();
  }
}

void parser(char *buffer){

char * pojedyncze_slowo = strtok (buffer," \n\t"); 
	int indeks=0; 
	while(1){ 
		if(pojedyncze_slowo==NULL){
			break;
		}
		else{
			polecenie[indeks]=pojedyncze_slowo; 
			indeks=indeks+1; 
			pojedyncze_slowo=strtok(NULL," \n\t"); 
			polecenie[indeks]=NULL; 
		}
	}
}

void change(){


     if((strcmp(polecenie[0],"data")==0)&&(polecenie[1]==NULL)){ 
      Serial.print("Season: ");
      Serial.println(season);
      Serial.print("State: ");
      Serial.println(state);
      Serial.print("CN23:");
      Serial.println(CN23);
      Serial.print("CN22:");
      Serial.println(CN22);
      Serial.print("CN21:");
      Serial.println(CN21);
      Serial.print("D3:");
      Serial.println(D3);
      Serial.print("Temp: ");
      Serial.println(celsius);
		}              
		else if((strcmp(polecenie[0],"hotwater")==0)&&(strcmp(polecenie[1],"start")==0)&&(polecenie[2]==NULL)){ 
      heatingCWU = true;
      if(celsius < tempStop){
        CWW();
      }
      Serial.println("\nWŁĄCZENIE OGRZEWANIA CWU\n");
		
		}
    else if((strcmp(polecenie[0],"hotwater")==0)&&(strcmp(polecenie[1],"start")==0)&&(strcmp(polecenie[2],"temp")==0)&&(polecenie[3]==NULL)){ 
    Serial.println(tempStart);
		}
    else if((strcmp(polecenie[0],"hotwater")==0)&&(strcmp(polecenie[1],"start")==0)&&(strcmp(polecenie[2],"temp")==0)&&(polecenie[3] == (int)polecenie[3])&&(polecenie[4]==NULL)){ 
			char a = (polecenie[3][0]);
      char b = (polecenie[3][1]);
      int ia = a - '0';
      int ib = b - '0';
      int number = ia * 10 + ib;
      if(number<tempStop){
      
      tempStart = number;
      Serial.println("\nTemperatura zmieniona\n");
		}else{
      Serial.println("\nOperacja niemożliwa - temperatura powinna być mniejsza niż tempStop: ");
      Serial.print(tempStop);
      Serial.println("");
    }}
    else if((strcmp(polecenie[0],"hotwater")==0)&&(strcmp(polecenie[1],"stop")==0)&&(polecenie[2]==NULL)){
      heatingCWU = false;
      Serial.println("\nWYŁĄCZENIE OGRZEWANIA CWU\n");
			
		}
    else if((strcmp(polecenie[0],"hotwater")==0)&&(strcmp(polecenie[1],"stop")==0)&&(strcmp(polecenie[2],"temp")==0)&&(polecenie[3]==NULL)){ 
      Serial.println("");
      Serial.println(tempStop);
		}
    else if((strcmp(polecenie[0],"hotwater")==0)&&(strcmp(polecenie[1],"stop")==0)&&(strcmp(polecenie[2],"temp")==0)&&(polecenie[3] == (int)polecenie[3])&&(polecenie[4]==NULL)){ 
			char a = (polecenie[3][0]);
      char b = (polecenie[3][1]);
      int ia = a - '0';
      int ib = b - '0';
      int number = ia * 10 + ib;
      if(number>tempStart){
      
      tempStop = number;
      Serial.println("\nTemperatura zmieniona\n");
			}else{
      Serial.println("\nOperacja niemożliwa - temperatura powinna być większa niż tempStart: \n");
      Serial.print(tempStart);
      Serial.println("");
    }
		} 
    else if((strcmp(polecenie[0],"hotwater")==0)&&(strcmp(polecenie[1],"temp")==0)&&(polecenie[2]==NULL)){ 
      Serial.println("");
      Serial.println(celsius);
		}
    else if((strcmp(polecenie[0],"heating")==0)&&(strcmp(polecenie[1],"start")==0)&&(polecenie[2]==NULL)){ 
    heatingCO = true;
    if (state == 3 && season == 1){
      Winter();
    }
    Serial.println("\nHeatingCO mode started\n");
		}
    else if((strcmp(polecenie[0],"heating")==0)&&(strcmp(polecenie[1],"stop")==0)&&(polecenie[2]==NULL)){ 
    heatingCO = false;
    if(state == 4 || state == 5){
      Summer();
    }
  Serial.println("\nHeatingCO mode stoped\n");
}
else{Serial.println("\nBłędne polecenie!\n");}
}

void loop() {
   season = digitalRead((6));
   button_on_off = digitalRead(ButtonPin);
   if(button_on_off == HIGH){
        arduino_on_off++;
        if(arduino_on_off == 1){
          ShutDown();
          return;
        }

        if(arduino_on_off == 2){
          Start();
        }
   }

  if(arduino_on_off == 0){
        program();
        digitalWrite(LED_BUILTIN, digitalRead((5)));
    }
  Relay();
  
   String str = Serial.readString();
   if (str != ""){
   char buffer [str.length() + 1];
   str.toCharArray(buffer, buffer);
   parser(buffer);
   change();}

}
