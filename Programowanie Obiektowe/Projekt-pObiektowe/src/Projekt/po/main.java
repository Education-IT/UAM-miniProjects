package Projekt.po;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class main {

	public static void main(String[] args) throws FileNotFoundException  {
		Scanner scanner = new Scanner(System.in);
		Map<String, String> lista_mieszkancow = new HashMap<>();
		String pesel;
		String testlong;
		String mieszkaniec;
		byte x;
		
	
		
		System.out.println("Podaj nazw� miasta:");
		String miasto =  scanner.nextLine();
		
		while(Plik.czyPlikistnieje(miasto))
		{
			System.out.println("Dla podanego przez Ciebie miasta istnieje ju� plik! Napisz list� dla nowego miasta:");
			System.out.println("Podaj nazw� miasta:"); 
			miasto =  scanner.nextLine();
			
		}
		
		
		System.out.println("\nWpisujesz list� mieszka�c�w dla miasta " + miasto);
		System.out.println("------------------------------------");
		System.out.println("\nPodaj imi�, nazwisko oraz pesel mieszka�ca");
		
		while(true)
		{ 
			 mieszkaniec = scanner.nextLine();
			String[] podzial = mieszkaniec.split(" ");
			
	
			
			switch (podzial.length) {
           
			case 1:
            	if(podzial[0]=="")
            		{System.out.println("Nie poda�e� �adnej warto�ci!");
            		continue;}
                System.out.println("Nie poda�e� nazwiska i peselu!");
                continue;
            case 2:
                System.out.println("Nie poda�e� peselu!");
                continue;
           
        }
			
			try {
				testlong = podzial[2];
				Long v  = Long.parseLong(testlong);	
				
			}
			
			catch(java.lang.NumberFormatException exception)
			{
				System.out.println("B��ny numer pesel! Znajduj� si� w nim litery! Wpisz jeszcze raz wszytskie dane mieszka�ca");
				System.out.println("Czy chcesz kontynuowa� wypisywanie listy mieszka�c�w? Napisz [0/1]");
				 x = scanner.nextByte();
				 if (x == 1)
					{scanner.nextLine(); continue;}
						else 
							if(!(lista_mieszkancow.size()>0))
								return;
							else 
								break;
				 
			}
			
			
	
			
		pesel = podzial[2];
			
			
		
			if (pesel.length()!=11)
				{System.out.println("Niepoprawny numer pesel! Upewnij si�, �e wpisujesz prawid�owy!");
				System.out.println("Czy chcesz kontynuowa� wypisywanie listy mieszka�c�w? Napisz [0/1]");
				 x = scanner.nextByte();
				 if (x == 1)
					{scanner.nextLine(); continue;}
						else 
							if(!(lista_mieszkancow.size()>0))
								return;
							else 
								break;
				}
		
				
			
			if(!suma_kontrolna.test(pesel))
			{
			System.out.println("Pesel wpisanego przez Ciebie mieszka�ca, nie przeszed� testu sumy kontrolnej ostatniej cyfry. Wpisz jeszcze raz wszytskie dane mieszka�ca lub zacznij od kolejnego");
			System.out.println("Czy chcesz kontynuowa� wypisywanie listy mieszka�c�w? Napisz [0/1]");
			 x = scanner.nextByte();
			 if (x == 1)
				{scanner.nextLine(); continue;}
					else 
						if(!(lista_mieszkancow.size()>0))
							return;
						else 
							break;
			}
			
			
			lista_mieszkancow.put(pesel, mieszkaniec);
			
			
			
			System.out.println("Czy chcesz kontynuowa� wypisywanie listy mieszka�c�w? Napisz [0/1]");
			 x = scanner.nextByte();
			if (x == 1)
			{scanner.nextLine(); continue;}
				else 
					if(!(lista_mieszkancow.size()>0))
						return;
					else 
						break;
		}
			
		zapisPliku.zapisPliku(miasto, lista_mieszkancow);
	}
}
