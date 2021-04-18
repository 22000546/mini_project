CC = gcc
CFLAGS = -W -Wall
TARGET = myProduct
DTARGET = D_myProduct
OBJECTS = main.c product.c manager.c
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^
clean :
	rm *.o $(TARGET) $(DTARGET)
