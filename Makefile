
C_COMPILER=gcc
CLEANUP = rm -rf
MKDIR=mkdir -p

UNITY_ROOT=./libs/Unity
BIN_DIRECTORY=./bin

CFLAGS=-std=c11
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


TEST_SRC_FILES=$(UNITY_ROOT)/src/unity.c src/*.c test/*.c
TEST_HEADER_FILES=include/pixels/*.h src/*.h test/*.h
TEST_TARGET=pixels_tests
TEST_INC_DIRS=-Iinclude/ -Isrc -I$(UNITY_ROOT)/src
SYMBOLS=

all: clean test

test: $(TEST_SRC_FILES) $(TEST_HEADER_FILES)
	$(MKDIR) $(BIN_DIRECTORY)
	$(C_COMPILER) $(CFLAGS) $(TEST_INC_DIRS) $(SYMBOLS) $(TEST_SRC_FILES) -o $(BIN_DIRECTORY)/$(TEST_TARGET)
	./$(BIN_DIRECTORY)/$(TEST_TARGET)

clean:
	$(CLEANUP) $(BIN_DIRECTORY)/*
