/* contrib/calendars/calendars--1.0.sql */

-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION calendars" to load this file. \quit

CREATE FUNCTION to_char(date, text, text)
	RETURNS text
	AS 'MODULE_PATHNAME', 'to_char_calendar'
	LANGUAGE C STABLE STRICT PARALLEL SAFE;

CREATE FUNCTION to_date(text, text, text)
	RETURNS date
	AS 'MODULE_PATHNAME', 'to_date_calendar'
	LANGUAGE C STABLE STRICT PARALLEL SAFE;
