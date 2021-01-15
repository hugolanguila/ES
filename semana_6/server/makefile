DESTDIR=/usr/local/bin
PROYECTO=server
CFLAGS=-Wall
LFLAGS=-lm
CC=gcc

OBJECTS=$(patsubst %.c,%.o,$(wildcard *.c))

all:$(PROYECTO)

%.o:%.c
	$(CC) -c $< $(CFLAGS)

$(PROYECTO):$(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY:clean install uninstall

install:
	if [! -d $(DESTDIR) ]; then \
		sudo mkdir $(DESTDIR);\
	fi; \
	sudo cp $(PROYECTO) $(DESTDIR)

uninstall:
	sudo rm $(DESTDIR)\$(PROYECTO)

clean:
	rm *.o $(PROYECTO)

zip:
	zip -r $(PROYECTO).zip ./
