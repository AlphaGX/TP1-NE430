CC = gcc
#OPTIONS = -lm
CC_FLAGS = -g -Wall
#Paths
ObjPATH=
BinPATH=
#Sources
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
#Executable name
EXEC=Executable


#Default: Build Object and Link them into a binairy executable 
all: $(OBJECTS) link

#Compile then run executable
run: all
	@./$(BinPATH)$(EXEC)

#Create folder for objects and binairy
mkdir:
	@mkdir -p $(ObjPATH) $(BinPATH)

#Link Object files
link:
	$(Compilateur) $(ObjPATH)*.o $(LibsLoad) -o $(BinPATH)$(EXEC)

#Compile Sources into Objects
%.o: %.c
	$(Compilateur) -o $(ObjPATH)$@ -c $< $(CompFLAGS)

test: 	main-test
	./main-test

archive:
	tar cvzf CS353-TP3.tar.gz store.c store.h main.c Makefile CS353-TP3-4.pdf

clean :
	rm -f *.o
	rm -f main-test main

clear:
	@clear