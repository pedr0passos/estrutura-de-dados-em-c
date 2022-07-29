all: compila

compila: main.o aluno.o amigos.o lista.o
	gcc main.o amigos.o aluno.o lista.o -o prog
main.o: main.c 
	gcc -c main.c 
aluno.o: aluno.c 
	gcc -c aluno.c 
amigos.o: amigos.c
	gcc -c amigos.c
lista.o: lista.c
	gcc -c lista.c
clean:
	rm main.o aluno.o amigos.o lista.o prog