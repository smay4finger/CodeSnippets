EXECUTABLE=macaddress
OBJS=macaddress.o
INCLUDES=

CFLAGS=-W -Wall -Wextra -O2 $(INCLUDES)
LDFLAGS=
LDLIBS=


all: $(EXECUTABLE)
$(EXECUTABLE): $(OBJS)

clean:
	-$(RM) $(OBJS) $(EXECUTABLE)

.PHONY: all clean
