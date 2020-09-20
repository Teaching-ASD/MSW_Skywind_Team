# MSW_Skywind_Team

## A program leírása:
A programunk szerepe, hogy kettő harcos párbaját leszimulálja.
Ehhez létrehoztunk egy osztályt, amiből származtatunk két objektumot.
Mindegyik harcosnak van neve, életerő pontja és sebzés pontja, melyeket argumentumként kell megadni a program indításakor (a megadás módja "A program futtatása" menüpont alatt található).  
A párbaj lezajlása: a harcosok felváltva támadják egymást, a támadott félnek pontosan annyival csökken az életerő pontja amennyi sebzés ponttal rendelkezik a támadó fél.  
A párbaj akkor ér véget, amikor az egyiküknek teljesen elfogynak az életerő pontjai.

## A program futtatása:
* Linux rendszeren:
    * Linux terminál megnyitása.
    * A "cd" parancs segítségével a programfájlokat tartalmazó mappába navigálás.
    * ./a.out és a hat argumentum megadása szóközzel elválasztva egymástól.  
    pl.: ./a.out Maple 150 10 Sally 45 30
    * Fontos, hogy a program jelenlegi állása szerint kizárólag hat megadott argumentummal fut, továbbá az életpontok és a sebzéspontok helyén mindenképp számnak kell állnia.
* Windows rendszeren:
    * A program futtatásához szükséges telepíteni egy Linux terminált (ajánlott program: [WSL Ubuntu](https://ubuntu.com/wsl))
    * A terminál feltelepítése után a program futtatásának menete megegyezik a "Linux rendszeren" menüpontban leírtakkal.ogram futtatásának menete megegyezik a "Linux rendszeren" menüpontban leírtakkal.
