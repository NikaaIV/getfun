PREFIX ?= /usr/local
INCDIR = $(PREFIX)/include

install:
	install -d $(INCDIR)
	install -m 644 getfun.h $(INCDIR)/getfun.h

uninstall:
	rm -f $(INCDIR)/getfun.h
