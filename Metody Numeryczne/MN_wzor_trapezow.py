
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

    h = ((end - start)/n)
    
    print('krok = '+str(h))
    suma = 0
    for i in range(1,n):
        x = start + i*h
        y = f(x)
        suma = suma + y
        print('wartosc kwadratura w f(x'+str(i)+') wynosi: '+str(y))

    wynik = 0.5 * h * (f(start) + 2*suma + f(end))
    print('(WZOR TRAPEZOW -> Przyblizona wartosc calki wynosi = '+str(wynik))


main()
    


