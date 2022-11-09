import numpy

def main():
    stopien = -1
    matrix = [] # pozniej to będzie U
    L = []
    U = []
    i,j,k = 0,0,0
   
    print('#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#--#')
    print('#-- Obliczanie macierzy odwrotnej do podanej macierzy ---#')
    print('#--#--#--#--#--#--# Krystian Osiński --#--#--#--#--#--#--#')
    print()

    #======================================================================================================
    # Podanie macierzy wejściowej (A)
    while stopien > 10 or stopien < 1:
        stopien = int(input('Podaj stopien macierzy kwadratowej od 1 do 10 = '))

    I = numpy.identity(stopien) # stworzenie macierzy identycznościowej
    forward = numpy.zeros((stopien,stopien))  #\
                                               #} stworzenie macierzy danego stopnia i wypełnienie ich zerami
    backward = numpy.zeros((stopien,stopien)) #/

    for i in range(stopien):
        m = []
        for j in range(stopien):
            j=float(input('Wprowadź element w ' + str(i+1) + ' wierszu i w ' + str(j+1) + ' kolumnie: '))
            m.append(j)

        print('-----------------------------------------')
        matrix.append(m)
   
    print('Twoja macierz wygląda następująco')
    for i in range(stopien):
        for j in range(stopien):
            
            print(matrix[i][j],end=" ")
        print()
    print()
    print()
    
    #======================================================================================================
    # Sprawdzenie czy macierz jest odwracalna (osobliwa/nieosobliwa) oraz wykonanie zadania za pomocą biblioteki numpy
    det = numpy.linalg.det(matrix)
    print('Wyznacznik Twojej macierzy wynosi = '+str(det))
    if det != 0:
        print('A wiec jest to macierz nieosobliwa = istnieje macierz odwrotna')
    else:
        print('Jest to macierz osobliwa a wiec nie jestesmy w stanie oblicz jej macierzy odwrotnej')
        return 0
    print('--------------------------------------')
    
    print('Obliczona macierz odwrotna za pomocą biblioteki NUMPY wynosi:')
    print(numpy.linalg.inv(matrix))
    print()
    print()

    
    #======================================================================================================
    # Wyliczenie macierzy L(lower) i U(uper) oraz ich ukazanie
    # Tworzmy L i za razem zmieniamy stan macierzy 'matrix' - w wyniku czego macierz 'matrix' staje się naszym U
    po = 0
    for i in range(stopien):
        l = []
        for j in range(stopien):
            if j > i:
                l.append(0)
            elif j==i:
                l.append(1)
            else: 
                if matrix[j][j]==0: # aby nie dzielić przez zero!
                    matrix[j][j]=1
                    po = 1
                q = matrix[i][j]/matrix[j][j]
                l.append(q)
                if po == 1:
                    po = 0
                    matrix[j][j]=0
                for k in range(stopien):
                    matrix[i][k] = matrix[i][k] - ( matrix[j][k] * q )
        L.append(l)

    print('--- Twoja macierz L! wygląda następująco ---')
    for i in range(stopien):
        for j in range(stopien):
            
            print(L[i][j],end=" ")
        print()
    print()
    print()

    print('--- Twoja macierz U! wygląda następująco ---')
    for i in range(stopien):
        for j in range(stopien):
            
            print(matrix[i][j],end=" ")
        print()
    print()
    print()
    
    #======================================================================================================
    # Wyliczenie macierzy odwrotnej przy użyciu L i macierzy identycznościowej - za pomocą podstawiania do przodu
    
    for k in range (stopien):
        for i in range(stopien):
            suma = 0
            for j in range(i):
                suma = suma + L[i][j] * forward[j][k]

            forward[i][k] = (I[i][k]-suma)/L[i][i]

    print('--- Twoja macierz Po podstawieniu w przod - wygląda następująco ---')
    for i in range(stopien):
        for j in range(stopien):
            print(forward[i][j],end=" ")
        print()
    print()
    print()

    #======================================================================================================
    # Wyliczenie macierzy odwrotnej przy użyciu U i macierzy utworzonej podczas podstawiania do przodu - za pomocą podstawiania do tyłu
        
    for k in range (stopien):
        for i in range(stopien-1,-1,-1):
            suma = 0
            for j in range(i+1,stopien):
                suma = suma + matrix[i][j] * backward[j][k]

            backward[i][k] = (forward[i][k]-suma)/matrix[i][i]
    
    print('#---#---#---#---#---#---#---#---#')
    print('#--- MACIERZ ODWROTNA WYNOSI ---#') #Wynik jest już naszą macierzą odwrotną
    print('#---#---#---#---#---#---#---#---#')
    print()
    
    for i in range(stopien):
        for j in range(stopien):
            print(backward[i][j],end=" ")
        print()
    
    print()
    print('#---#---#---#---#---#---#---#---#')
            
main()
        
    


