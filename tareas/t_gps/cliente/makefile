DESTDIR=/usr/local/bin
PROYECTO=cliente
CFLAGS=-Wall
LFLAGS=-LFLAGS
CC=gcc
OBJECTS=$(patsubst %.c,%.o, $(wildcard *.c))

all:$(PROYECTO)

%.o:%.c
	$(CC) -c $< $(CFLAGS)

$(PROYECTO):$(OBJECTS)
	$(CC) -o $@ $^ $(LFLAGS)

.PHONY:clear install uninstall

clear:
	rm *.o $(PROYECTO)

install:
	if [ ! -d $(DESTDIR) ]; then \
		sudo mkdir $(DESTDIR);
	fi;\
	sudo co $(PROYECTO) $(DESTDIR)

uninstall:
	sudo rm $(DESTDIR)/$(PROYECTO)
