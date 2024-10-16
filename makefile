
LCC = /opt/gbdk/bin/lcc
GCC = gcc

TEST_SRC = test/test_state_manager.c
TEST_RUNNER = test_runner

UNITY_DIR = Unity/src

all: clone run_tests compile assemble link open clean

UNIFIED_REPO = $(shell [ -d Unity ] && echo 1)
ifeq ($(UNIFIED_REPO),)
clone:
	@echo "Cloning Unity..."
	git clone https://github.com/ThrowTheSwitch/Unity
else
clone:
	@echo "Unity already exists!"
endif

run_tests:
	rm -rf $(TEST_RUNNER)
	$(GCC) -DTEST -I$(UNITY_DIR) -IUnity/extras/fixture/src -I./src -I./test -o $(TEST_RUNNER) $(UNITY_DIR)/unity.c $(TEST_SRC)
	./$(TEST_RUNNER)

compile:
	$(LCC) -S src/fade.c
	$(LCC) -S src/game_states/splash.c
	$(LCC) -S src/game_states/main_menu.c
	$(LCC) -S src/game_states/page_01.c
	$(LCC) -S src/game_states/page_02.c
	$(LCC) -S src/game_states/page_03.c
	$(LCC) -S src/state_manager.c
	$(LCC) -S src/game_states.c
	$(LCC) -S src/main.c

assemble:
	$(LCC) -c fade.asm splash.asm main_menu.asm page_01.asm page_02.asm page_03.asm state_manager.asm game_states.asm main.asm

link:
	$(LCC) $(MFLAGS) -o output.gb main.o game_states.o state_manager.o page_03.o page_02.o page_01.o main_menu.o splash.o fade.o

open:
	open -a /Applications/SameBoy.app output.gb

clean:
	rm -rf ./*.asm ./*.ihx ./*.lst ./*.o ./*.sym $(TEST_RUNNER)
