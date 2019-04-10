### Mokinių rezultatų skaičiavimo programa

---

**PERSPĖJIMAS!!!**

Kadangi _readme.md_ ir _makefile_ v0.1 - v0.4 versijoms kūriau tas visas versijas įgyvendinęs, _readme.md_ failuose gali būt "balaganas".

**readme.md** failas daugiausia informacijos apie ankstesnes versijas turės **"master branch'e"**. Readme failuose, pateiktuose su releasais, gali trūkti informacijos arba gali pasitaikyti klaidingos informacijos.

**Nagrinėjant skirtingus releasus, patartina naudotis tik šituo readme failu.**

---

# [v0.1](https://github.com/d1j/OBJ-Duomenu-apdorojimas/releases/tag/v0.1)

---

## **_Naudojimosi instrukcijos_**

Kompiliuoti programą galima rankiniu būdu arba naudojant **make** komandas.

`make v1` sukompiliuos programą (`v1.exe`), kuri veikia panaudojant C-tipo masyvus.
`make v2` sukompiliuos programą (`v2.exe`), naudojančią `std::vector` konteinerius.

Paleidus programą, atidžiai sekti programos nurodymus.

## **_Pastebėjimai_**

_main_v1.cpp_ faile duomenims saugoti panaudoti C-tipo masyvai. Duomenys apie mokinį saugomi _linked_list'e_, sudarytame iš struktūros `mokinys` (taip, pavadinimas turėtų būti `studentas`, tačiau savo klaidą supratau padaręs v0.3 versiją :D...). Sunkiai paaiškinsiu, kodėl pasirinkau mokinius saugoti _linked_list'e_, tačiau užduotis jau padaryta ir nelabai ką norisi keisti. Struktūra mokinys turi dinaminį pažymių masyvą, kurio reikalauja užduotis.

_main_v2.cpp_ faile duomenims saugoti panaudoti vien tik `std::vector` konteineriai (tiek mokinių masyvas, tiek pažymių masyvai). Pakeitus _linked_list'ą_ ir C masyvus vektoriais, kodas tapo žymiai paprastesnis ir sutrumpėjo 100 eilučių, smagu.

---

# [v0.2](https://github.com/d1j/OBJ-Duomenu-apdorojimas/releases/tag/v0.2)

---

## **_Naudojimosi instrukcijos_**

Paleisti programą galima sukompiliavus _main_v2.cpp_ ranka arba naudojant `make` (arba `make v2`) komandą.

Šioje versijoje pridėtas duomenų skaitymo iš failo funkcionalumas.

- Skaitomas failas turi būti toje pačioje direktorijoje kaip ir vykdoma programa.
- Duomenų failo pavadinimas privalo būti _duomenys.txt_ (tolimesnėse versijose failo pavadinimas galės būti bet koks).
- Duomenys turi būti griežtai struktūrizuoti (pavyzdys _duomenys.txt_ faile).

Duomenų failo formatas:

- Pirmas skaičius - mokinių skaičius.
- Antras skaičius - skaičius, nurodantis, kiek namų darbų pažymių turi kiekvienas mokinys.
- Sekančiose eilutėse surašyti duomenys apie mokinius.

> 4 5  
> Vardas1 Pavarde1 8 9 10 6 10 9  
> Vardas2 Pavarde2 7 10 8 5 5 6  
> Vardas3 Pavarde3 8 9 10 6 10 9  
> Vardas4 Pavarde4 1 10 8 5 4 6

## **_Pastebėjimai_**

Iš naudojimosi instrukcijų savaime aišku, jog duomenų skaitymas iš failo nėra nei patogus, nei lankstus, tačiau daugelį problemų išsprendžiau ir skaitymą patobulinau vėlesnėse projekto versijose.

Šioje versijoje atsiranda galimybė rikiuoti mokinius pagal jų vardus arba pavardes.

---

# [v0.3](https://github.com/d1j/OBJ-Duomenu-apdorojimas/releases/tag/v0.3)

---

## **_Naudojimosi instrukcijos_**

Nuo šios versijos patogiausia programą kompiliuoti naudojant komandą `make` (arba `make v2`).

Duomenų failo formatas išlieka toks pats kaip v0.2 versijoje, tačiau failo pavadinimas gali keistis. Programoje reikia nurodyti failo pavadinimą.

