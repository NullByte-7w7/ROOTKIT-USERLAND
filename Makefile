TARGET = _libc.so
CC = gcc
CFLAGS = -shared -fPIC -ldl
SRCS = DRK.c

all: $(TARGET)

$(TARGET):$(SRCS)

        $(CC) $(CFLAGS) -o $(TARGET) $(SRCS)
