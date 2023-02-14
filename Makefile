#OBJS specifies which files to compile as part of the project
OBJS = main.cpp src/*.cpp

#CC specifies the compiler we're using
CC = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLDUE_PATHS = -I include -I include/headers

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L include/lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl, -subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME specifies the name of our executable
OBJ_NAME = main

#This is the target that compiles our executable
all: $(OBJS)
	$(CC) $(OBJS) $(INCLDUE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)