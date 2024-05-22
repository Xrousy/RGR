TARGET = RGR
CC = gcc
CFLAGS = -Wall -Werror 
DINAMICFLAGS = -shared -fPIC

PREF_SRC = ./src/
PREF_SRC_SORT = ./src/sort/
PREF_OBJ = ./obj/

$(TARGET): $(PREF_SRC)*.c 
	$(CC) $(CFLAGS) -o $@ $(PREF_SRC)*.c -lsort -L.

libsort.so: $(PREF_SRC_SORT)*.c
	$(CC) $(CFLAGS) $(DINAMICFLAGS) -o $@ $<

clean:
	rm $(TARGET) after.txt before.txt