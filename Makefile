# Nombre del binario
TARGET = main

# Compilador (puedes cambiarlo a gcc si prefieres)
CC = clang

# Flags de compilación
CFLAGS = -Wall -O2 -lm

# Archivos fuente y headers
SRCS = eira_kem.c main.c
HEADERS = eira_kem.h

# Regla principal
all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Ejecutable con símbolos de depuración
debug:
	$(CC) $(CFLAGS) -g $(SRCS) -o $(TARGET)-debug

# Limpieza de binarios
clean:
	rm -f $(TARGET) $(TARGET)-debug