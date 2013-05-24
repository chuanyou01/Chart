#include "StdAfx.h"
#include "CurSysInfo.h"

CCurSysInfo::CCurSysInfo(void)
{
	InitSysInfo();
}

CCurSysInfo::~CCurSysInfo(void)
{
}

void CCurSysInfo::InitSysInfo()
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	m_dwProcessorNum = sysInfo.dwNumberOfProcessors;
	
	ProcessorDetail();

	GetMemDetail();
}

void CCurSysInfo::GetMemDetail()
{
	MEMORYSTATUS memState;
	GlobalMemoryStatus(&memState);

	m_dwMemVirtual = memState.dwTotalVirtual;
	m_dwMemPhysic = memState.dwTotalPhys;

	DWORD dwTotal = m_dwMemPhysic + m_dwMemVirtual;
	if (dwTotal != 0)
	{
		DWORD dwUsed = (memState.dwTotalVirtual - memState.dwAvailVirtual ) + 
			(memState.dwTotalPhys - memState.dwAvailPhys);

		m_nUsage = (dwUsed*100)/dwTotal;
	}
}

void CCurSysInfo::ProcessorDetail()
{
	PSYSTEM_LOGICAL_PROCESSOR_INFORMATION pBuffer = NULL;
	DWORD dwSize = 0;
	
	m_dwLogicPorcessorNum = 0;

	BOOL bResult = GetLogicalProcessorInformation(pBuffer, &dwSize);
	if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
	{
		_tprintf(TEXT("Impossible to get processor information \n"));
		return ;
	}

	pBuffer = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)malloc(dwSize);
	bResult = GetLogicalProcessorInformation(pBuffer, &dwSize);
	if (!bResult)
	{
		free(pBuffer);

		_tprintf(TEXT("Impossible to get processor information \n"));
		return ;
	}

	DWORD lpiCount = dwSize / sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);

	for (DWORD dwIndex = 0;  dwIndex<lpiCount; dwIndex++)
	{
		if (pBuffer[dwIndex].Relationship == RelationProcessorCore)
		{
			if (pBuffer[dwIndex].ProcessorCore.Flags == 1)
// 			{
// 			}
			m_dwLogicPorcessorNum ++;
		}
	}
}

DWORD CCurSysInfo::GetCPUCount()
{
	return m_dwProcessorNum;
}

DWORD CCurSysInfo::GetLogicCount()
{
	return m_dwLogicPorcessorNum;
}

int CCurSysInfo::GetMemUsage()
{
	return m_nUsage;
}