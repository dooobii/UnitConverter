
CC := gcc
CFLAGS := -std=c99 -Isrc

SRCDIR := src

SRCS := $(wildcard $(SRCDIR)/*.c)

OBJS := $(SRCS:$(SRCDIR)/%.c=%.o)

TARGET := time

all: ./$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) ./$(TARGET)
