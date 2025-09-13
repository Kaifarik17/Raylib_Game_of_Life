FLAGS=
BUILD_DIR=build/
EXEC_NAME=game
INCLUDE_DIR=include/
LIB_DIR=lib/
LD_FLAGS=-lraylib -framework Cocoa -framework OpenGL -framework IOKit -framework CoreAudio -framework CoreVideo
SRC=src/game.c src/graphics.c src/logic.c src/utils.c

all:
	mkdir -p $(BUILD_DIR)
	gcc $(FLAGS) -L$(LIB_DIR) $(LD_FLAGS) -I$(INCLUDE_DIR) $(SRC) -o $(BUILD_DIR)$(EXEC_NAME)

clean:
	rm $(BUILD_DIR)$(EXEC_NAME)