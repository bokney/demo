
CC = /opt/gbdk/bin/lcc

all: compile assemble link open clean

compile:
	$(CC) -S src/fade.c
	$(CC) -S src/game_states/splash.c
	$(CC) -S src/game_states/main_menu.c
	$(CC) -S src/game_states/page_01.c
	$(CC) -S src/game_states/page_02.c
	$(CC) -S src/game_states/page_03.c
	$(CC) -S src/state_manager.c
	$(CC) -S src/game_states.c
	$(CC) -S src/main.c

assemble:
	$(CC) -c fade.asm splash.asm main_menu.asm page_01.asm page_02.asm page_03.asm state_manager.asm game_states.asm main.asm

link:
	$(CC) $(MFLAGS) -o output.gb main.o game_states.o state_manager.o page_03.o page_02.o page_01.o main_menu.o splash.o fade.o

open:
	open -a /Applications/SameBoy.app output.gb

clean:
	rm -rf ./*.asm ./*.ihx ./*.lst ./*.o ./*.sym
