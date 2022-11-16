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
	
	
	int subStrStartIndexArr[100]; // tablica w której bêd¹ umieszczane indexy na których zaczyna siê ka¿dy podci¹g.
	
	int i = 0;
	int subStringsLetterNumber = 0; // na której z kolei literze z podci¹gu pracujemy
	int subStringsNumber = 0; // ile podci¹gów wystêpuje w stringu.
	int subStrLength = 0; // d³ugoœc podci¹gu
	
	//sprawdzanie d³ugoœci podci¹gu znaków.
	for(subStrLength; subStr[subStrLength]!='\0'; subStrLength++){}
	
	
	//pêtla która dzia³a tak d³ugo - jak d³ugi jest podany w³aœciwy string.
	for(i; str[i]!='\0';i++){
		
		if(subStringsLetterNumber==subStrLength-1){ //sprawdzamy czy pracujemy ju¿ na ostatniej literze naszego podci¹gu (reszta liter siê zgadza³a)
			if(str[i] == subStr[subStringsLetterNumber]){   
				subStrStartIndexArr[subStringsNumber] = i-subStrLength+1;   // jeœli znajdziemy ca³y podci¹g - to umieszczamy w tablicy wartoœæ indexu w stringu na którym siê owy podci¹g rozpoczyna.
				subStringsNumber++; 
				subStringsLetterNumber=0; //rozpoczynamy dalsze poszukiwania podci¹gu - a wiêc zaczynamy znowu pracowaæ na pierwszej literze podci¹gu.
				
			} else{
				subStringsLetterNumber=0;
			}
		}
		else{
			if(str[i]==subStr[subStringsLetterNumber]){  //jeœli i-ta litera stringa pasuje do litery podci¹gu na której pracujemy - zaczynamy pracê na kolejnej literze.
				subStringsLetterNumber++;
			}
			else{
				subStringsLetterNumber=0;
				
			}
		}
	}
	
	//Jeœli nie znaleziono podci¹gu - wypisujemy komunikat o jego braku i koñczymy program.
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
	
	
	// wypisywanie ca³ego stringu wraz z zaznaczeniem wystêpowania podci¹gów za pomoc¹ zmiany koloru na zielony.
	for(i; str[i]!='\0';i++){
		if(pivot == 1){ 
		    if(pivot2 == subStrLength){   //bêdziemy wyœwietlaæ tak d³ugo podci¹g na zielono - dopóki pivot2 nie osiegnie liczby d³ugoœci podciagu. 
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
		else if(subStringsNumber>=0){  //jeœli s¹ nadal jakieœ znalezione podci¹gi w stringu to
			if(subStrStartIndexArr[subStringsLetterNumber]==i){ // sprawdzamy zaczynaj¹c od najstarszej wartoœci w tablicy  (pierwsza wartoœæ w tablicy[0]) czy podany index odpowiada indexowi stringu. 
				
				subStringsNumber--;                             // jeœli tak to liczba posta³ych do wypisania podciagów siê zmniejsza
				subStringsLetterNumber++;                       // zaczynamy pracowaæ póŸniej na nastêpnej literze podciagu.
				
				printf(Green);
				printf("%c",str[i]);
				printf(Reset);
				
				if(subStrLength>1){                             //jeœli d³ugosæ podci¹gu jest wiêksza od 1 to bêdziemy od teraz wypisywaæ litery na zielone tak d³ugo jak d³ugi jest podci¹g.
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









