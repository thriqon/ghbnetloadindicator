

AC_INIT([ghbnetloadapplet],[0.1],[mail@jonasw.de])

AM_INIT_AUTOMAKE([1.10 no-define])


AC_PROG_CXX
AC_LANG(C++)


PKG_CHECK_MODULES(GNOME_APPLETS, libpanelapplet-2.0 >= 2.9.4)
AC_SUBST(GNOME_APPLETS_CFLAGS)
AC_SUBST(GNOME_APPLETS_LIBS)

PKG_CHECK_MODULES([LIBXMLXX], [libxml++-2.6])

#TODO: rewrite with prefix?
AC_SUBST(BONOBOFILES,["/usr/lib/bonobo/servers/"])

AC_CONFIG_HEADERS([config.h])

AC_DEFINE(MAXTRAFFIC, 4812.8, [the maximum of netload allowed])

AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile src/GhbNetloadApplet.server])

AC_OUTPUT

