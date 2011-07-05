
bonoboserverdir = $(BONOBOFILES)


bin_PROGRAMS=ghbnetloadapplet

AM_CPPFLAGS=$(GNOME_APPLETS_CFLAGS) $(LIBXMLXX_CFLAGS)

ghbnetloadappletSOURCESWITHOUTMAIN=host.cpp traffic.cpp date.cpp traffic.h host.h date.h weekdays.h


ghbnetloadapplet_SOURCES=main_test.cpp $(ghbnetloadappletSOURCESWITHOUTMAIN)
ghbnetloadapplet_LDADD=$(GNOME_APPLETS_LIBS) $(LIBXMLXX_LIBS)


check_PROGRAMS=trafficcheck accountcheck datecheck
trafficcheck_SOURCES=trafficcheck.cpp $(ghbnetloadappletSOURCESWITHOUTMAIN)
accountcheck_SOURCES=accountcheck.cpp host.cpp
datecheck_SOURCES=datecheck.cpp date.cpp

TESTS=$(check_PROGRAMS)

datasubdir=${datadir}/ghbnetloadapplet

#datasub_DATA=ghbnetloadapplet.sample.xml


bonoboserver_DATA = GhbNetloadApplet.server
