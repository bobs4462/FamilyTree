CC=gcc -I. -g


OBJ=main.o famtree.o search.o


PARAM= -O2 -o


famtree:$(OBJ)
	$(CC) $(PARAM) famtree $(OBJ)

$(OBJ):famtree.h

clean:
	rm $(OBJ) famtree
