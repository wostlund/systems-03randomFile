compile: main.c
	gcc main.c -o driver


clean:
	rm file1.txt
	rm *~

run: driver
	./driver
