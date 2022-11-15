package Projekt.po;

class suma_kontrolna {

	static boolean test(String pesel)
	{ int[] waga_liczby = {1,3,7,9,1,3,7,9,1,3};
	int suma_kontrolna = 0;
	int cyfra_kontrolna =Integer.parseInt(pesel.substring(10,11));
	int y;
	 for(y=0;y<10;y++)
	 {
		 suma_kontrolna = suma_kontrolna + Integer.parseInt(pesel.substring(y,y+1)) * waga_liczby[y];
		 
	 }
	suma_kontrolna = suma_kontrolna %10;
	suma_kontrolna = 10 - suma_kontrolna;
	suma_kontrolna = suma_kontrolna %10;
	
	if(suma_kontrolna == cyfra_kontrolna)
		return true;
		else
			return false;
	}
	
	
	
	
}
