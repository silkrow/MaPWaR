#
#   Makefile
#
#   Description
#       Make tool build for MaPWaR
#
#   Author
#       Kyle Yu
#

# System Dependancies

# Windows Dependant Variables
ifeq ($(OS),Windows_NT)
    # SDL Development include file and directory
    SDL_DEVELOPMENT_INC := C:\MinGW\SDL2\include
    SDL_DEVELOPMENT_DIR := C:\MinGW\SDL2\lib\x86

    # GNU Compiler Standard
    STD := -std=c11

    # Binary File
    OBJ := MaPWaR.exe

    # Library Flags
    LIBRARY := -L$(SDL_DEVELOPMENT_DIR) -Llib -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2

    # Download Message
    DOWNLOAD := `downloading SDL2 development library`

    # Distribution
    DIST_NAME := SDL2-game-windows
    DIST_DEPENDENCIES := SDL2.dll
else
    #UNAME Shell Variable
    UNAME_S := $(shell uname -s)

    # OS X Dependant Variables
    ifeq ($(UNAME_S), Darwin)
        # SDL Development include file and directory
        SDL_DEVELOPMENT_INC := ./Library/Frameworks/SDL2.framework/Headers
        SDL_DEVELOPMENT_DIR := ./Library/Frameworks

        # GNU Compiler Standard - Clang does not have standard
        STD := -std=gnu11

        # Binary File
        OBJ := MaPWaR

        # Library Flags
        LIBRARY := -Wl,-rpath,@executable_path/$(SDL_DEVELOPMENT_DIR) -F$(SDL_DEVELOPMENT_DIR) -framework SDL2

        # Download Message
        DOWNLOAD := `downloading SDL2 framework library`

        # Distribution
        DIST_NAME := SDL2-game-osx
        DIST_DEPENDENCIES := Library

    # GNU/Linux Depedant Variables
    else ifeq ($(UNAME_S), Linux)
        # SDL Development include file and directory
        SDL_DEVELOPMENT_INC := /usr/include/SDL2

        # GNU Compiler Standard - Clang does not have standard
        STD := -std=c11

        # Binary File
        OBJ := MaPWaR

        # Library and C Compiler Flags
        LIBRARY := $(shell sdl2-config --libs)
        CFLAGS += $(shell sdl2-config --cflags)

        # Download Message
        DOWNLOAD := `sudo apt-get install libsdl2-dev`
	
    endif
endif

# development (3), and production (0)
DEBUG := -g0

# Source Files
SRC_DIR := src/
SOURCE_FILES := $(wildcard $(SRC_DIR)*.c)

# Compiler
CC := gcc

# C Compiler Flags
CFLAGS += -Wall -Werror -pedantic -Wshadow -Wstrict-aliasing -Wstrict-overflow $(DEBUG)

# Optimizations
OPT := -O2 -flto

.PHONY: all SDL

all: SDL $(OBJ)

$(OBJ): $(OBJECT_FILES)
	@echo compiling binary \'$(OBJ)\'
	$(CC) $(DEBUG) $(STD) $(OPT) $(OBJECT_FILES) -o $(OBJ) $(LIBRARY)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< $(CFLAGS) $(STD) $(OPT) $(INCLUDE) $(DFLAGS) $(patsubst $(OBJ_DIR)%.o,$(DEPEND_DIR)%.d,$@) -o $@

# SDL Library Check
SDL:
ifeq ($(wildcard $(SDL_DEVELOPMENT_INC)),)
	$(error SDL2 development package [$(SDL_DEVELOPMENT_INC)] not found, try $(DOWNLOAD))
endif

.PHONY: valgrind drmemory clean

clean:
	rm -f $(OBJ_DIR)*
	rm -f $(OBJ)

valgrind: all
	valgrind --leak-check=yes --show-leak-kinds=all --track-origins=yes ./$(OBJ)

drmemory: all
	drmemory $(OBJ)
