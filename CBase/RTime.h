#pragma once

/*
%a
Abbreviated weekday name
%A
Full weekday name
%b
Abbreviated month name
%B
Full month name
%c
Date and time representation appropriate for locale
%d
Day of month as decimal number (01 每 31)
%H
Hour in 24-hour format (00 每 23)
%I
Hour in 12-hour format (01 每 12)
%j
Day of year as decimal number (001 每 366)
%m
Month as decimal number (01 每 12)
%M
Minute as decimal number (00 每 59)
%p
Current locale's A.M./P.M. indicator for 12-hour clock
%S
Second as decimal number (00 每 59)
%U
Week of year as decimal number, with Sunday as first day of week (00 每 53)
%w
Weekday as decimal number (0 每 6; Sunday is 0)
%W
Week of year as decimal number, with Monday as first day of week (00 每 53)
%x
Date representation for current locale
%X
Time representation for current locale
%y
Year without century, as decimal number (00 每 99)
%Y
Year with century, as decimal number
%z, %Z
Either the time-zone name or time zone abbreviation, depending on registry settings; no characters if time zone is unknown
%%
Percent sign
*/
class CRTime
{
public:
	CRTime(void);
	~CRTime(void);
public:
	void SetTime(time_t tm);

	time_t GetTime();

	string GetCurrent();

	string GetCurrent(const char* strFormate);

	string Format(const char* strFormate);

	int DayofYear();

	int DayofWeak();

	int Year();

	int Month();

	int Day();

	int Hour();

	int Minite();

	int Second();

private:
	void PareTime();
	time_t m_time;
	tm    m_mTime;
};
