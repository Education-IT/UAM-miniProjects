Załączone jest również zdjęcie schematu automatów funkcji stateChanger() i errorDetector() oraz wskazanie jak czujniki
są położone - kiedy wiemy że zębatka kręci się w prawo czy w lewo w przypadku  mojego projektu. 

Największy problem sprawiła mi funkcja errorDetector():
a dokładniej jej wymyślenie. W jaki sposób będę sprawdzał i porawiał błędy. 
Chciałem do problemu podejść zbyt ambitnie przez co wiele sposobów było trudnych 
dla mnie w implementacji. Postanowiłem, że stosunkowo prostym i działającym pomysłem
będzie sprawdzanie wykrytytych ruchów w czasie nerwralgicznego momentu zmiany. 
Mój program patrzy, jaki był wcześniejszy stan, i zapamietajue aktualny, następuje odczyt kolejnego
stanu i sprawdzamy czy stan[-2] == aktualny stan. Jeśli tak to oznacza że stan po środku był błędny. 
Jeśli nie -> to oznacza że rzeczywiście zaszła zmiana kierunku ruchu.

Co należałoby dalej zrobić?
Zdecydowanie ten kod należy zacząć sprawdzać na żywym organiźmie. Zaimplementowac jego odpowiednik np.:
w microPython'ie i za pomocą odpowiednich detektorów i arduino zacząć działać i badać zachowania programu.
Można dodać do niego równiez porównywanie ruchu między innymi połączonymi zębatkami aby wyrówać szybkość,
kierunek obrotu.


Dziękuję za takie Otwartem ciekawe i problemowe zadania. Treść prosta - rozwiązanie nie w pełni trywialne.
Wykrycie oczywistych błędów było bardzo proste. Schody zaczynają się przy tych niespodziwanych błdach.
bo np.: ze stanów

HH - LL
HL - LH 
czy jak otrzymamy jakkolwiek zepsutu kod przez brak odczytu: "__" , "L_" , "H_" ipt itd
to poprostu nie pozwalamy na zmianę stanu.