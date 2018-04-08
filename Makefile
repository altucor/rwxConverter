CC = g++
CFLAGS = -std=c++17 -Wall
#CFLAGS = -Wall
OBJS = rwxLibClass.o rwxConverter.o
INCLUDE = rwxLib
OUTPUTNAME = rwx

all: $(OBJS)
	@echo $@
	$(CC) $(CFLAGS) $(OBJS) -o $(OUTPUTNAME)

rwxConverter.o:
	@echo $@
	$(CC) $(CFLAGS) -c rwxConverter/rwxConverter.cpp -I $(INCLUDE)

rwxLibClass.o:
	@echo $@
	$(CC) $(CFLAGS) -c rwxLib/rwxLibClass.cpp -I $(INCLUDE)

clean:
	@echo $@
	rm -f *.o
