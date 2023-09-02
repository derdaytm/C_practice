# Makefile

# Derleyici seçimi
CC = gcc

# Derleme seçenekleri
CFLAGS = -Wall

# Hedef tanımlama
all: program

# Program hedefi ve bağımlılıklar
program: Yılan_oyunu.c
    $(CC) $(CFLAGS) -o program Yılan_oyunu.c

# Temizlik hedefi
clean:
    rm -f program
