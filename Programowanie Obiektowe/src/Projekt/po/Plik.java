package Projekt.po;

import java.io.File;

public class Plik {

	static boolean czyPlikistnieje(String miasto)
	{
	
		        File plik = new File(miasto + ".txt");
		        
		        return plik.exists() && plik.isFile();
		        
		    
	}
	
	
	
	
	
}
