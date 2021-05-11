# The compiler to use
CXX = g++
# Enabling all warning errors and debugging
CXXFLAGS = -g3 -std=c++11 -Wall -fmessage-length=0 
# Specifying Object files
OBJS = GameData/util.o GameData/game.o GameData/MainEngine.o GameData/GamePlay.o GameData/Points.o GameData/GemGrid.o GameData/GemShape.o GameData/Player.o
# Specifying external libraries
LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage -pthread
# The final executable file
TARGET = game

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

# Compiling Dependencies
GameData/util.o: Utilities/util.cpp Utilities/util.h
	$(CXX) -c Utilities/util.cpp -o GameData/util.o

GameData/MainEngine.o: GameEngine/MainEngine.cpp GameEngine/MainEngine.h
	$(CXX) -c GameEngine/MainEngine.cpp -o GameData/MainEngine.o

GameData/GamePlay.o: GameEngine/GamePlay.cpp GameEngine/GamePlay.h
	$(CXX) -c GameEngine/GamePlay.cpp -o GameData/GamePlay.o

GameData/Points.o: GameEngine/Points.cpp GameEngine/Points.h
	$(CXX) -c GameEngine/Points.cpp -o GameData/Points.o

GameData/GemGrid.o: GameEngine/GemGrid.cpp GameEngine/GemGrid.h
	$(CXX) -c GameEngine/GemGrid.cpp -o GameData/GemGrid.o

GameData/GemShape.o: GameEngine/GemData/GemShape.cpp GameEngine/GemData/GemShape.h
	$(CXX) -c GameEngine/GemData/GemShape.cpp -o GameData/GemShape.o

GameData/Player.o: PlayerData/Player.cpp PlayerData/Player.h
	$(CXX) -c PlayerData/Player.cpp -o GameData/Player.o

all: $(TARGET)

clean: rm -f $(OBJS) $(TARGET)