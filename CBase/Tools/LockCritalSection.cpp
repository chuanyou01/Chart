#include "StdAfx.h"
#include "LockCritalSection.h"
#include "MCriticalSectioin.h"


CLockCriticalSection::CLockCriticalSection( CMCriticalSectioin *mCriticalSection )
{
	m_CriticalSection = mCriticalSection;
	EnterCriticalSection(&m_CriticalSection->m_citiaclSection);
}

CLockCriticalSection::~CLockCriticalSection()
{
	LeaveCriticalSection(&m_CriticalSection->m_citiaclSection);
}
