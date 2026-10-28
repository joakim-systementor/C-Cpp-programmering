# Calculator

Ett enkelt miniräknarprogram som använder det statiska biblioteket
`biblioteket`.

## Byggordning

Bygg först biblioteket från projektmappen `biblioteket`:

```sh
cd ../biblioteket
make
```

Kopiera sen biblioteket från `../biblioteket/lib/libmathutils.a` och header-filen från `../biblioteket/include/math_utils.h` och lägg .a-filen i en mapp som heter `lib` och .h-filen i mappen `lib/include`.

Bygg sedan miniräknaren från projektmappen `calculator`:

```sh
make
```

Programmet förväntar sig att biblioteket finns på
`lib/libmathutils.a` och att bibliotekets headerfil finns i
`lib/include/`.

## Köra

Från `calculator/`:

```sh
make run
```

## Rensa

Från `calculator/` tar `make clean` bort programmets byggfiler.
Biblioteket rensas separat genom att köra `make clean` från `biblioteket/`.

Bygg alltså i den här ordningen:

```sh
cd biblioteket
make

cd ../calculator
make run
```

Makefile i `calculator` bygger inte biblioteket automatiskt; den använder filen som redan skapats av projektet `biblioteket`.
