
#pragma once


#ifndef _TREHAD_POOL_
#define  _TREHAD_POOL_
#ifdef WIN_2008 



class CTreadPool
{
public:
	CTreadPool(void);
	CTreadPool(int nMaxThreads, int nMinThreads);
	~CTreadPool(void);

	BOOL Create(int nMaxThreads, int nMinThreads);

	BOOL IsSysPool();
private:
	void Clear();
private:
	PTP_CALLBACK_ENVIRON	m_pTp_callback_environ;
	PTP_POOL				m_pPool;

	int			m_nMaxThreads;
	int			m_nMinThreads;
};
#endif
#endif