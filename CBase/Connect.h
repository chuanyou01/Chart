#pragma once

class IConnect
{
public:
	IConnect(void);
	virtual ~IConnect(void);
	bool InitAddr();
	virtual bool Connect() = 0;
	bool Bind();
	virtual bool Send() = 0;
	virtual bool Revieve() = 0;
	virtual void Close() = 0;
};
