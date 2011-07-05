#ifndef WEEKDAYS_H
#define WEEKDAYS_H

#ifdef LANG_GERMAN
#define WEEKDAYS_DEFINED
const char* weekdays[] = { "Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag" };
#endif

#if defined(LANG_ENGLISH) || !defined(WEEKDAYS_DEFINED)
const char* weekdays[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
#endif


#endif
