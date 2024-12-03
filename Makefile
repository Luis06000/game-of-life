# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I. -IC:\SFML-2.6.2\include
LDFLAGS = -LC:\SFML-2.6.2\lib -lsfml-graphics -lsfml-window -lsfml-system

# Fichiers sources
SOURCES = $(wildcard code/*.cpp)

# Nom de l'exécutable
EXECUTABLE = Game.exe

# Règle principale
$(EXECUTABLE): $(SOURCES)
	$(CXX) $(SOURCES) $(CXXFLAGS) $(LDFLAGS) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean
