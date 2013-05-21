#pragma once

class CBuffer
{
private:
	char*	m_pPoint;
	size_t  m_write;
	size_t	m_read;
	size_t  m_size;
public:
	CBuffer(int inti_size);
	~CBuffer(void);

public:
	size_t Append(const void* data, size_t size);

	size_t Append(const char* data, size_t size);

	size_t Size() const;
	
	size_t Writeable() const;

	size_t Readable() const;

	char* BeginWrite() const;

	char* BeginRead() const;

	void SetAddWrite(size_t size);

	void SetAddRead(size_t size);

	void Retrieve();
};
