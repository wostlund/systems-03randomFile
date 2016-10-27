compile: main.c
	gcc main.c -o driver


clean:
	rm *~

run: driver
	./driver
