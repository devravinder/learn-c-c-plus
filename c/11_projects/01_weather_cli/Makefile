CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lcurl

SRC = src/main.c src/weather.c
OUT = build/weather

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

run:
	./$(OUT)

clean:
	rm -f build/weather
