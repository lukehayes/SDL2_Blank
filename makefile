CXXFLAGS := -Iinclude
ENTRY := main.c
LDFLAGS := -lSDL2
BIN := -o bin/app
#SRCDIR := src
#SOURCES := $(SRCDIR)/Window.cpp

#OBJ     = obj
#OBJS    = $(OBJ)/Window.o \
		  #$(OBJ)/Graphics.o \
		  #$(OBJ)/Entity.o \
		  #$(OBJ)/Engine.o \
		  #$(OBJ)/Renderer.o \
		  #$(OBJ)/Player.o \

$(OBJ)/%.o: src/%.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

all: $(OBJS)
	$(CXX) $(ENTRY) $^ $(CXXFLAGS) $(BIN) $(LDFLAGS)

clean:
	rm -r obj/* bin/app

