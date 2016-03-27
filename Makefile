CC = icc -std=c++11 
CXXFLAG	= -g -O0 -Wall -Wextra -W 

SRCDIR	= src
BUILDDIR = build
HEADERDIR = header

HEADER = $(wildcard $(HEADERDIR)/*.hpp)
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ	= $(SRC:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

bitstream: $(OBJ)
	$(CC) $(CXXFLAG) $^ -o $@ 

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADER)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CXXFLAG) $< -o $@ -c

clean:
	rm -rf $(BUILDDIR) Huffman.out

rebuild: clean all
	
.PHONY: all clean rebuild