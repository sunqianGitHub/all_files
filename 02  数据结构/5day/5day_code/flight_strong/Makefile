vpath %.c = ./operate
vpath %.h = ./include

CFLAGS = -Wall -g

main:main.c sort.c search.c wrap.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) main .*.sw? -rf

.PHONY:clean
