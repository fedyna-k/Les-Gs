# Compilator's variables

CC 		 = g++
CPPFLAGS = -I include # -I include/SFML -L lib -lsfml-system -lsfml-window -lsfml-graphics
RM	 	 = del	# Windows = del // Unix = rm

SOURCEDIR = src
OBJECTDIR = obj
OUTPUTDIR = bin

FILES 	:= $(wildcard $(SOURCEDIR)/*.cpp)
OBJ 	:= $(FILES:$(SOURCEDIR)%.cpp=$(OBJECTDIR)%.o)

# Compiling

.PHONY: all
all: main

main: $(OBJ)
	$(CC) $^ -o $(OUTPUTDIR)/$@ $(CPPFLAGS)

# All files obj compilation

$(OBJECTDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CC) -c $< -o $@ $(CPPFLAGS)


# May come in handy

clear:
	$(RM) $(OUTPUTDIR)\main
	$(RM) $(OBJECTDIR)\*.o

# Recompile everthing

again:
	$(RM) $(OBJECTDIR)\*.o
	make