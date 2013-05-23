#include "StdAfx.h"
 #include "TreadPool.h"
#ifdef WIN_2008 

CTreadPool::CTreadPool(void)
{
	m_pTp_callback_environ = NULL;
	m_pPool = NULL;

	m_nMaxThreads = -1;
	m_nMinThreads = -1;
}

CTreadPool::CTreadPool( int nMaxThreads, int nMinThreads )
{
	Create(nMaxThreads, nMinThreads);
}
CTreadPool::~CTreadPool(void)
{
	Clear();
}

void CTreadPool::Clear()
{
	if (m_pTp_callback_environ != NULL)
	{
		DestroyThreadpoolEnvironment(m_pTp_callback_environ);
		m_pTp_callback_environ = NULL;
	}
	if (m_pPool!=NULL)
	{
		CloseThreadpool(m_pPool);
		m_pPool = NULL;
	}
	
	m_nMaxThreads = -1;
	m_nMinThreads = -1;


}

BOOL CTreadPool::Create( int nMaxThreads, int nMinThreads )
{
	m_pPool = CreateThreadpool(NULL);
	if (m_pPool==NULL)
	{
		OutputDebugString(TEXT("Create Thread Pool failed \n"));
		return FALSE;
	}

	m_nMinThreads = nMinThreads;
	m_nMaxThreads = nMaxThreads;

	SetThreadpoolThreadMaximum(m_pPool, nMaxThreads);
	SetThreadpoolThreadMinimum(m_pPool, nMinThreads);

	m_pTp_callback_environ = new TP_CALLBACK_ENVIRON;
	InitializeThreadpoolEnvironment(m_pTp_callback_environ);

	SetThreadpoolCallbackPool(m_pTp_callback_environ, m_pPool);

	return TRUE;
}

BOOL CTreadPool::IsSysPool()
{
	return (m_pTp_callback_environ == NULL);
}

#endif