#pragma once

class IConnect;
class ConnectPool
{
public:
	ConnectPool(void);
	~ConnectPool(void);
private:
	list<IConnect*>		m_listOpen;
	list<IConnect*>		m_listFree;
	unsigned int		m_nMaxCount;
	connect_type		m_nType;

public:
	bool Init(connect_type nType, unsigned int nMax);
	IConnect* GetConnect();
	int	GetFreeCount();
	int	GetMaxCount();
	
};
