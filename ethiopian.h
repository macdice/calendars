#ifndef ETHIOPIAN_H
#define ETHIOPIAN_H

#include "lib/stringinfo.h"
#include "utils/date.h"

void to_char_calendar_ethiopian(DateADT input,
								const char *format,
								StringInfo output);

DateADT to_date_calendar_ethiopian(const char *input, const char *format);

#endif
