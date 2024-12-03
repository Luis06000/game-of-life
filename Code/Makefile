# Compilateur et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I. -IC:\SFML-2.6.2\include
LDFLAGS = -LC:\SFML-2.6.2\lib -lsfml-graphics -lsfml-window -lsfml-system

# Répertoires
SRCDIR = .
OBJDIR = obj

# Fichiers sources
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
HEADERS = $(wildcard $(SRCDIR)/*.h)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Nom de l'exécutable
EXECUTABLE = game.exe

# Création du répertoire obj si nécessaire
$(shell mkdir -p $(OBJDIR))

# Règles
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(EXECUTABLE)

.PHONY: all clean
