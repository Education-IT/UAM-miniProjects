

def funkcja(aih,f):
    wynik = f(aih)
    return wynik
    
def main():
    start = float(input('-- Podaj poczatek przedzialu pochodnej (wezel X0): '))
    start_x = float(input('-- Podaj wartosc funkcji w f(x0) (wezel x0): '))

    end = float(input('-- Podaj poczatek przedzialu pochodnej (wezel Xn): '))
    end_x = float(input('-- Podaj wartosc funkcji w f(xn)(wezel xn): '))

    n = int(input('-- Podaj ilosc podprzedzialow: '))
    funkcja = input('Podaj funckję f(x) = ')
    f = lambda x: eval(funkcja)

    h = ((end - start)/(2*n))
    
    print('krok = '+str(h))
    suma = 0
    suma2 =0
    for i in range(1,2*n):
        x = start + i*h
        y = f(x)
        if i%2 != 0:
            suma = suma + y
            print('wartosc kwadratury w f(x'+str(i)+') wynosi: '+str(y))
        else:
            suma2 = suma2 + y
            print('wartosc kwadratury w f(x'+str(i)+') wynosi: '+str(y))

    wynik =  (h/3) * (f(start) + 4*suma + 2*suma2 + f(end))
    print('(ZLOZONY WZOR PARABOL -> Przyblizona wartosc calki wynosi = '+str(wynik))


main()
    


