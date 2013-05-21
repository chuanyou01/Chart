#include "StdAfx.h"
#include "RTime.h"
#include <time.h>

#define _TIME_FORMATE "%Y-%m-%d %H:%M:%S"

CRTime::CRTime(void)
{
}

CRTime::~CRTime(void)
{
}

time_t CRTime::GetTime()
{
	return m_time;
}
void CRTime::SetTime( time_t tm )
{
	m_time = tm;
	PareTime();
}

std::string CRTime::GetCurrent()
{
	time(&m_time);
	PareTime();
	return Format("%Y-%m-%d %H:%M:%S");
}

std::string CRTime::GetCurrent( const char* strFormate )
{
	time(&m_time);
	PareTime();
	return Format(strFormate);
}

string CRTime::Format( const char* strFormate )
{
	char tmpbuf[128] = {0};
	strftime(tmpbuf, 128, strFormate, &m_mTime);
	return tmpbuf;
}

void CRTime::PareTime()
{
	errno_t err = _localtime64_s(&m_mTime, &m_time);
	if (err)
	{
		throw std::exception("GetCurrentTime failed!");
	}
}

int CRTime::DayofYear()
{
	return m_mTime.tm_yday;
}

int CRTime::DayofWeak()
{
	return m_mTime.tm_wday;
}

int CRTime::Year()
{
	return m_mTime.tm_year;
}

int CRTime::Month()
{
	return m_mTime.tm_mon;
}

int CRTime::Day()
{
	return m_mTime.tm_mday;
}

int CRTime::Hour()
{
	return m_mTime.tm_hour;
}

int CRTime::Minite()
{
	return m_mTime.tm_min;
}

int CRTime::Second()
{
	return m_mTime.tm_sec;
}