## **_Pastebėjimai_**

_main_v2.cpp_ failo funkcijos ir struktūra buvo išskaidyta į atskirus failus. Nuo šiol _main_v2.cpp_ yra tik main funkcija, kurioje paprastas išorinių funkcijų manipuliavimas; _funkcijos.cpp_ faile laikomos pagrindinės funkcijos, kurių pagalba apdorojami duomenys; Į _mokinys.h_ buvo perkelta struktūra `mokinys`, o struktūros metodai laikomi _mokinys.cpp_ faile.

Panaudoti `try-catch` blokai, kurie nuo šiol gelbėja programą nuo "crashinimo" skaičiuojant vidurkius, medianas bei skaitant duomenų failus.

Patobulintas _makefile_ pagal "tutorialą" [šioje svetainėje](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/).

---

# [v0.4](https://github.com/d1j/OBJ-Duomenu-apdorojimas/releases/tag/v0.4)

---

## **_Naudojimosi instrukcijos_**

Programą kompiliuojame komandos `make` (arba `make main`) pagalba. Paleidus programą, sekti instrukcijas.

Programos vykdymui būtini `\duomenys` bei `\rezultatai` folderiai. **Šių folerių netrinti!**

Folderyje `\duomenys` saugomi duomenų failai, tad, testuojant programą, failus kelti čia. Rezultatus rasite folderyje `\rezultatai`. _PASTABA: nurodant rezultatų failo pavadinimą, nurodyti reikia tik failo vardą, programa automatiškai parenka .txt formatą (įvedus pavadinimą "rez" bus segeneruojami failai "rez_kiet.txt" ir "rez_varg.txt")_.

Generuojant duomenų failus pagal `2. Generuoti duomenis` bus sugeneruotas jusų nurodytas skaičius mokinių, su pažymiais, kurių kiekis skiriasi nuo 1 iki 20 (Pavyzdys `\duomenys\100.txt` faile). _PASTABA: norint generuoti daugiau pažymių, reikia keisti programos kodą faile `generavimas.h`_.

**Failas `\duomenys\100.txt` greičiausiai neveiks dėl platformų skirtumo, todėl patariama jo nenaudoti.**

Nuo šios versijos atsiranda galimybė ranka suvestus duomenis išsaugoti rezultatų failuose.

## **_Pastebėjimai_**

- _main_v2.cpp_ pervadintas į _main.cpp_. Pasikeitė _main.cpp_ struktūra;
- nuo šiol `make` kompiliuoja failą pavadinimu _main.exe_;
- _funkcijos.h_ faile aprašomos bendros funkcijos (įvesties, skaičių generavimo, failų egzistavimo tikrinimo ir t.t.), naudojamos visuose failuose.
- _apdorojimas.cpp_ faile randasi didžioji dalis funkcijų, skirtų mokinių rezultatų apdorojimui (Kai kurios rezultatų skaičiavimo funkcijos yra struktūros `mokinys` metodai, saugomi *mokinys.cpp* faile)
- _generavimas.h_ aprašyta funkcija, kurios pagalba galime sugeneruoti duomenų failus.
- pamiršau padaryt galimybę vartotojui nurodyti, kiek daugiausia pažymių mokinys gali turėti (defaultinės reikšmės: min-1; max-20).

## **_Analizė_**
Pastaba: Programa sukurta taip, jog į *failo skaitymo* laiką įeina ir n.d. vidurkio bei medianos skaičiavimas, o *išvedimo į failą* laiką įeina galutinio rezultato skaičiavimas.

| Mokinių skaičius | Failo generavimas | Failo skaitymas | Rikiavimas | Išvedimas (į failus) | Viso      |
| ---------------- | ----------------- | --------------- | ---------- | -------------------- | --------- |
| 100              | 0.019736s         | 0.00498s        | 0.003001s  | 0.034002s            | 0.061719s |
| 1000             | 0.041904s         | 0.035984s       | 0.048022s  | 0.079989s            | 0.205899s |
| 10000            | 0.208012s         | 0.29104s        | 0.511567s  | 0.337026s            | 1.347645s |
| 100000           | 2.00921s          | 2.6623s         | 6.64547s   | 3.16874s             | 14.48572s |
| 1000000          | 19.5229s          | 27.1462s        | 79.8309s   | 32.4162s             | 158.9162s |
| 10000000         | std::bad_alloc    | -               | -          | -                    | -         |
Testai atlikti su tokiais parametrais: 
```c++
#define min_paz_sk 1
#define max_paz_sk 20
```
```
mokinių rikiavimas pagal VARDĄ
rezultatų skaičiavimas pagal VIDURKĮ
```

