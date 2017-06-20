CC = g++
RM = rm

CFLAGS += -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
TARGETS := window
all:$(TARGETS)

$(TARGETS):window.c glad.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	-$(RM) -f *.o
	-$(RM) -f $(TARGETS)
