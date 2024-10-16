
UNITY_REPO = https://github.com/ThrowTheSwitch/Unity
UNITY_DIR = lib/Unity
UNITY_SRC = $(UNITY_DIR)/src
UNITY_FIXTURE = $(UNITY_DIR)/extras/fixture

GBDK_TAR = https://github.com/gbdk-2020/gbdk-2020/releases/download/4.3.0/gbdk-macos.tar.gz
GBDK_DIR = lib/gbdk

GCC = gcc
LCC = $(GBDK_DIR)/bin/lcc

TEST_SRC = test/test_state_manager.c
TEST_RUNNER = test_runner

UNITY_EXISTS = $(shell [ -d $(UNITY_DIR) ] && echo 1)
GBDK_EXISTS = $(shell [ -d $(GBDK_DIR) ] && echo 1)

all: clone_unity download_gbdk run_tests compile assemble link open clean

ifeq ($(UNITY_EXISTS),)
clone_unity:
	@echo "Cloning Unity..."
	git clone $(UNITY_REPO) $(UNITY_DIR)
else
clone_unity:
	@echo "Unity already exists!"
endif

ifeq ($(GBDK_EXISTS),)
download_gbdk:
	@echo "Downloading GBDK-2020..."
	curl -L $(GBDK_TAR) -o gbdk.tar.gz
	@echo "Extracting GBDK-2020..."
	tar -xzf gbdk.tar.gz -C lib
	rm gbdk.tar.gz
else
download_gbdk:
	@echo "GBDK-2020 already exists!"
endif

run_tests:
	rm -rf $(TEST_RUNNER)
	$(GCC) -DTEST -I$(UNITY_SRC) -I$(UNITY_FIXTURE) -I./src -I./test -o $(TEST_RUNNER) $(UNITY_SRC)/unity.c $(TEST_SRC)
	./$(TEST_RUNNER)

compile: run_tests
	$(LCC) -S src/fade.c
	$(LCC) -S src/game_states/splash.c
	$(LCC) -S src/game_states/main_menu.c
	$(LCC) -S src/game_states/page_01.c
	$(LCC) -S src/game_states/page_02.c
	$(LCC) -S src/game_states/page_03.c
	$(LCC) -S src/state_manager.c
	$(LCC) -S src/game_states.c
	$(LCC) -S src/main.c

assemble: compile
	$(LCC) -c fade.asm splash.asm main_menu.asm page_01.asm page_02.asm page_03.asm state_manager.asm game_states.asm main.asm

link: assemble
	$(LCC) $(MFLAGS) -o output.gb main.o game_states.o state_manager.o page_03.o page_02.o page_01.o main_menu.o splash.o fade.o

open: link
	open -a /Applications/SameBoy.app output.gb

clean:
	rm -rf ./*.asm ./*.ihx ./*.lst ./*.o ./*.s2 ./*.sym $(TEST_RUNNER)
