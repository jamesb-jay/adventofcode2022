build_day1: day1.c
	gcc -Wall -lm -o day1 day1.c

test_day1: day1
	./day1 "inputfiles/day1.input"
