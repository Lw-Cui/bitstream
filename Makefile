CC = icc -std=c++11 
CXXFLAG	= -g -O0 -Wall -Wextra -W -I.

TESTDIR = test
SRCDIR	= bitsrc
BUILDDIR = build
HEADERDIR = bitheader

HEADER = $(wildcard $(HEADERDIR)/*.hpp)
SRC = $(wildcard $(SRCDIR)/*.cpp)
SRC_OBJ	= $(SRC:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)
TEST = $(wildcard $(TESTDIR)/*.cpp)
TEST_OBJ = $(TEST:$(TESTDIR)/%.cpp=$(BUILDDIR)/%.o)

bitstream: $(TEST_OBJ) $(SRC_OBJ)
	$(CC) $(CXXFLAG) $^ -o $@ 

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp $(HEADER)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CXXFLAG) $< -o $@ -c

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(HEADER)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CXXFLAG) $< -o $@ -c

clean:
	rm -rf $(BUILDDIR) 

rebuild: clean all
	
.PHONY: all clean rebuild