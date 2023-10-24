import random
from zad1 import xeuclid
from zad2 import ex2_op

# aby zrozumieć działanie algorytmu:
# https://www.youtube.com/watch?v=NOj-jNQfrd4&ab_channel=KhanAcademyPoPolsku
# http://www.algorytm.org/algorytmy-arytmetyczne/test-pierwszosci-test-fermata.html

# n - liczba której sprawdzamy pierwszość
# k - liczba powtórzeń testu (w celu zminimalizowanania ryzyka wylosowanie a "oszusta"
def test_Fermata(n, k):
    for _ in range(k):
        a = random.randrange(1,n-1)
        nwd,x,y = xeuclid(a,n)
        if nwd != 1:
            #print(f"nwd(a,p) = {nwd} != 1 Dowiedliśmy że p jest liczbą złożoną!")
            return False
        else:
            if ex2_op(a,n-1,n) != 1:
                #print(f"a^(p-1) mod p = {1} != 1. Dowiedliśmy że p jest liczbą złożoną")
                return False
    #print("pierwsza")
    return (True,f"with probability: {1-(1/(2**k))}")

if __name__ == "__main__":

    #Prime numbers
    p1 = 114813069527425452423283320117768198402231770208869520047764273682576626139237031385665948631650626991844596463898746277344711896086305533142593135616665318539129989145312280000688779148240044871428926990063486244781615463646388363947317026040466353970904996558162398808944629605623311649536164221970332681344168908984458505602379484807914058900934776500429002716706625830522008132236281291761267883317206598995396418127021779858404042159853183251540889433902091920554957783589672039160081957216630582755380425583726015528348786419432054508915275783882625175435528800822842770817965453762184851149030217
    p2 = 391391460710934952447744356920347432818302403303325591886976492807319896968025226937614034635791513888335717473023250182271798945302849615194243154049546831368896945330379987670475241933068594152537330597969762722659261563190456905695749170316137931922395119952663460471204126820352679225013665047263
    p3 = 8589934583
    p4 = 3213876088517980551083924184682325205044405987565585670602439

    #Composite numbers (liczby złożone)
    z1 = 8589934571
    z2 = 561 # 'a' fools: try test with small k ;)
    z3 = 3213876088517980551083924184682325205044405987565585670602429
    z4 = 511 # 'a' fools  try test with small k ;)

    print("##-- Prime numbers: --##")
    print(f"is p1 prime? {test_Fermata(p1, 20)}")
    print(f"is p2 prime? {test_Fermata(p2, 20)}")
    print(f"is p3 prime? {test_Fermata(p3, 20)}")
    print(f"is p4 prime? {test_Fermata(p4, 20)}")

    print("\n##-- Composite numbers --#")
    print(f"is z1 prime? {test_Fermata(z1, 20)}")
    print(f"is z2 prime? {test_Fermata(z2, 20)}")
    print(f"is z3 prime? {test_Fermata(z3, 20)}")
    print(f"is z4 prime? {test_Fermata(z4, 20)}")



