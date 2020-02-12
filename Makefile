# NOTE: Makefiles need tabs not spaces. Do not convert tabs to spaces.
CC := g++ # This is the main compiler
SRCDIR := src
BUILDDIR := build
BINDIR := bin
TARGET := $(BINDIR)/traceIt

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
DEBUG_FLAGS := -DDEBUG_RAY -DDEBUG_INTERSECTION
CFLAGS := -g -O0 -Wall $(DEBUG_FLAGS)
LIB := -lpng #in case of third party libs
INC := -I include

$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
