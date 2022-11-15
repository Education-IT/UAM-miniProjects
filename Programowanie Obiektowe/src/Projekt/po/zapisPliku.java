package Projekt.po;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Map;

class zapisPliku {

	static void zapisPliku(String miasto,Map<String, String> lista_mieszkancow) throws FileNotFoundException {
		
		
		File plik = new File(miasto+".txt");
		PrintWriter zapis = new PrintWriter(miasto+".txt");
		for(String value : lista_mieszkancow.values()) {
		    zapis.println(value);
		    
		}
		
		zapis.close();
		
		
	}
	
}
