TARGET = TREE

all:
	make compilar
	make run
	make clean

compilar: main.c arv.c arv.h
	gcc -o $(TARGET) main.c arv.c arv.h

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)
