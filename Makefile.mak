# Makefile

# Derleyici seçimi
CC = gcc

# Derleme seçenekleri
CFLAGS = -Wall

# Hedef tanımlama
all: program

# Program hedefi ve bağımlılıklar
program: Kart_sayma.c
    $(CC) $(CFLAGS) -o program Kart_sayma.c

# Temizlik hedefi
clean:
    rm -f program
