#include "StdAfx.h"
#include "Buffer.h"

CBuffer::CBuffer(int inti_size)
:m_pPoint(NULL)
,m_read(0)
,m_write(0)
{
	m_pPoint = static_cast<char*>(std::malloc(inti_size));
}

CBuffer::~CBuffer(void)
{
	free(m_pPoint);
}

size_t CBuffer::Append( const void* data, size_t size )
{
	return Append(static_cast<const char*>(data), size);
}

size_t CBuffer::Append( const char* data, size_t size )
{
	int nNead = m_size - Writeable();
	if(nNead > 0)
	{
		m_pPoint = static_cast<char*>(std::realloc(m_pPoint, m_size + nNead));
		assert(m_pPoint);
		m_size += nNead;
	}
	std::memcpy(m_pPoint + m_write, data, size);
	m_write += size;
	return size;
}

inline size_t CBuffer::Size() const
{
	return m_size;
}

inline size_t CBuffer::Writeable() const
{
	return m_size - m_write;
}

inline size_t CBuffer::Readable() const
{
	return m_size - m_read;
}

inline char* CBuffer::BeginWrite() const
{
	return m_pPoint + m_write;
}

inline char* CBuffer::BeginRead() const
{
	return m_pPoint + m_read;
}

inline void CBuffer::SetAddWrite( size_t size )
{
	m_write += size;
}

inline void CBuffer::SetAddRead( size_t size )
{
	m_read += size;
}

void CBuffer::Retrieve()
{
// 	size_t len = Readable();
// 	if (m_read)
// 	{
// 		std::memmove(m_pPoint, BeginRead(), len);
// 	}
// 
// 	m_read = 0;
// 	m_write = len;
}