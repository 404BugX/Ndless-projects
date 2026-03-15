BINARY  = BouncingSquare
CFLAGS  = -Wall -W -marm -Os -I/opt/ndless-libs/include
LDFLAGS = -L/opt/ndless-libs/lib
LIBS    = -lSDL
OBJS    = main.o

all: $(BINARY).tns

%.o: %.c
	nspire-gcc $(CFLAGS) -c $< -o $@

$(BINARY).elf: $(OBJS)
	nspire-ld $(LDFLAGS) $(OBJS) $(LIBS) -o $@

$(BINARY).tns: $(BINARY).elf
	genzehn --input $< --output $(BINARY).tns.zehn --name "$(BINARY)" --240x320-support true
	make-prg $(BINARY).tns.zehn $(BINARY).tns
	rm -f $(BINARY).tns.zehn $(BINARY).elf

clean:
	rm -f *.o *.elf *.tns *.zehn
