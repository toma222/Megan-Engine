
COMPILER=gcc
TARGET = mac
SYSTEM = mac
BIN_PATH = dist/$(TARGET)/main

MAINFILE = src/main.c
INCLUDE_PATH = -Iinclude/$(SYSTEM)
LIBRARY_FLAGS = -Llib/$(TARGET) -lSDL2main -lSDL2 -lSDL2_image

C_FILES = src/ecs/ecs.c src/functions/transform/transform.c src/functions/window/window.c src/game/game.c src/functions/image/image.c src/utils/math/MMath.c

make:
	$(info [MAKE][makefile] compiling with       => ${COMPILER})
	$(info [MAKE][makefile] compiling for target => ${TARGET})
	$(info [MAKE][makefile] compiling to         => ${BIN_PATH})
	$(COMPILER) -Wall -O2 -O3 -o $(BIN_PATH) $(MAINFILE) $(C_FILES) $(INCLUDE_PATH) $(LIBRARY_FLAGS)
	make run

run:
	./$(BIN_PATH)
	$(info [MAKE][makefile] done)
