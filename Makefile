# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I. -IC:\SFML-2.6.2\include
LDFLAGS = -LC:\SFML-2.6.2\lib -lsfml-graphics -lsfml-window -lsfml-system

# Sources pour le jeu principal (sans UnitaryTest.cpp)
GAME_SOURCES = code/Cells.cpp code/ConcreteSubject.cpp code/ConsoleObserver.cpp \
               code/FileParser.cpp code/FileVerify.cpp code/Game.cpp code/Grid.cpp \
               code/GridVerify.cpp code/main.cpp code/Menu.cpp code/Obstacle.cpp \
               code/SFMLObserver.cpp

# Sources pour les tests unitaires (sans main.cpp)
TEST_SOURCES = code/Cells.cpp code/ConcreteSubject.cpp code/ConsoleObserver.cpp \
               code/FileParser.cpp code/FileVerify.cpp code/Game.cpp code/Grid.cpp \
               code/GridVerify.cpp code/Menu.cpp code/Obstacle.cpp \
               code/SFMLObserver.cpp code/UnitaryTest.cpp

# Cible par défaut
all: game

# Compilation du jeu
game: $(GAME_SOURCES)
	$(CXX) $(GAME_SOURCES) $(CXXFLAGS) $(LDFLAGS) -o Game.exe

# Compilation des tests
test: $(TEST_SOURCES)
	$(CXX) $(TEST_SOURCES) $(CXXFLAGS) $(LDFLAGS) -o Test.exe

clean:
	rm -f Game.exe Test.exe

.PHONY: all clean
