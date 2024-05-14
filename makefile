CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I./Graphics -I./include
LFLAGS = -L./Assets -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRCDIR = Src
OBJDIR = Obj
BINDIR = .
EXECUTABLE = $(BINDIR)/pvz.out
MEDIA_PATH = ./Assets/



SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(EXECUTABLE)
$(EXECUTABLE) : $(OBJECTS) 
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(wildcard $(SRCDIR)/*.hpp)
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(MEDIA_PATH)


clean:
	rm -rf $(OBJDIR)/*.o $(EXECUTABLE)