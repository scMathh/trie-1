CC = gcc
CFLAGS += -g

SRCS = trie.c stringset.c checklist.c main.c testa_stringset.c erro.c
OBJS = trie.o stringset.o checklist.o main.o testa_stringset.o erro.o

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o rodeme

clean:
	rm -f $(OBJS) rodeme
