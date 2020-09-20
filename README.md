# MSW_Skywind_Team

## A program leírása:
A programunk szerepe, hogy kettő harcos párbaját leszimulálja.
Ehhez létrehoztunk egy osztály, amiből származtatunk két objektumot.
Ezeknek az objektumoknak(harcosoknak) a memória címeit egy vektorban tároltuk el.
Mindegyik harcosnak van neve, életerőpontja és sebzése, melyeket argumentumként kell megadni a program indításakor (a megadás módját "A program futtatása" menüpont alatt találod).  
A párbaj lezajlása: a harcosok felváltva támadják egymást, mindaddig amíg az egyiküknek teljesen el nem fogynak az életerőpontjai, az a harcos veszít amelyiknél ez megtörténik.

## A program futtatása:
* Linux rendszeren:
    * Linux terminál megnyitása.
    * A "cd" parancs segítségével a programfájlokat tartalmazó mappába navigálás.
    * ./a.out és a hat argumentum megadása szóközzel elválasztva egymástól.  
    pl.: ./a.out Maple 150 10 Sally 45 30
    * Fontos, hogy a program jelenlegi állása szerint kizárólag hat megadott argumentummal fut, továbbá az életpontok és a sebzéspontok helyén mindenképp számnak kell állnia.
* Windows rendszeren:
    * A program futtatásához szükséges telepíteni egy Linux terminált (ajánlott program: [WSL Ubuntu](https://ubuntu.com/wsl))
    * A terminál feltelepítése után a program futtatásának menete megegyezik a "Linux rendszeren" menüpontban leírtakkal.

