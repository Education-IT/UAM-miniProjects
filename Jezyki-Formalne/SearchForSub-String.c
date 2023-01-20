#include <stdio.h>
#define Red "\033[31m"
#define Reset "\x1b[0m"
#define Green "\033[32m" 
#define Clear "\033[H\033[J" 

int main(){
printf(Clear);	
printf(Green);
printf("     __ __                     __   _                  ____         _               __    _  \n");
printf("    / //_/ _____ __  __ _____ / /_ (_)____ _ ____     / __ \\ _____ (_)____   _____ / /__ (_)\n");
printf("   / ,<   / ___// / / // ___// __// // __ `// __ \\   / / / // ___// // __ \\ / ___// //_// /\n"); 
printf("  / /| | / /   / /_/ /(__  )/ /_ / // /_/ // / / /  / /_/ /(__  )/ // / / /(__  )/ ,<  / /   \n");  
printf(" /_/ |_|/_/    \\__, //____/ \\__//_/ \\__,_//_/ /_/   \\____//____//_//_/ /_//____//_/|_|/_/\n");   
printf("              /____/                                                                         \n");
printf(Reset);

	char str[500];
	char subStr[500];
	printf(Green);
	printf("\nEnter your string:  ");
	printf(Reset);
	fgets(str,sizeof(str),stdin);
	printf(Green);
	printf("\nEnter your sub-string:  ");
	printf(Reset);
	scanf("%s",subStr);
	printf("\n");
	
	
	int subStrStartIndexArr[100]; // tablica w kt�rej b�d� umieszczane indexy na kt�rych zaczyna si� ka�dy podci�g.
	
	int i = 0;
	int subStringsLetterNumber = 0; // na kt�rej z kolei literze z podci�gu pracujemy
	int subStringsNumber = 0; // ile podci�g�w wyst�puje w stringu.
	int subStrLength = 0; // d�ugo�c podci�gu
	
	//sprawdzanie d�ugo�ci podci�gu znak�w.
	for(subStrLength; subStr[subStrLength]!='\0'; subStrLength++){}
	
	
	//p�tla kt�ra dzia�a tak d�ugo - jak d�ugi jest podany w�a�ciwy string.
	for(i; str[i]!='\0';i++){
		
		if(subStringsLetterNumber==subStrLength-1){ //sprawdzamy czy pracujemy ju� na ostatniej literze naszego podci�gu (reszta liter si� zgadza�a)
			if(str[i] == subStr[subStringsLetterNumber]){   
				subStrStartIndexArr[subStringsNumber] = i-subStrLength+1;   // je�li znajdziemy ca�y podci�g - to umieszczamy w tablicy warto�� indexu w stringu na kt�rym si� owy podci�g rozpoczyna.
				subStringsNumber++; 
				subStringsLetterNumber=0; //rozpoczynamy dalsze poszukiwania podci�gu - a wi�c zaczynamy znowu pracowa� na pierwszej literze podci�gu.
				
			} else{
				subStringsLetterNumber=0;
			}
		}
		else{
			if(str[i]==subStr[subStringsLetterNumber]){  //je�li i-ta litera stringa pasuje do litery podci�gu na kt�rej pracujemy - zaczynamy prac� na kolejnej literze.
				subStringsLetterNumber++;
			}
			else{
				subStringsLetterNumber=0;
				
			}
		}
	}
	
	//Je�li nie znaleziono podci�gu - wypisujemy komunikat o jego braku i ko�czymy program.
	if(subStringsNumber<=0){
		printf("\n---------------------------------\n");
		printf(Red);
		printf("Sub-String");
		printf(Reset);
		printf(" '%s' ",subStr);
		printf(Red);
		printf("not found!");
		printf(Reset); 
		printf("\n---------------------------------\n");
		return 0;
	}else{
	    printf(Green);
	    printf("Sub-strings in text:\n");
	    printf(Reset);
	}
	
	i = 0;
	subStringsLetterNumber=0;
	subStringsNumber = subStringsNumber-1; 
	int pivot = 0;
	int pivot2 = 1;
	
	
	// wypisywanie ca�ego stringu wraz z zaznaczeniem wyst�powania podci�g�w za pomoc� zmiany koloru na zielony.
	for(i; str[i]!='\0';i++){
		if(pivot == 1){ 
		    if(pivot2 == subStrLength){   //b�dziemy wy�wietla� tak d�ugo podci�g na zielono - dop�ki pivot2 nie osiegnie liczby d�ugo�ci podciagu. 
			    pivot = 0; 
			    //printf(Green);
				printf("%c",str[i]);
				//printf(Reset);
				pivot2=1;
		    }
			else{
		    	printf(Green);
				printf("%c",str[i]);
				printf(Reset);
				pivot2++;
			}
		}
		else if(subStringsNumber>=0){  //je�li s� nadal jakie� znalezione podci�gi w stringu to
			if(subStrStartIndexArr[subStringsLetterNumber]==i){ // sprawdzamy zaczynaj�c od najstarszej warto�ci w tablicy  (pierwsza warto�� w tablicy[0]) czy podany index odpowiada indexowi stringu. 
				
				subStringsNumber--;                             // je�li tak to liczba posta�ych do wypisania podciag�w si� zmniejsza
				subStringsLetterNumber++;                       // zaczynamy pracowa� p�niej na nast�pnej literze podciagu.
				
				printf(Green);
				printf("%c",str[i]);
				printf(Reset);
				
				if(subStrLength>1){                             //je�li d�ugos� podci�gu jest wi�ksza od 1 to b�dziemy od teraz wypisywa� litery na zielone tak d�ugo jak d�ugi jest podci�g.
				pivot = 1;
				}
			}
			else{
				printf("%c",str[i]);
			}
		}else{
			printf("%c",str[i]);
		}
	}	
	printf("\n"); 
	return 0;
}









