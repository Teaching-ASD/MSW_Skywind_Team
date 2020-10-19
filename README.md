# MSW_Skywind_Team

## A program leírása:
A programunk lényege, hogy kettő harcos párbaját leszimulálja.
Ehhez létrehoztunk egy osztályt, amiből származtatunk két objektumot.
Mindegyik harcosnak van neve, életerő pontja és sebzés pontja, melyeket az argumentumként megadott két txt fájlból nyer ki a program.
A párbaj lezajlása: a harcosok felváltva támadják egymást, a támadott félnek pontosan annyival csökken az életerő pontja amennyi sebzés ponttal rendelkezik a támadó fél.  
A párbaj akkor ér véget, amikor az egyik félnek teljesen elfogynak az életerő pontjai.

## A program futtatása:
* Linux rendszeren:
    * Linux terminál megnyitása.
    * A "cd" parancs segítségével a programfájlokat tartalmazó mappába navigálás.
    * ./a.out és az ütköztetni kívánt két txt kiterjesztésű fájl megadása
    pl.: ./a.out Maple.txt Sally.txt
    * A txt fájlokban az alábbi példa szerint kell elhelyekedniük az adatoknak:  
    {  
    "name" : "Maple",  
    "hp" : 150,  
    "dmg" : 10  
    }
* Windows rendszeren:
    * A program futtatásához szükséges telepíteni egy Linux terminált (ajánlott program: [WSL Ubuntu](https://ubuntu.com/wsl))
    * A terminál feltelepítése után a program futtatásának menete megegyezik a "Linux rendszeren" menüpontban leírtakkal.

