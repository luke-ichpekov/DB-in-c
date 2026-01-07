all: insert retrieve db

insert: insert.c
	gcc -o insert insert.c
retrieve: retrieve.c
	gcc -o retrieve retrieve.c
db: db.c
	gcc -c db.c -o db.o
clean:
	rm -f insert retrieve db

cleanDb:
	rm -f dbFile.bin