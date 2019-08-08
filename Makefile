MODULE_big = calendars
OBJS = calendars.o ethiopian.o $(WIN32RES)

EXTENSION = calendars
DATA = calendars--1.0.sql
PGFILEDESC = "calendars - functions for alternative calendars"

REGRESS = calendars

# We need a UTF8 database
ENCODING = UTF8
NO_LOCALE = 1

PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
