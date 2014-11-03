# Dr. Beco - 2014-06-13
.PHONY : asp

# Regra aspipo : exercicios
asp : $(o).bin

# Regra aspipo : exercicios
$(o).bin : $(o).c libaspipo-ux64.o libaspipo.h
	gcc -Wall -Wextra -O0 -g $(o).c libaspipo-ux64.o -o $(o).bin 

