TARGETS = ej01

C = gcc

all: clean $(TARGETS)

$(TARGETS):
	$(C) $@.c -o $@

clean:
	rm -f $(TARGETS)