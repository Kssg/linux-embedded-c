CC = gcc
CFLAG = -Wall -Wextra -g
OBJ = main.o student.o
TARGET = student_manager	# 最終執行檔名稱

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAG) -o $@ $^

# $@: 代表目前目標（例如 student_manager）
# $^: 代表所有依賴檔（例如 main.o student.o）

main.o: main.c student.h
student.o: student.c student.h

clean:
	rm -f $(OBJ) $(TARGET)
