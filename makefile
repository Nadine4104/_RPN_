SOURCES = pol.c stack.c

OBJS = pol.o stack.o

CC = gcc

EXE = pol

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS)

$(OBJS): $(SOURCES)
	$(CC) -c $(SOURCES)

clean:
	rm *.o $(EXE)

test: $(EXE)
	./pol "2 5 +"
	./pol "3 2 3 * -"
	./pol "1 2 + 4 * 3 +"
	./pol "45 36 34 - *"
