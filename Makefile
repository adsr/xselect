all: xselect

xselect: xselect.c
	gcc -Wall -g -o xselect xselect.c

install: xselect
	install -m 0755 xselect /usr/local/bin

clean:
	rm -f *.o xselect core
