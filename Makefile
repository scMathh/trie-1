all:
	@make -C src
	@mv src/rodeme .
clean:
	@make -C src clean
dclean:
	@rm -f bmais_arquivo*


