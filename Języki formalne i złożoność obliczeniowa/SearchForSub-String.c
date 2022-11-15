#include <sys/types.h> 

#define Red "\033[31m"
#define Reset "\x1b[0m"
#define Green "\033[32m" 
#define Clear "\033[H\033[J" 


#include <stdio.h>

int main(){
	
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
	printf("Enter your string: ");
	fgets(str,sizeof(str),stdin);
	printf("\nYour string is: ");
	//puts(str);
	printf("Enter your sub-string: ");
	scanf("%s",subStr);
	//printf("\nYour sub-string is: %s",subStr);
	
	int index[10];
	int j = 0;
	int i = 0;
	int k = 0;
	int m = 0;
	int count = 0;
	for(count; subStr[count]!='\0'; count++){}
	printf("\nSub-String length is: %d\n",count);
	
	
	for(i; str[i]!='\0';i++){
	
		
		if(k==count-1){
			if(str[i] == subStr[j]){
			
			printf("wystepuje! na indeksie %d \n",i-count+1);
			index[m] = i-count+1;
			m++;
			k=0;
			j=0;
			}
			else{
				k=0;
				j=0;
			}
		}
		else{
		
		if(str[i]==subStr[j]){
			k++;
			j++;
	}
	else{
	k=0;
	j=0;
	}
		}
		}
	i = 0;
	j=0;
	m = m-1;
	int pivot = 0;
	int pivot2 = 1;
	for(i; str[i]!='\0';i++){
	if(pivot == 1){
	    if(pivot2 == count){
	    pivot = 0;
	    printf(Green);
			printf("%c",str[i]);
			printf(Reset);
			pivot2=1;
	    
	    }else{
	    printf(Green);
			printf("%c",str[i]);
			printf(Reset);
			pivot2++;
			}
	
	
	}
	else if(m>=0){
		if(index[j]==i){
			m--;
			j++;
			printf(Green);
			printf("%c",str[i]);
			printf(Reset);
			if(count>1){
			pivot = 1;}
		}
		else{
			printf("%c",str[i]);
		}
	}else{
		printf("%c",str[i]);
	}
	
		
	}
	
	
	return 0;
}









