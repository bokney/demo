
CC = /opt/gbdk/bin/lcc
CFLAGS = #-Wa-l -Wl-m -Wl-j
MFLAGS = #-Wl-yt1 -Wl-yo4 -Wl-ya0

all:
	$(CC) $(CFLAGS) -c -o demoStates.o src/demoStates.c
	$(CC) $(CFLAGS) -c -o stateManager.o src/stateManager.c
	$(CC) $(CFLAGS) -c -o main.o src/main.c
	$(CC) $(MFLAGS) -o output.gb main.o stateManager.o demoStates.o

clean:
	rm -rf ./*.asm ./*.ihx ./*.lst ./*.o ./*.sym