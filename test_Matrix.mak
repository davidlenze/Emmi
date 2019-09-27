OPTIONS = -std=c99 -pedantic -Wall -Wextra -Wdeclaration-after-statement -Wtraditional-conversion -c  -D__USE_MINGW_ANSI_STDIO=1
#-Wtraditional-conversion


Test_Matrix.exe : Test_Matrix.o Matrix.o RNG.o Tuple.o
		gcc -o Test_Matrix.exe Test_Matrix.o Matrix.o RNG.o Tuple.o -lm

Test_Matrix.o : Test_Matrix.c Matrix.h RNG.h
		gcc $(OPTIONS) -c Test_Matrix.c

Matrix.o : Matrix.c Matrix.h RNG.h
		gcc $(OPTIONS) -c Matrix.c

RNG.o : RNG.c RNG.h
		gcc $(OPTIONS) -c RNG.c

Tuple.o : Tuple.c Tuple.h RNG.h RNG.c
		gcc $(OPTIONS) -c Tuple.c

clean:
		del *.o
		del *.exe
