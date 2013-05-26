#pragma once

class Object
{
public:
	Object(void);
	virtual ~Object(void);
	virtual string Serialize() = 0;
	virtual int LoadFromBuffer(string strBuffer) = 0;
};
