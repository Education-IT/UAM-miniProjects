package Projekt.po;

import static org.junit.Assert.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;

import org.junit.Test;

public class ZapisywaniePliku_test {

	@Test
	public void test() throws IOException  {
		String miasto = "MIASTO";
		Map<String, String> testMAP = new HashMap<>();
		String test ="test";
		String test2 = "test2";
		testMAP.put(test, test2);
		 
		zapisPliku.zapisPliku(miasto, testMAP); //utworzenie przyk³adowego pliku z przyk³adowymi wartoœciami 
	
		assertTrue(Plik.czyPlikistnieje(miasto)); //sprawdzenie czy plik powsta³
		
		Path pathToFile = Paths.get("MIASTO.txt");
		Files.delete(pathToFile); //usuniecie pliku testowego
	}
	
}
