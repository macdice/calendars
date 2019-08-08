/*-------------------------------------------------------------------------
 *
 * calendars.c
 *	  Text search unaccent dictionary
 *
 * Copyright (c) 2019, PostgreSQL Global Development Group
 *
 *-------------------------------------------------------------------------
 */

#include "postgres.h"

#include "fmgr.h"
#include "lib/stringinfo.h"
#include "utils/builtins.h"
#include "utils/date.h"

#include "ethiopian.h"

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(to_char_calendar);
PG_FUNCTION_INFO_V1(to_date_calendar);

Datum
to_char_calendar(PG_FUNCTION_ARGS)
{
	DateADT date = PG_GETARG_DATEADT(0);
	const char *format = text_to_cstring(PG_GETARG_TEXT_PP(1));
	const char *calendar = text_to_cstring(PG_GETARG_TEXT_PP(2));
	StringInfoData buffer;

	initStringInfo(&buffer);

	if (strcmp(calendar, "Ethiopian") == 0)
		to_char_calendar_ethiopian(date, format, &buffer);
	else
		elog(ERROR, "unknown calendar \"%s\"", calendar);

	PG_RETURN_TEXT_P(cstring_to_text(buffer.data));
}

Datum
to_date_calendar(PG_FUNCTION_ARGS)
{
	const char *input = text_to_cstring(PG_GETARG_TEXT_PP(0));
	const char *format = text_to_cstring(PG_GETARG_TEXT_PP(1));
	const char *calendar = text_to_cstring(PG_GETARG_TEXT_PP(2));
	DateADT result = 0;

	if (strcmp(calendar, "Ethiopian") == 0)
		result = to_date_calendar_ethiopian(input, format);
	else
		elog(ERROR, "unknown calendar \"%s\"", calendar);

	PG_RETURN_DATEADT(result);
}

