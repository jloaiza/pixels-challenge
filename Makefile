
C_COMPILER=gcc
CLEANUP = rm rf
MKDIR=mkdir -p

UNITY_ROOT=./libs/Unity
BIN_DIRECTORY=./bin

CFLAGS=-std=c89
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
CFLAGS += -Wno-misleading-indentation


TEST_SRC_FILES=$(UNITY_ROOT)/src/unity.c src/sort.c src/pixel_data.c test/pixel_data.c  tests/check_sort.c tests/test_utils.c
TEST_TARGET=pixels_tests
TEST_INC_DIRS=-Isrc -I$(UNITY_ROOT)/src
SYMBOLS=

all: clean test

test: $(TEST_SRC_FILES) $(TEST_INC_DIRS)
	$(MKDIR) $(BIN_DIRECTORY)
	$(C_COMPILER) $(CFLAGS) $(TEST_INC_DIRS) $(SYMBOLS) $(TEST_SRC_FILES) -o $(BIN_DIRECTORY)/$(TEST_TARGET)
	./$(BIN_DIRECTORY)/$(TEST_TARGET)

clean:
	$(CLEANUP) $(BIN_DIRECTORY)/*
