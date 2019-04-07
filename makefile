CC=g++
CFLAGS=-I.
DEPS = funkcijos.h mokinys.h generavimas.h apdorojimas.h main.h
OBJ = main.o mokinys.o funkcijos.o apdorojimas.o generavimas.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
