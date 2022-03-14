CC = gcc
CFLAGS += -g

SRCS = bm.c bm_noh.c checklist.c main.c testa_bm.c
OBJS = bm.o bm_noh.o checklist.o main.o testa_bm.o 

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o rodeme

clean:
	rm -f $(OBJS) rodeme
