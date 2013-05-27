#pragma once

class ConnectPool;
class CDB_OP;
class CBuffer;
class CCommunication
{
public:
	CCommunication(void);
	~CCommunication(void);
private:
	ConnectPool*	m_pConnectPool;
	CDB_OP*			m_pDBop;
public:
	bool Create(const string& strLabel);
	bool Open(const string& strlabel);
	bool Push(const string& strlabel, const string& strBuffer);
	bool Push(const string& strlabel, const CBuffer* pBuffer);
	bool Pop(const string& strLabel, const string& strBuffer);
	bool Pop(const string& strLabel, const CBuffer strBuffer);
	void Close(const string& strLabel);

};
