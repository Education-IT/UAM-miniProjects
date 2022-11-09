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
		
	
		
		System.out.println("Podaj nazwê miasta:");
		String miasto =  scanner.nextLine();
		
		while(Plik.czyPlikistnieje(miasto))
		{
			System.out.println("Dla podanego przez Ciebie miasta istnieje ju¿ plik! Napisz listê dla nowego miasta:");
			System.out.println("Podaj nazwê miasta:"); 
			miasto =  scanner.nextLine();
			
		}
		
		
		System.out.println("\nWpisujesz listê mieszkañców dla miasta " + miasto);
		System.out.println("------------------------------------");
		System.out.println("\nPodaj imiê, nazwisko oraz pesel mieszkañca");
		
		while(true)
		{ 
			 mieszkaniec = scanner.nextLine();
			String[] podzial = mieszkaniec.split(" ");
			
	
			
			switch (podzial.length) {
           
			case 1:
            	if(podzial[0]=="")
            		{System.out.println("Nie poda³eœ ¿adnej wartoœci!");
            		continue;}
                System.out.println("Nie poda³eœ nazwiska i peselu!");
                continue;
            case 2:
                System.out.println("Nie poda³eœ peselu!");
                continue;
           
        }
			
			try {
				testlong = podzial[2];
				Long v  = Long.parseLong(testlong);	
				
			}
			
			catch(java.lang.NumberFormatException exception)
			{
				System.out.println("B³êny numer pesel! Znajduj¹ siê w nim litery! Wpisz jeszcze raz wszytskie dane mieszkañca");
				System.out.println("Czy chcesz kontynuowaæ wypisywanie listy mieszkañców? Napisz [0/1]");
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
				{System.out.println("Niepoprawny numer pesel! Upewnij siê, ¿e wpisujesz prawid³owy!");
				System.out.println("Czy chcesz kontynuowaæ wypisywanie listy mieszkañców? Napisz [0/1]");
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
			System.out.println("Pesel wpisanego przez Ciebie mieszkañca, nie przeszed³ testu sumy kontrolnej ostatniej cyfry. Wpisz jeszcze raz wszytskie dane mieszkañca lub zacznij od kolejnego");
			System.out.println("Czy chcesz kontynuowaæ wypisywanie listy mieszkañców? Napisz [0/1]");
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
			
			
			
			System.out.println("Czy chcesz kontynuowaæ wypisywanie listy mieszkañców? Napisz [0/1]");
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
