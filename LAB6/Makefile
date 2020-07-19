all: pi_private pi_shared
pi_private: pi_private.c
	gcc -pthread -o pi_private pi_private.c
pi_shared: pi_shared.c
	gcc -pthread -o pi_shared pi_shared.c
clean:
	rm all
	