
CC = /opt/gbdk/bin/lcc
CFLAGS = #-Wa-l -Wl-m -Wl-j
MFLAGS = #-Wl-yt1 -Wl-yo4 -Wl-ya0

all: build open clean

build:
	$(CC) $(CFLAGS) -c -o fade.o src/fade.c
	$(CC) $(CFLAGS) -c -o splash.o src/game_states/splash.c
	$(CC) $(CFLAGS) -c -o main_menu.o src/game_states/main_menu.c
	$(CC) $(CFLAGS) -c -o page_01.o src/game_states/page_01.c
	$(CC) $(CFLAGS) -c -o page_02.o src/game_states/page_02.c
	$(CC) $(CFLAGS) -c -o page_03.o src/game_states/page_03.c
	$(CC) $(CFLAGS) -c -o state_manager.o src/state_manager.c
	$(CC) $(CFLAGS) -c -o game_states.o src/game_states.c
	$(CC) $(CFLAGS) -c -o main.o src/main.c
	$(CC) $(MFLAGS) -o output.gb main.o game_states.o state_manager.o page_03.o page_02.o page_01.o main_menu.o splash.o fade.o

open:
	open -a /Applications/SameBoy.app output.gb

clean:
	rm -rf ./*.asm ./*.ihx ./*.lst ./*.o ./*.sym
