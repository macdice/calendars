#include "postgres.h"

#include "ethiopian.h"

#include "fmgr.h"
#include "lib/stringinfo.h"
#include "utils/date.h"

void
to_char_calendar_ethiopian(DateADT input,
						   const char *format,
						   StringInfo output)
{
	int day_number = (int) input;

	/* compute the year, month, day in the Ethiopian system */
	/* use the format string to append a text representation to output */
	appendStringInfo(output, "<put Ethiopian date for day number %d here>",
					 day_number);
}

DateADT
to_date_calendar_ethiopian(const char *input, const char *format)
{
	/* parse the input, possibly using format, and compute a day number */

	return 0;
}
