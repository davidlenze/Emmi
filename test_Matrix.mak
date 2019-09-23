OPTIONS = -std=c99 -pedantic -Wall -Wextra -Wdeclaration-after-statement -Wtraditional-conversion -c  -D__USE_MINGW_ANSI_STDIO=1
#-Wtraditional-conversion


Test_Matrix.exe : Test_Matrix.o Matrix.o
		gcc -o Test_Matrix.exe Test_Matrix.o Matrix.o -lm

Test_Matrix.o : Test_Matrix.c Matrix.h
		gcc $(OPTIONS) -c Test_Matrix.c

Matrix.o : Matrix.c Matrix.h
		gcc $(OPTIONS) -c Matrix.c


clean:
		del *.o
		del *.exe
