CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = bank

all: $(TARGET)

$(TARGET): bank_account_system.c
	$(CC) $(CFLAGS) bank_account_system.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
