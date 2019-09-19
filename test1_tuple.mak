OPTIONS = -std=c99 -pedantic -Wall -Wextra -Wdeclaration-after-statement -Wtraditional-conversion -c  -D__USE_MINGW_ANSI_STDIO=1
#-Wtraditional-conversion


test1_tuple.exe : test1_tuple.o tuple.o RNG.o
		gcc -o test1_tuple.exe test1_tuple.o tuple.o RNG.o -lm

test1_tuple.o : test1_tuple.c tuple.h RNG.h
		gcc $(OPTIONS) -c test1_tuple.c

tuple.o : tuple.c tuple.h RNG.h
		gcc $(OPTIONS) -c tuple.c

RNG.o: RNG.c RNG.h
		gcc $(OPTIONS) -c RNG.c

clean:
		del *.o
		del *.exe
