
bonoboserverdir = $(BONOBOFILES)


bin_PROGRAMS=ghbnetloadapplet

AM_CPPFLAGS=$(GNOME_APPLETS_CFLAGS) $(LIBXMLXX_CFLAGS)


ghbnetloadapplet_SOURCES=applet.cpp applet_gtk.cpp api_client.cpp api_client.h applet_gtk.h

ghbnetloadapplet_LDADD=$(GNOME_APPLETS_LIBS) $(LIBXMLXX_LIBS)


datasubdir=${datadir}/ghbnetloadapplet

datasub_DATA=ghbnetloadapplet.sample.xml


bonoboserver_DATA = GhbNetloadApplet.server
