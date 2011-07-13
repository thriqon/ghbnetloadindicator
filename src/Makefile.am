
bonoboserverdir = $(BONOBOFILES)


bin_PROGRAMS=ghbnetloadapplet

AM_CPPFLAGS=$(GNOME_APPLETS_CFLAGS) $(LIBXMLXX_CFLAGS)

ghbnetloadappletSOURCESWITHOUTMAIN=host.cpp traffic.cpp date.cpp traffic.h host.h date.h weekdays.h traffic_xml.cpp traffic_xml.h apiclient.cpp apiclient.h traffictotal_xml.cpp traffictotal_xml.h account_xml.h account_xml.cpp host_xml.h host_xml.cpp


ghbnetloadapplet_SOURCES=main_test.cpp $(ghbnetloadappletSOURCESWITHOUTMAIN)
LDADD=$(GNOME_APPLETS_LIBS) $(LIBXMLXX_LIBS)


check_PROGRAMS=trafficcheck accountcheck datecheck trafficxmlcheck traffictotalxmlcheck hostxmlcheck accountxmlcheck
#check_CPPFLAGS=-fprofile-arcs -ftest-coverage -O0 -g
trafficcheck_SOURCES=trafficcheck.cpp $(ghbnetloadappletSOURCESWITHOUTMAIN)
accountcheck_SOURCES=accountcheck.cpp host.cpp
datecheck_SOURCES=datecheck.cpp date.cpp
trafficxmlcheck_SOURCES=trafficxmlcheck.cpp $(ghbnetloadappletSOURCESWITHOUTMAIN)
traffictotalxmlcheck_SOURCES=traffictotalxmlcheck.cpp $(ghbnetloadappletSOURCESWITHOUTMAIN)
hostxmlcheck_SOURCES=hostxmlcheck.cpp $(ghbnetloadappletSOURCESWITHOUTMAIN)
accountxmlcheck_SOURCES=accountxmlcheck.cpp $(ghbnetloadappletSOURCESWITHOUTMAIN)

TESTS=$(check_PROGRAMS)

datasubdir=${datadir}/ghbnetloadapplet

#datasub_DATA=ghbnetloadapplet.sample.xml


bonoboserver_DATA = GhbNetloadApplet.server
