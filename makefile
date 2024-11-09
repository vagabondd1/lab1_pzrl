TARGET = cmdcalc
.PHONY: all clean run

all: $(TARGET)
clean:
	rm -f $(TARGET) *.o
run: $(TARGET)
	./$(TARGET) $(ARGS) 
main.o: main.c
	gcc -c main.c
func.o: func.c
	gcc -c func.c
$(TARGET): main.o func.o
	gcc -Wall main.o func.o -o $(TARGET)
