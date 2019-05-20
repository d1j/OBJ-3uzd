
# v1.1
---
## **_Naudojimosi instrukcijos_**

Kompiliuoti naudojant `make` arba "ranka" 
`g++ -o main main.cpp funkcijos.cpp apdorojimas.cpp generavimas.cpp mokinys.cpp`

## **_Pastebėjimai_**

Kodas buvo perdarytas taip, kad dabartinė mokinio duomenų struktūra saugo galutinį balą pagal medianą ir pagal vidurkį. Galutiniai balai apskaičiuojami failo skaitymo metu. Tai, ko gero, yra priežastis, kodėl failo skaitymas nesutrumpėjo. 

## **_Analizė_**

|                   | Failo skaitymas | Rikiavimas | Skaidymas | Išvedimas (į failus) |
| ----------------- | --------------- | ---------- | --------- | -------------------- |
| v1.0  10 000      | 0.140669s       | 0.062239s  | 0.015656s | 0.155142s            |
| v1.1  10 000 -o0  | 0.140233s       | 0.109413s  | 0.01561s  | 0.140645s            |
| v1.1  10 000 -o1  | 0.140659s       | 0.108961s  | 0.031679s | 0.163168s            |
| v1.1  10 000 -o2  | 0.124716s       | 0.109398s  | 0.031248s | 0.17151s             |
| v1.1  10 000 -o3  | 0.140362s       | 0.109125s  | 0.015631s | 0.178083s            |
| v1.0  100 000     | 1.20321s        | 0.609582s  | 0.140357s | 1.16144s             |
| v1.1  100 000 -o0 | 1.15662s        | 1.23474s   | 0.156282s | 1.17665s             |
| v1.1  100 000 -o1 | 1.15632s        | 1.23475s   | 0.155668s | 1.20348s             |
| v1.1  100 000 -o2 | 1.15633s        | 1.23446s   | 0.155914s | 1.18746s             |
| v1.1  100 000 -o3 | 1.13987s        | 1.21883s   | 0.156304s | 1.18133s             |

# v1.2
---
## **_Naudojimosi instrukcijos_**

Kompiliuoti naudojant `make` arba "ranka" 
`g++ -o main main.cpp funkcijos.cpp apdorojimas.cpp generavimas.cpp mokinys.cpp`

## **_Realizuoti operatoriai_**

* << Išveda resultatus į failą
* .>> Įveda duomenis iš failo į objektą
* == Patikrina ar dviejų mokinių vardas ir pavardė sutampa
* != Patikrina ar dviejų mokinių vardas ir pavardė nesutampa
* = Priskirai r-value arba l-value reikšmę

# v1.5
---

Bazinė klasė - zmogus.h
Derived klasė - mokinys.h