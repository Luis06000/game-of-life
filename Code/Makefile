# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I. -IC:\SFML-2.6.2\include
LDFLAGS = -LC:\SFML-2.6.2\lib -lsfml-graphics -lsfml-window -lsfml-system

# Fichiers sources
SOURCES = main.cpp \
          Game.cpp \
          FileParser.cpp \
          FileVerify.cpp \
          Grid.cpp \
          Cells.cpp \
          GridVerify.cpp \
          ConsoleObserver.cpp \
          SFMLObserver.cpp \
          ConcreteSubject.cpp \
          Menu.cpp

# Nom de l'exécutable
EXECUTABLE = game.exe

# Règle principale
$(EXECUTABLE): $(SOURCES)
	$(CXX) $(SOURCES) $(CXXFLAGS) $(LDFLAGS) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean
