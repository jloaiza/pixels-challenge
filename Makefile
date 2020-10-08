
C_COMPILER=gcc
CLEANUP = rm -rf
MKDIR=mkdir -p

UNITY_ROOT=./libs/Unity
BIN_DIRECTORY=bin

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


TEST_SRC_FILES=$(UNITY_ROOT)/src/unity.c src/*.c test/test_utils.c

TEST_SORT_SRC=test/test_sort.c
TEST_SORT_TARGET=sort_tests

TEST_PIXEL_DATA=test/test_pixel_data.c
TEST_PIXEL_DATA_TARGET=pixel_data_tests

TEST_HEADER_FILES=include/pixels/*.h src/*.h test/*.h
TEST_INC_DIRS=-Iinclude/ -Isrc -I$(UNITY_ROOT)/src
SYMBOLS=

all: clean test-sort test-pixel-data

test-sort: $(TEST_SRC_FILES) $(TEST_HEADER_FILES) $(TEST_SORT_SRC)
	$(MKDIR) $(BIN_DIRECTORY)
	$(C_COMPILER) $(CFLAGS) $(TEST_INC_DIRS) $(SYMBOLS) $(TEST_SRC_FILES) $(TEST_SORT_SRC) -o $(BIN_DIRECTORY)/$(TEST_SORT_TARGET)
	./$(BIN_DIRECTORY)/$(TEST_SORT_TARGET)

test-pixel-data: $(TEST_SRC_FILES) $(TEST_HEADER_FILES) $(TEST_SORT_SRC)
	$(MKDIR) $(BIN_DIRECTORY)
	$(C_COMPILER) $(CFLAGS) $(TEST_INC_DIRS) $(SYMBOLS) $(TEST_SRC_FILES) $(TEST_PIXEL_DATA) -o $(BIN_DIRECTORY)/$(TEST_PIXEL_DATA_TARGET)
	./$(BIN_DIRECTORY)/$(TEST_PIXEL_DATA_TARGET)

clean:
	$(CLEANUP) $(BIN_DIRECTORY)/*