Primityviai mąstant, viso proceso (nuo duomenų generavimo iki duomenų išvedimo) laikas turi kisti tiesiogiai proporcingai didėjant duomenų skaičiui x10, tačiau taip nėra dėl keleto priežasčių:
* kai mokinių skaičius yra nedidelis (100, 1000 ar 10000), viso laiko atžvilgiu duomenų failų ir rezultatų failų sukūrimas užima daugiausia laiko. Todėl ir bendras laikas iš 100 mokinių į 1000 padidėja x3.33 (0.205899s/0.061719s) karto, o iš 1000 į 10000 - x6.54 karto.
* didėjant duomenų skaičiui, laikas, atidarant ir kuriant failus, tampa nereikšmingas, tačiau programos veikimo laikas visgi nedidėja x10 karto; laiko didėjimas tampa ~x11 kartų. Taip greičiausiai yra dėl to, kad naudojamas `std::sort` algoritmas, kurio sudėtingumas yra _O(n log n)_, todėl matome, kad didėjant duomenų skaičiui, rikiavimo trukmė daugmaž didėja x12 kartų. Kadangi rikiavimas užima daugiausia laiko programos veikime, dėl to visos programos veikimo laikas ir keičiasi x11 karto.
* pabandžius sugeneruoti failą su 10 000 000 mokinių, kompiuteris neatlaikė įtampos.

---

# v0.5

---
## **_Naudojimosi instrukcijos_**
Padaręs v0.4 versiją, iššakojau projektą į 3 papildomas šakas: 
* `v0.5/v1.0vector` šakoje įgyvendinta v0.5 versija su `std::vector` konteineriais,
*  `v0.5/v1.0list` šakoje įgyvendinta su `std::list` konteineriais,
*  `v0.5/v1.0deque` šakoje projektas įgyvenditas su `std::deque` konteineriais

