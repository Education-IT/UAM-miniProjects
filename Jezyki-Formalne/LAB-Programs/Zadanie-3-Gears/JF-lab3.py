def errorDetector(direc_list,index,verification_list):
    constant = direc_list[0]
    change = 0

    for dir in direc_list[index:]: #wyrażenie regularne które powoduje, że przy każdorazowym wywołaniu funkcji -> nie przechodzimy po całej liście -> tylko zaczynamy od miejsca w którym ostatnio skończyliśmi

       if dir != constant and change == 0:
           change = dir

       elif dir == constant and change != 0:
           change = 0
           direc_list.pop(index - 1)
           verification_list[index - 1] += "Err!"

       elif dir == change:
           constant = dir
           change = 0

       index += 1

    return index - 1


def directionDetector(gear_list, direc_list,verification_list):
    left = ["qLH", "qLL", "qHL", "qHH"]
    right = ["qLH", "qHH", "qHL", "qLL"]

    if len(gear_list) >= 2:
        indexL = left.index(gear_list[-1]) - 1
        indexR = right.index(gear_list[-1]) - 1

        if gear_list[-2] == left[indexL]:
            #print("gear - left!")
            direc_list.append("Left") #Dodajemy te same elementy do 2 list ponieważ na jednej z nich będziemy dokonywać zmian. Operacja zrobiona po to aby ułatwić wizualnie zrozumienie programu. Na amym końcu wyswietlana jest zmieniona i niezmieniona lista
            verification_list.append("Left")

        elif gear_list[-2] == right[indexR]:
            #print("gear - right")
            direc_list.append("Right")
            verification_list.append("Right")


def stateChanger(currentState, read): #Tutaj dokonuje się po części detekcja i reakcja na błedy - oczywiste błędy takie jak np: nagła zmiana stanu z HH na LL (jest niemożliwa!) A więc zostajemy w tym samym stanie. To samo przy błędzie odczytu.
    if currentState == "qHH" or currentState == "qLL":
        if (read != "HH") and (read != "LL") and ("_" not in read):
            return "q" + read
        else:
            return currentState

    elif currentState == "qHL" or currentState == "qLH":
        if read != "HL" and read != "LH" and ("_" not in read):
            return "q" + read
        else:
            return currentState

    elif currentState == 0:
        return "q" + read

def main():
    currentState = 0
    currentIndex = 0
    gear_states_list = []
    direction_list = []
    verification_list = []
    file = open("states.txt", 'r')
    i = 0
    for read in file:
        currentState = stateChanger(currentState, read[0:2])  #Czytamy tylko dwa pierwsze symbole - dzięki temu w pliku z odczytami mogłem jawnie napisać gdzie umiesciłem błędy

        if not gear_states_list or gear_states_list[-1] != currentState: #Jeśli lista nie jest pusta i odtrzymany odczyt różni się od ostatniego:
            gear_states_list.append(currentState)
            directionDetector(gear_states_list,direction_list,verification_list)
            i += 1

        if len(gear_states_list) > 2 and i % 3 == 0: #Zaczynamy badac poprawność co 3 wprowadzone nowe stany do listy gear_states_list
            currentIndex = errorDetector(direction_list,currentIndex,verification_list)


    print("\nMovement list with ERRORS:")
    print(verification_list)
    print(f"list length: {len(verification_list)}")

    print("\nMovement list checked and repaird by ERROR DETECTOR:")
    print(direction_list)
    print(f"list length: {len(direction_list)}")

    print(f"\nThe difference between the lists indicates the number of incorrect\nand corrected motion readings. Errors number: {len(verification_list)-len(direction_list)}")

main()