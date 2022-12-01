
COMPILER=gcc
TARGET = x64
SYSTEM = windows
BIN_PATH = dist/$(TARGET)/main

MAINFILE = engine/main.c
INCLUDE_PATH = -Iinclude/$(SYSTEM)
LIBRARY_FLAGS = -Llib/$(TARGET) -lSDL2main -lSDL2 -lSDL2_image

C_FILES = engine/data/ecs.c engine/func/transform/transform.c engine/func/window/window.c game/game.c engine/func/image/image.c engine/utils/math/MMath.c

make:
	$(info [MAKE][makefile] compiling with       => ${COMPILER})
	$(info [MAKE][makefile] compiling for target => ${TARGET})
	$(info [MAKE][makefile] compiling to         => ${BIN_PATH})
	$(COMPILER) -Wall -O2 -O3 -o $(BIN_PATH) $(MAINFILE) $(C_FILES) $(INCLUDE_PATH) $(LIBRARY_FLAGS)
	make run

run:
	./$(BIN_PATH)
	$(info [MAKE][makefile] done)
