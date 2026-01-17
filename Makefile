CC = gcc
CFLAGS = -Wall -Wextra -g

all: insert retrieve

insert: insert.o db.o bptree.o
	$(CC) -o insert insert.o db.o bptree.o 
bptree.o: bptree.c bptree.h
	$(CC) $(CFLAGS) -c bptree.c

retrieve: retrieve.o db.o bptree.o
	$(CC) -o retrieve retrieve.o db.o bptree.o

insert.o: insert.c insert.h db.h retrieve.h
	$(CC) $(CFLAGS) -c insert.c

retrieve.o: retrieve.c retrieve.h db.h
	$(CC) $(CFLAGS) -c retrieve.c 

db.o: db.c db.h
	$(CC) $(CFLAGS) -c db.c

clean:
	rm -f *.o insert retrieve db dbFile.bin
