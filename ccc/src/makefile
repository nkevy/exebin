CC=g++
LIB=./
BIN=../bin
CFLAG= -march

all: CaptureTouch

test_print:
	$(CC) -I ./test -o $(BIN)/$@ ./test/test.cpp

CaptureTouch:
	$(CC) -I ./$@ -o $(BIN)/$@ ./CaptureTouch/capt.cpp

clean:
