#include<stdio.h>
#include <stdlib.h>
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
void gra()
{int gra[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int x,g,h,i=0;
printf("	          kolumna\n");
printf("	        0     1     2\n");
printf("	w    | ---------------\n");
printf("	i  0 | 0,0 | 0,1 | 0,2\n");
printf("	e    |---------------\n");
printf("	r  1 | 1,0 | 1,1 | 1,2\n");
printf("	s    |---------------\n");
printf("	z  2 | 2,0 | 2,1 | 2,2\n");
for(i=0;i<=9;i++)
{
 if(( gra[0][0]==2)&&( gra[0][1]==2)&&( gra[0][2]==2))
{ printf("gracz '2' wygral!!!\n");
 printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
 if(( gra[0][0]==1)&&( gra[0][1]==1)&&( gra[0][2]==1))
{ printf("gracz '1' wygral!!!\n");
  printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;   }
 else
 if(( gra[1][0]==2)&&( gra[1][1]==2)&&( gra[1][2]==2))
{ printf("gracz '2' wygral!!!\n");  printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
 if(( gra[1][0]==1)&&( gra[1][1]==1)&&( gra[1][2]==1))
{ printf("gracz '1' wygral!!!\n"); printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
  if(( gra[2][0]==2)&&( gra[2][1]==2)&&( gra[2][2]==2))
{ printf("gracz '2' wygral!!!\n"); printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
 if(( gra[2][0]==1)&&( gra[2][1]==1)&&( gra[2][2]==1))
{ printf("gracz '1' wygral!!!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x); system("cls");break;  }
 else
  if(( gra[0][0]==2)&&( gra[1][0]==2)&&( gra[2][0]==2))
{
  printf("gracz '2' wygral!!!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
 if(( gra[0][0]==1)&&( gra[1][0]==1)&&( gra[2][0]==1))
{ printf("gracz '1' wygral!!!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
  if(( gra[0][1]==2)&&( gra[1][1]==2)&&( gra[2][1]==2))
{ printf("gracz '2' wygral!!!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
 if(( gra[0][1]==1)&&( gra[1][1]==1)&&( gra[2][1]==1))
{ printf("gracz '1' wygral!!!/n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
  if(( gra[0][2]==2)&&( gra[1][2]==2)&&( gra[2][2]==2))
{ printf("gracz '2' wygral!!!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
 if(( gra[0][2]==1)&&( gra[1][2]==1)&&( gra[2][2]==1))
{ printf("gracz '1' wygral!!!\n"); printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
  if(( gra[0][0]==2)&&( gra[1][1]==2)&&( gra[2][2]==2))
{ printf("gracz '2' wygral!!!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
 if(( gra[0][0]==1)&&( gra[1][1]==1)&&( gra[2][2]==1))
{ printf("gracz '1' wygral!!!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
else
 if(( gra[2][0]==2)&&( gra[1][1]==2)&&( gra[0][2]==2))
{ printf("gracz '2' wygral!!!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
 else
 if(( gra[2][0]==1)&&( gra[1][1]==1)&&( gra[0][2]==1))
{ printf("gracz '1' wygral!!!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x);system("cls"); break;  }
else
{if(i==9)
{printf("Remis!\n");printf("Wpisz cokolwiek aby wyjsc\n"); scanf("%d",&x); system("cls"); break; }

if((i==4) || (i==7))
 {
printf("	          kolumna\n");
printf("	        0     1     2\n");
printf("	w    | ---------------\n");
printf("	i  0 | 0,0 | 0,1 | 0,2\n");
printf("	e    |---------------\n");
printf("	r  1 | 1,0 | 1,1 | 1,2\n");
printf("	s    |---------------\n");
printf("	z  2 | 2,0 | 2,1 | 2,2\n");
} 
printf("Podaj wiersz\n");
 scanf("%d",&g);
 printf("Podaj kolumne\n");
 scanf("%d",&h);
 printf("Podaj numer gracza - '1' lub '2'\n");
 scanf("%d",&gra[g][h]);}} return;}
 //---------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------
 void zgadywanka()
 { int x,y,a;
 printf("Witaj! Jestem komputerem i postaram sie zgadnac o jakiej liczbie myslisz!\n");
 printf("Pomysl o jakies liczbie od 1 do 8. \nProsze odpowiadaj na pytania - jesli'tak' - 1  lub 'nie' - 0\n");
 printf("Gotowy?");
 scanf("%d",&a);
 if(a!=1)
 printf("Napisz w takim razie '1' gdy bedziesz gotowy.\n");
 
 while(a!=1)
 scanf("%d",&a);
 
 printf("Czy Twoja liczba jest < 5 ?\n");
 scanf("%d",&x);
    if(x==1) 
    
{{    printf("Czy Twoja liczba jest <3\n");
      scanf("%d",&y);
      if(y==1)
          {printf("Czy Twoja liczba o ktorej myslisz to '1'?\n");
           x=0;scanf("%d",&x);
			  if(x==1)
				{printf("Zgadlem! Dzieki za gre!\n"); printf("Wpisz dowolna wartoc by zakonczyc\n"); scanf("%d",&x); system("cls"); return ;}  
				else
				{printf("W takim razie Twoja liczba to 2!Prawda?\n");scanf("%d",&x);if(x==1) {printf("Zgadlem! Dzieki za gre!\n"); printf("Wpisz dowolna wartoc by zakonczyc\n"); scanf("%d",&x); system("cls"); return ;}}}
       else {printf("Czy Twoja liczba jest >= 3\n");
           scanf("%d",&y);
            if(y==1)
               printf("Czy Twoja liczba o ktorej myslisz to '3'?\n");
               x=0;scanf("%d",&x);
				if(x==1)
				   {printf("Zgadlem! Dzieki za gre!\n"); printf("Wpisz dowolna wartoc by zakonczyc\n"); scanf("%d",&x); system("cls"); return ;}
				else
				 {printf("W takim razie Twoja liczba to 4!Prawda?\n");scanf("%d",&x);if(x==1) {printf("Zgadlem! Dzieki za gre!\n"); printf("Wpisz dowolna wartoc by zakonczyc\n"); scanf("%d",&x); system("cls"); return ;}}}}}
 
  else 
    {printf("Czy Twoja liczba jest < 7?\n");
    scanf("%d",&x);}
      if(x==1)
         {{printf("Czy Twoja licba to 5?\n"); x=0;scanf("%d",&x);}
			if(x==1)
		      {printf("Zgadlem! Dzieki za gre!\n"); printf("Wpisz dowolna wartoc by zakonczyc\n"); scanf("%d",&x); system("cls"); return ;}  
			  else
		      {printf("W takim razie Twoja liczba to 6!Prawda?\n");scanf("%d",&x);if(x==1) {printf("Zgadlem! Dzieki za gre!\n"); printf("Wpisz dowolna wartoc by zakonczyc\n"); scanf("%d",&x); system("cls"); return ;}}}
       else
         {printf("Czy Twoja liczba jest >= 7?\n");
         scanf("%d",&x);}
          if(x==1)
             {{printf("Czy Twoja licba to 7?\n"); x=0;scanf("%d",&x);}
			 if(x==1)
			    {printf("Zgadlem! Dzieki za gre!\n"); printf("Wpisz dowolna wartoc by zakonczyc\n"); scanf("%d",&x); system("cls"); return ;}  
			 else
			    {printf("W takim razie Twoja liczba to 8!Prawda?\n");scanf("%d",&x);if(x==1) {printf("Zgadlem! Dzieki za gre!\n"); printf("Wpisz dowolna wartoc by zakonczyc\n"); scanf("%d",&x); system("cls"); return ;}}}
 

}
//--------------------------------------------------------------------------------------------------- 
//---------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------
int podciag(int n , int q[])
{ int max,x,y;
max=1;x=q[0];y=1;
int i = 1;
for(i;i<n;i++)
{ if(q[i]==x)
{   y=y+1;
    x=q[i];
  if(y>max)
    {max=y;}}
  else
   {x=q[i];
     y=1;}
 }
return (max);}

 int ciag()
{int n,i,j,y,max;
 system("cls");
 printf("Podaj ile liczb ma byc w Twoim ciagu liczb\n");
 scanf("%d",&n);
 int q[n];
 printf("Podaj teraz swoj ciag liczb\n");
 for(i=0;i<n;i++)
 {scanf("%d",&q[i]);}
 printf("A wiec Twoj ciag liczb to:\n");
 for(j=0;j<n;j++)
 printf(" |%d| ",q[j]); 
 printf("\n--------------------------------------\n");
 max = podciag(n,q);
 printf("najdluzszy podciag w tym ciagu liczb wynosi = %d\n",max);
 printf("\nWpisz dowolna wartoc aby zakonczyc program"); scanf("%d",&y); system("cls"); return 0; 

}
 //---------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------

 void podz(int a, int b)
 { int n,i;
 if(a>b)
 n=a;
 else n=b;
 printf("\nWspolnym dzielnikiem 'x' i 'y' jest liczba :\n");
 for(i=1;i<=n;i++)
{if((a%i==0)&&(b%i==0))
printf("--> %d\n",i);}
 }
 
 void bliz(int n, int m)
{
if((n<2)|| (m<2))
printf("\nLiczby nie sa blizniacze\n");
else
if((m-n!=2) || (m-n!=2))
printf("\nLiczby nie sa blizniacze\n");
else 
for (int i=2; i<n; i++)
{if(n%i==0)
printf("\nLiczby nie sa blizniacze\n");
else
if(m%i==0)
printf("\nLiczby nie sa blizniacze\n");
else 
printf("\nLiczby sa blizniacze\n");}}


int Euklides(int x, int y)
{ int a,b;
if(y>x)
{b=x;
x=y;
y=b;}
while(y!=0){
a = x%y;
x = y;
y = a; }
printf("\nNajwiekszym wspolnym dzielnikiem tych liczb jest liczba = %d\n", x);return x;}

void wzglpierwsze(int x)
{if(x==1)
printf("\nliczby wzglednie pierwsze\n");
else
printf("\nLiczby NIE SA wzglednie pierwsze\n");}

int sum(int x,int y)
{int c;
c = x + y; return c;}

int sumakwa(int x, int y)
{int c; x=x*x;
y=y*y; 

return sum(x,y);} 

 
 void XY()
 {system("cls");
 
 int x,y,z;
 printf("Podaj liczbe 'x' i 'y' aby poznac ich wlasciwosci\n");
 printf("\nX = ");scanf("%d",&x);
 printf("\nY = ");scanf("%d",&y);
 if(x==y)
 printf("\nLiczby sa rowne\n");
 else
 printf("\nLiczby NIE sa rowne\n");
 bliz(x,y);
 podz(x,y);
 z = Euklides(x,y);
 wzglpierwsze(z);
 z = sumakwa(x,y);
 printf("\nSuma Kwadratow liczby 'x' i 'y' wynosi = %d\n",z);
 
 printf("\nWypisz dowolna wartosc aby zakonczyc program");
 scanf("%d",&z);
 system("cls");
 return;
 }
 
 
 
 
 //---------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------
 
 int insertSort(int n, int m[])
 {int i,j,y;

 for(i=0;i<=n;i++)
{y=m[i];
j=i-1;
while((y<m[j]) && (j>=-1))
{m[j+1]=m[j];
j=j-1;
m[j+1]=y;}}return m[n];}

int suma(int x, int b[])
{int l; int sumac=0;
for(l=0;l<x;l++)
{sumac=sumac+b[l];} return sumac;
}

void ciag2()
 {system("cls");
 int n,i,y; 
int sumac;
printf("Podaj wartosc ilosci liczb w ciagu\n");
scanf("%d",&n);
int m[n];
printf("Podaj teraz liczby Twojego ciagu:\n");
for(int z=0;z<n;z++)
{scanf("%d",&m[z]);}

insertSort(n,m);
printf("-----------------------");
printf("\nTwoj ciag po posortowaniu - wyglada nastepujaco\n");
for(int g=0;g<n;g++)
{printf("%d  ",m[g]);}
printf("\n-----------------------\n");
sumac = suma(n,m);
printf("\nSuma liczb w tym ciagu wynosi = %d\n", sumac);
printf("\nPodaj dowolona wartosc aby zakonczyc program");
scanf("%d",&n);
system("cls");
return;}



 
 
 
 
 
 //---------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------
 //---------------------------------------------------------------------------------------------------
 int main ()
 {int x; 
 while(1)
{ x=-1;
 printf("                     MENU\n");
 printf("  	        wybierz opcje\n");
 printf("-----------------------------------------------\n");
 printf("1. Gra w kolko i krzyzyk                      |\n");
 printf("2. Gra z komputerem zgadujacym liczbe         |\n");
 printf("3. Obliczanie podciagu - ciagu podanych liczb |\n");
 printf("4. Poznaj kilka cech podanych liczb 'x' i 'y' |\n");
 printf("5. Sortowanie podanego ciagu oraz jego suma   |\n");
 printf("-----------------------------------------------\n"); 
 printf("Jaki program chcesz uruchomic? Wpisz numer programu aby rozpoczac lub '0' \naby zakaczyc. \n");
 scanf("%d",&x);
if(x==0)
  return 0;
else if(x==1)
  {system("cls");
  gra();}
else if(x==2)
  {system("cls");
  zgadywanka();}
else if(x==3)
  {ciag();}
else if(x==4)
  {XY();}
else if(x==5)
  {ciag2();}
}}
 
 
