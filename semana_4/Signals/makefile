DESTDIR=/usr/local/bin
PROYECTO=hilos
CC=gcc
CFLAGS=-Wall
LFLAGS=-pthread
OBJECTS=$(patsubst %.c,%.o, $(wildcard *.c))

%.o:%.c
	$(CC) -c $< $(CFLAGS)

$(PROYECTO):$(OBJECTS)
	$(CC) -o $@ $< $(LFLAGS)

.PHONY:clean



install:
	if [ ! -d $(DESTDIR) ]; then \
		sudo mkdir $(DESTDIR); \
	fi; \
	sudo cp $(PROYECTO) $(DESTDIR)

uninstall:
	sudo rm $(DESTDIR)\$(PROYECTO)

clean:
	rm *.o $(PROYECTO)
