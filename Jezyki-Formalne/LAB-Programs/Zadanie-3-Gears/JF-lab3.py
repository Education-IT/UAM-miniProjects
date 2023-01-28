def errorDetector(gear_list,direc_list):
    constant = direc_list[0]
    change_index = 0
    change = 0
    index = -1

    for dir in direc_list:
       if dir != constant and change == 0:
           change = dir

       elif dir == constant and change != 0:
           change=0
           direc_list[index] = dir

       elif dir == change:
           constant = dir
           change = 0

       index += 1


def directionDetector(gear_list, direc_list):
    left = ["qLH", "qLL", "qHL", "qHH"]
    right = ["qLH", "qHH", "qHL", "qLL"]

    if len(gear_list) >= 2:
        indexL = left.index(gear_list[-1]) - 1
        indexR = right.index(gear_list[-1]) - 1

        if gear_list[-2] == left[indexL]:
            print("gear - left!")
            direc_list.append("Left")

        elif gear_list[-2] == right[indexR]:
            print("gear - right")
            direc_list.append("Right")


def stateChanger(currentState, read):
    if currentState == "qHH" or currentState == "qLL":
        if read != "HH" and read != "LL":
            return "q" + read
        else:
            return currentState

    elif currentState == "qHL" or currentState == "qLH":
        if read != "HL" and read != "LH":
            return "q" + read
        else:
            return currentState

    elif currentState == 0:
        return "q" + read

def main():
    currentState = 0
    gear_states_list = []
    direction_list = []
    file = open("states.txt", 'r')
    for read in file:
        result = read[0:2]
        currentState = stateChanger(currentState, result)
        if not gear_states_list or gear_states_list[-1] != currentState:
            gear_states_list.append(currentState)
            directionDetector(gear_states_list,direction_list)
        else:
            if len(gear_states_list) > 2:
                errorDetector(gear_states_list, direction_list)

    print(gear_states_list)
    print(direction_list)
    print()
    print("ERROR DETECTOR AVAILABLE:")
    # errorDetector(gear_states_list,direction_list)
    # print(0)
    # print(direction_list)
main()