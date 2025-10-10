# Compilateur
CC = gcc
CFLAGS = -Wall -Wextra -g -Isrc/headers

# Nom de l'exécutable
TARGET = claush

# Dossier final de l'exécutable
BINDIR = bin

# Sources
SRCS = $(wildcard src/*.c)

# Dossier des objets
OBJDIR = build

# Objets générés (src/file.c -> build/file.o)
OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)

# Règle par défaut
all: $(BINDIR)/$(TARGET)

# Construction de l'exécutable
$(BINDIR)/$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compilation d'un .c en .o
$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Créer le dossier build si nécessaire
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Créer le dossier bin si nécessaire
$(BINDIR):
	mkdir -p $(BINDIR)

# Nettoyer
clean:
	rm -rf $(OBJDIR) $(BINDIR)/$(TARGET)

# Tout recompiler
rebuild: clean all

# Lancer directement
run: $(BINDIR)/$(TARGET)
	./$<
