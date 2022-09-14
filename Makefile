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
EXEC=bin


#Default: Build Object and Link them into a binairy executable 
all: $(OBJECTS) link

#Compile then run executable
run: all
	@clear
	@./$(BinPATH)$(EXEC) minitest

#Create folder for objects and binairy
mkdir:
	@mkdir -p $(ObjPATH) $(BinPATH)

#Link Object files
link:
	$(CC) $(ObjPATH)*.o $(LibsLoad) -o $(BinPATH)$(EXEC)

#Compile Sources into Objects
%.o: %.c
	$(CC) -o $(ObjPATH)$@ -c $< $(CC_FLAGS)


archive:
	tar cvzf NE430-TP1.tar.gz *

clean :
	rm -f *.o
	rm -f $(EXEC)

clear:
	@clear