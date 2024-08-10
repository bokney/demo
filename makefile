
CC = /opt/gbdk/bin/lcc
CFLAGS = #-Wa-l -Wl-m -Wl-j
MFLAGS = #-Wl-yt1 -Wl-yo4 -Wl-ya0

all:
	$(CC) $(CFLAGS) -c -o main_menu.o src/game_states/main_menu.c
	$(CC) $(CFLAGS) -c -o splash.o src/game_states/splash.c
	$(CC) $(CFLAGS) -c -o stateManager.o src/stateManager.c
	$(CC) $(CFLAGS) -c -o states.o src/states.c
	$(CC) $(CFLAGS) -c -o main.o src/main.c
	$(CC) $(MFLAGS) -o output.gb main.o states.o stateManager.o splash.o main_menu.o

clean:
	rm -rf ./*.asm ./*.ihx ./*.lst ./*.o ./*.sym