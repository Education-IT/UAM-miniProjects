package Projekt.po;
import static org.junit.Assert.*;
import org.junit.Test;



public class peselTest {

	@Test
	public void test_suma_kontrolna()  {
	
	assertTrue(suma_kontrolna.test("55030101230")); //poprawny pesel
	
	assertFalse(suma_kontrolna.test("98060705754")); //b³êny pesel
	
	}
	
	@Test(expected = Exception.class)
    public void StringTest() throws Exception {
        suma_kontrolna.test("PeselZliter"); // brak peselu tylko litery
    }
	
	}
	


