build_fileio: fileio.c headers/fileio.h
	gcc -Wall -c fileio.c

build_day1: day1.c
	gcc -Wall -o day1 day1.c

test_day1: day1
	./day1 "inputfiles/day1.input"

build_day2: day2.c fileio.o
	gcc -Wall -o day2 day2.c fileio.o

test_day2: day2
	./day2 "inputfiles/day2.input"