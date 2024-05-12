CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu99
LDFLAGS = 

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

SRCS := $(wildcard $(SRCDIR)/*.c)
SRCS += $(wildcard $(SRCDIR)/impl/*.c)  # Include implementation files
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/shell

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)  # Create the directory if it doesn't exist
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR) $(BINDIR)