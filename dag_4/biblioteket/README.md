# Math Utils

Ett litet projekt som bygger ett statiskt C-bibliotek med grundläggande
matematiska funktioner.

## Bygga biblioteket

Kör från den här projektmappen:

```sh
make
```

Det skapar `lib/libmathutils.a`. Headerfilen som används av program
som länkar biblioteket finns i `include/math_utils.h`.

Funktionen `power()` använder `pow()` från systembiblioteket `libm`.
Programmet som länkar biblioteket behöver därför också länka med `-lm`.

## Rensa byggfiler

```sh
make clean
```
