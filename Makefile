CC = gcc

all:main.o karakter_islemleri.o
	$(CC) main.o karakter_islemleri.o -o main.exe
main.o:
	$(CC) -c main.c
karakter_islemleri.o:
	$(CC) -c karakter_islemleri.c
clean:
	rm *.exe *.o