`v0.5/v1.0vector` ir `v0.5/v1.0deque` kodas skiriasi tik tuo, kad visur *vector* buvo pakeista į *deque*, tad projektą releasinsiu tik su [std::vector](https://github.com/d1j/OBJ-Duomenu-apdorojimas/releases/tag/v0.5vec) ir [std::list](https://github.com/d1j/OBJ-Duomenu-apdorojimas/releases/tag/v0.5list) konteineriais.

Iš esmės programos funkcionalumas ir naudojimosi taisyklės nepakito, tad, kaip naudotis, žiūrėti į v0.4 ir ankstesnių versijų naudojimosi aprašus.


## **_Pastebėjimai_**

Programa mažai kuo pakito nuo v0.4 versijos. Šiokie tokie pokyčiai matomi v0.5 įgyvendinime su `std::list` konteineriais, kadangi šis konteineris neuturi `[]` "random access" operatoriaus. Todėl teko panaudoti ir pritaikyti `std::iterator` ir `std::next` funkcionalumus.

## **_Analizė_**
Pastaba: Programa sukurta taip, jog į *failo skaitymo* laiką įeina ir n.d. vidurkio bei medianos skaičiavimas, o *išvedimo į failą* laiką įeina galutinio rezultato skaičiavimas. Todėl negalėjau neįskaičiuoti *išvedimo į failus* laiko, kaip prašo užduotis.

| Konteinerio tipas | Failo skaitymas | Rikiavimas | Išvedimas (į failus) | Viso      |
| ----------------- | --------------- | ---------- | -------------------- | --------- |
| std::vector       | 1.16217s        | 2.76823s   | 1.27052s             | 5.20092s  |
| std::list         | 1.99002s        | 0.218764s  | 1.6116s              | 3.820384s |
| std::deque        | 1.16457s        | 4.92085s   | 1.42958s             | 7.515s    |

Testai atlikti su tokiais parametrais: 
```c++
#define min_paz_sk 1
#define max_paz_sk 20
```
```
mokinių skaičius 100 000
mokinių rikiavimas pagal VARDĄ
rezultatų skaičiavimas pagal VIDURKĮ
```

Gauti failo skaitymo (į kurį įeina rezultatų dalinis skaičiavimas) ir rezultatų išvedimo laiko rezultatai nenustebino - matomi vietomis šiek tiek reikšmingi, o kai kur visai nereikšmingi pokyčiai, naudojant skirtingus konteinerius. Tačiau keisti pasirodė rikiavimo laiko pokyčiai, kadangi visiems konteineriams naudojau standartines `std::sort` bei `list::sort` rikiavimo funkcijas ir rezultatai neturėjo taip drastiškai skirtis. Greit supratau, kad problema kode: nuo pat pradžių į pagalbines rikiavimui skirtas funkcijas `rikVard` ir `rikPavard` buvo paduodamos kintamųjų kopijos, o perdarydamas kodą su `std::list` gavau klaidą naudodamas tas funkcijas, todėl jas pertvarkiau, kad kintamieji būtų paduodami pagal adresą. 

Rezultatai po klaidos ištaisymo:

| Konteinerio tipas | Failo skaitymas | Rikiavimas | Išvedimas (į failus) | Viso      |
| ----------------- | --------------- | ---------- | -------------------- | --------- |
| std::vector       | 1.15691s        | 0.622723s  | 1.33029s             | 3.109923s |
| std::deque        | 1.11233s        | 0.798517s  | 1.39263s             | 3.303477s |
| std::list         | 1.99002s        | 0.218764s  | 1.6116s              | 3.820384s |

Išvados: 
* Mano programos veikimo atžvilgiu naudingiausia naudoti `std::vector` konteinerį, kadangi šis konteineris stipriai pranoksta `std::list`, kuomet duomenys po vieną pridedami į konteinerio galą (failo skaitymas) arba yra vienas po kito pasiekiami (iteruojami) ir naudojami (išvedimas į failus, rezultatų skaičiavimas). Panašius rezultatus šioj srity parodo `std::deque`, tačiau `std::vector` pastarąjį pranoksta rikiavime, kuris trunka mažiau greičiausia dėl konteinerio adresų paskyrimo. Kiek supratau, `std::vector` konteineris paskiria vieną nuoseklų gabalą atminties RAM'e, o `std::deque` paskiria atmintį atskirais gabalais, kurie gali būti išmėtyti po atmintį skirtingose vietose. Todėl rikiuojant ko gero greičiau nustatoma `std::vector` elemento vieta atminty, negu `std::deque`
* Nors ir `std::list` vienareikšmiškai greičiausias duomenų rikiavime, jo naudoti neapsimoka, nes duomenys turi kažkaip atsidurt konteineryje, o matyti, jog `std::list` nėra geriausias sprendimas tą padaryti.
* `std::list` pranoksta kitus konteinerius rikiavime, dėl to, kad adresų išdėstymo struktūra kardinaliai skiriasi: `std::list` dažniausiai implementuojamas kaip *doubly-linked list'as*, todėl elementai yra išmėtyti po atmintį ir yra tarpusavy susieti nuorodomis į gretimų elementų adresus. Šis skirtumas leidžia elementus apkeisti pakeičiant adresų sąsajas, o `std::vector` ir `std::deque` reikia perkopijuoti visą elementų informaciją, nes keisti adresų negalime dėl griežtos konteinerių struktūros.

---

# v1.0

---
## **_Naudojimosi instrukcijos_**

**PASTABA! Kadangi ši versija skirta analizuoti skirtingus konteinerius ir jų naudojimosi įpatumus, programą perdarinėjau skirtingoms strategijoms tik tiek, kad būtų galimą atlikti testus ir palyginti rezultatus. Tai reiškia, kad rezultatų v0.2 išvedimas į konsolės langą neveiks tinkamai.**

Man atrodo, kad kurti ir analizuoti atskirus šios versijos releasus bus nepatogu ir painu, todėl jų nekursiu.

Pirmos strategijos kodą galima peržiūrėti klonuojant repozitoriją ir nuėjus į "branch'ą" [v1.0_1strat](https://github.com/d1j/OBJ-Duomenu-apdorojimas/tree/v1.0_1strat). Jame nueiti į "commit'ų log'ą" ir atitinkamai susirasti norimą "commit'ą" pagal komentarus. Šiame "branch'e" "commit'inau" tokia eilės tvarka: kodas su `std::list` -> kodas su `std::vector` -> kodas su `std::deque`

Antros strategijos kodą taip pat galima peržiūrėti klonuojant repozitoriją ir nuėjus į "branch'ą" [v1.0_2strat](https://github.com/d1j/OBJ-Duomenu-apdorojimas/tree/v1.0_2strat). Jame nueiti į "commit'ų "log'ą" ir atitinkamai susirasti norimą "commit'ą" pagal komentarus. Šiame "branch'e" "commit'inau" tokia eilės tvarka: kodas su `std::list` -> kodas su `std::vector` -> kodas su `std::deque`

Kodą su pritaikytais `std` algoritmais galima rasti "branch'e" [v1.0_2strat_vector](https://github.com/d1j/OBJ-Duomenu-apdorojimas/tree/v1.0_2strat_vector)

Trečioji strategija (mano pirminė strategija) yra releasinta v0.5 versijoje.

## **_Pastebėjimai_**
* Supratau, kad norint atlikti kuo tikslesnį laiko matavimą, reikia pašalinti visus nereikalingus "background'o" procesus ir tuos pačius bandymus atlikti keletą kartų, išvestį rezultatų vidurkį. Tą supratęs perspėju, kad tiek praetų versijų rezultatai tiek tolimesni rezultatai gali būti iškraipyti "muzikos klausymosi naudojant chrome'ą" ir kitokių pašalinių veiklų. Tolimesnius bandymus stengiausi atlikti neapkraunant kompiuterio pašaliniais procesais.
* Pasirinktas skaičius mokinių nėra idealus variantas testavimui, kadangi skirtingų testų metu laikai skyrėsi netgi 0.05 sekundės, kas yra ganėtinai daug ~1 sekundės atžvilgiu.
* Galutinis kodas turi dar daug trūkumų, toli gražu nėra tobulas. Vienas iš pavyzdžių, ką turiu galvoje:
* ```c++
  //kodas, kurį naudojau su std::list konteineriais
  esamas.egz = *--esamas.pazym.end();
  //kodas, kurį naudojau su std::vector konteineriais
  esamas.egz = esamas.pazym[esamas.pazym.size() - 1];
  //kodas, kurį reikėjo naudoti abiem atvėjais
  esamas.egz = esamas.pazym.back();
  ```
 

## **_Analizė_**

| Konteinerio tipas    | Failo skaitymas | Rikiavimas | Skaidymas        | Išvedimas (į failus) | Viso        |
| -------------------- | --------------- | ---------- | ---------------- | -------------------- | ----------- |
| std::vector 1 strat. | 1.2031s         | 0.619839s  | 0.103649s        | 1.21908s             | 3.145668s   |
| std::deque  1 strat  | 1.10927s        | 0.809517s  | 0.164872s        | 1.21884s             | 3.302499s   |
| std::list   1 strat  | 1.98458s        | 0.202761s  | 0.359681s        | 1.19818s             | 3.745202s   |
| std::vector 2 strat  | 1.21868s        | 0.609515s  | Labai daug laiko | -                    | -           |
| std::deque  2 strat  | 1.34371s        | 0.745927s  | 753.149s         | 1.22574s             | 756.464377s |
| std::list   2 strat  | 1.98455s        | 0.20281s   | 0.19816s         | 1.21835s             | 3.60387s    |
| std::vector 3 strat  | 1.15691s        | 0.622723s  | -                | 1.33029s             | 3.109923s   |
| std::deque  3 strat  | 1.11233s        | 0.798517s  | -                | 1.39263s             | 3.303477s   |
| std::list   3 strat  | 1.99002s        | 0.218764s  | -                | 1.6116s              | 3.820384s   |
*1 lentelė*


| Konteinerio tipas                    | Failo skaitymas | Rikiavimas | Skaidymas        | Išvedimas (į failus) | Viso      |
| ------------------------------------ | --------------- | ---------- | ---------------- | -------------------- | --------- |
| std::vector 2 strat                  | 1.21868s        | 0.609515s  | Labai daug laiko | -                    | -         |
| std::vector 2 strat remove_if        | 1.17172s        | 0.60912s   | 0.107287s        | 1.23445s             | 3.122577s |
| std::vector 2 strat stable_partition | 1.18785s        | 0.605679s  | 0.173682s        | 1.18793s             | 3.155141s |
*2 lentelė*


Testai atlikti su tokiais parametrais: 
```c++
#define min_paz_sk 1
#define max_paz_sk 20
```
```
mokinių skaičius 100 000
mokinių rikiavimas pagal VARDĄ
rezultatų skaičiavimas pagal VIDURKĮ
```

Išvados (iš pirmos duomenų lentelės):
* `std::vector` ir `std::deque` visiškai nesutverti tam, kad iš jų būtų po vieną ištrinami elementai naudojant `erase` metodą.
* Failo skaitymo laikai drastiškai skiriasi tarp `std::list` ir kitų konteinerių, nes `std::list` kas kartą išskiria naują vietą atminty, kai pridedamas elementas, o pvz. `std::vector` tam tikrą kiekį atminties, kurį užpildžius, konteineris "resize'inamas" 1.5x karto. Atminties išskirimo operacija yra brangi, todėl į `std::vector`, rečiau naudodojantį šią operaciją, duomenys sutalpinami greičiau. 
* be aukščiau minėto fakto, skaitymo laikui įtaką daro tas faktas, jog į šį laiką įeina dalinis rezultatų skaičiavimas, kurio metu apskaičiuojama n.d. mediana ir vidurkis. Be medianos ir vidurkio skaičiavimo skaitymas į `std::vector` vyksta ~1s, o į `std::list` ~1.28s. Iš to galime daugmaž pasakyti, kad rezultatų skaičiavimas naudojant `std::vector` trunka ~0.2s, o `std::list` - ~0.62s. `std::list` sunkumų kyla, kuomet skaičiuojama mediana, kadanagi praleidžiant vidurkio skaičiavimą ir paliekant tik medianos skaičiavimą, bendras laikas beveik nepakinta. Medianos skaičiavime problemos greičiausiai kyla dėl vidurinio elemento nustatymo, kadangi dėl `std::list` bruožų, programa turi pereiti nuo pirmo elemento konteineryje iki vidurinio (jeigu n.d. skaičius lyginis, tai šis procesas du kartus kartojamas), kuomet `std::vector` atminties išdėstymo struktūra leidžia greitai pasiekti norimus narius panaudojant `[]` "random access" operatorius.
* Rikiavimo laikai skirtingose strategijose nesiskiria. Kodėl laikai skiriasi tarp skirtingų konteinerių, paaiškinta ankstesnės versijos analizėje. 
* Skaidymas (mokinių rūšiavimas į vargšus ir kietus). Iš karto žvilgsnį patraukia antros strategijos `std::vector` ir `std::deque` laikai. Savaime aišku, kad skaidymas su šiais konteineriais trunka ilgai, kadanagi jie nepritaikyti šalinti elementus (esančius ne konteinerio išorėje) po vieną naudojant `erase` metodą. Ši problema buvo išspręsta panaudojant tam tkrus algoritmus (žiūrėti *2 lentelė*), apie kuriuos komentarai šiek tiek žemiau.
* 3 strategijos skaidymas vyksta rezultatų išvedimo į failus metu, todėl atskirai laiko pamatuoti negalėjau. Tačiau iš bendro laiko matome, jog pirmos ir trečios strategijų laikai beveik nesiskiria. 3 strategija pranoksta 1 tuo, kad naudojama dvigubai mažiau atminties neskaidant mokinių į atskirus konteinerius, bet tiesiai į failus. 

Išvados (iš antros duomenų lentelės):
* Panaudoti `std::remove_if` bei `std::stable_partition` algortimai išgelbėjo programą su `std::vector` konteineriu ir parodė vienus geriausių rezultatų.
* Matyti, jog skaidymas naudojant `std::stable_partition` trunka x1.7 karto ilgiau. Spėju, jog taip yra dėl to, kad `std::stable_partition` tvarkingai surūšiuoja elementus į dvi kategorijas (rūšiavimo metu vyksta elementų "swap'ai", kurių metu kuriama elemento kopija, ir dėl to programos veikimo laikas kenčia), o `std::remove_if` tiesiog sustumia į konteinerio priekį elementus, tenkinančius nurodytą kriterijų (vietoj trijų prilyginimo operacijų ("swap'inant" elementus) tokiu atvėju tereikia vienos prilyginimo operacijos).

---
# v1.1
---

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
