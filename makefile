
COMPILER=g++
TARGET = x64
SYSTEM = windows
BIN_PATH = dist/$(TARGET)/main

INCLUDE_PATH = -Iinclude/$(SYSTEM) -Ipuffin/src
LIBRARY_FLAGS = -Llib/$(TARGET) -lSDL2main -lSDL2 -lSDL2_image

ENGINEOBJ = obj/Application.o obj/Window.o obj/Context.o obj/Logging.o
ANTARTICAOBJ = obj/Game.o

obj/%.o : antartica/%.cpp
	@echo ------ COMPILING GAME FILE $< -------
	$(COMPILER) -Wall -O2 -c -o $@ $< $(INCLUDE_PATH) $(LIBRARY_FLAGS)

obj/%.o : puffin/src/core/%.cpp puffin/src/core/%.h
	@echo ------ COMPILING PUFFIN FILE $< -------
	$(COMPILER) -Wall -O2 -c -o $@ $< $(INCLUDE_PATH) $(LIBRARY_FLAGS)

obj/%.o : puffin/src/graphics/%.cpp puffin/src/graphics/%.h
	@echo ------ COMPILING PUFFIN FILE $< -------
	$(COMPILER) -Wall -O2 -c -o $@ $< $(INCLUDE_PATH) $(LIBRARY_FLAGS)

make: $(ENGINEOBJ) $(ANTARTICAOBJ)
	@echo ------ COMPILING OBJECTS -------
	$(COMPILER) -Wall -O2 -o $(BIN_PATH) $(ENGINEOBJ) $(ANTARTICAOBJ) $(INCLUDE_PATH) $(LIBRARY_FLAGS)
	make run

run:
	./$(BIN_PATH)

clean:
	del $(ENGINEOBJ) $(ANTARTICAOBJ)
