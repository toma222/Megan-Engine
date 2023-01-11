
COMPILER=g++
TARGET = x64
SYSTEM = windows
BIN_PATH = dist/$(TARGET)/main
IMGUI_DIR = include\windows\imgui

INCLUDE_PATH = -Iinclude/$(SYSTEM) -Ipuffin/src -I$(IMGUI_DIR) -I$(IMGUI_DIR)/backends -Iinclude/windows/SDL2
LIBRARY_FLAGS = -Llib/$(TARGET) -lSDL2main -lSDL2 -lSDL2_image

ENGINEOBJ = obj/Application.o obj/Window.o obj/Context.o obj/Logging.o obj/Graphics.o obj/Sprite.o obj/Container.o obj/Transform.o obj/Texture.o obj/Surface.o obj/AppSurface.o
ANTARTICAOBJ = obj/Game.o

IMGUIOBJ = obj/imgui.o obj/imgui_widgets.o obj/imgui_tables.o obj/imgui_draw.o obj/imgui_demo.o obj/imgui_impl_sdlrenderer.o obj/imgui_impl_sdl.o

IMGUI_SOURCES = $(IMGUI_DIR)/imgui.cpp $(IMGUI_DIR)/imgui_demo.cpp $(IMGUI_DIR)/imgui_draw.cpp $(IMGUI_DIR)/imgui_tables.cpp $(IMGUI_DIR)/imgui_widgets.cpp
IMGUI_SOURCES += $(IMGUI_DIR)/backends/imgui_impl_sdl.cpp $(IMGUI_DIR)/backends/imgui_impl_sdlrenderer.cpp

obj/%.o : include/windows/imgui/%.cpp
	@echo ------ COMPILING IMGUI FILE $< -------
	$(COMPILER) -c -o $@ $< $(INCLUDE_PATH)

obj/%.o : include/windows/imgui/backends/%.cpp
	@echo ------ COMPILING IMGUI BACKENDS FILE $< -------
	$(COMPILER) -c -o $@ $<  $(INCLUDE_PATH)

obj/%.o : antartica/%.cpp antartica/GameLayer/GameLayer.h antartica\GameLayer\ImguiLayer.h
	@echo ------ COMPILING GAME FILE $< -------
	$(COMPILER) -Wall -O2 -c -o $@ $< $(INCLUDE_PATH) $(LIBRARY_FLAGS) 

obj/%.o : puffin/src/core/%.cpp puffin/src/core/%.h
	@echo ------ COMPILING PUFFIN FILE $< -------
	$(COMPILER) -Wall -O2 -c -o $@ $< $(INCLUDE_PATH) $(LIBRARY_FLAGS)

obj/%.o : puffin/src/graphics/%.cpp puffin/src/graphics/%.h
	@echo ------ COMPILING PUFFIN FILE $< -------
	$(COMPILER) -Wall -O2 -c -o $@ $< $(INCLUDE_PATH) $(LIBRARY_FLAGS)

obj/%.o : puffin/src/components/%.cpp puffin/src/components/%.h
	@echo ------ COMPILING PUFFIN FILE $< -------
	$(COMPILER) -Wall -O2 -c -o $@ $< $(INCLUDE_PATH) $(LIBRARY_FLAGS)

make: $(ENGINEOBJ) $(ANTARTICAOBJ) $(IMGUIOBJ)
	@echo ------ COMPILING OBJECTS -------
	$(COMPILER) -Wall -O2 -o $(BIN_PATH) $(ENGINEOBJ) $(IMGUIOBJ) $(ANTARTICAOBJ) $(INCLUDE_PATH) $(LIBRARY_FLAGS)
	make run

run:
	./$(BIN_PATH)

clean:
	del $(addprefix obj\,$(notdir $(ENGINEOBJ)))
	del $(addprefix obj\,$(notdir $(ANTARTICAOBJ)))

clean-all:
	del $(addprefix obj\,$(notdir $(ENGINEOBJ)))
	del $(addprefix obj\,$(notdir $(ANTARTICAOBJ)))
	del $(addprefix obj\,$(notdir $(IMGUIOBJ)))
