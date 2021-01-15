DESTDIR=/usr/local/bin
PROYECTO=servidor
CFLAGS=-Wall
LFLAGS=-LFLAGS
CC=gcc
OBJECTS=$(patsubst %.c,%.o, $(wildcard *.c))

all:$(PROYECTO)

%.o:%.c
	$(CC) -c $< $(CFLAGS)

$(PROYECTO):$(OBJECTS)
	$(CC) -o $@ $^ $(LFLAGS)

.PHONY:clean install uninstall

clean:
	rm *.o $(PROYECTO)

install:
	if [ ! -d $(DESTDIR) ]; then \
		sudo mkdir $(DESTDIR);
	fi;\
	sudo co $(PROYECTO) $(DESTDIR)

uninstall:
	sudo rm $(DESTDIR)/$(PROYECTO)
