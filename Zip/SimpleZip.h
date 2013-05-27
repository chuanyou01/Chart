#pragma once
#include <string>
#include <list>

extern "C"
class CSimpleZip
{
public:
	CSimpleZip(void);
	~CSimpleZip(void);

public:
	bool Add(std::string strZipFile,std::list<std::string>& lstFile,std::string strRootPath,bool bFullPath=FALSE);
	bool Extract(std::string strDest,std::string strZipFile);

	/**	@brief compress binary data. 
	*	compress binary data from src to dst.
	*	@param src The data to be compressed
	*	@param srcSize The size of src
	*	@param dst The data buf of compressed
	*	@param dstSize The size of dst
	*	@param szErrmsg The error message if failed
	*	@return if success return true, else false
	*	@note if dst is NULL or dstSize is small to contain the result, return false, and the dstSize is the need size.
	*	@author yhw
	*	@date 03/26/2013
	*/
	bool Add(const void* src, const unsigned int& srcSize, void* dst, unsigned int& dstSize, std::string& szErrmsg);

	/**	@brief decompress binary data. 
	*	decompress binary data from src to dst.
	*	@param src The data to be decompressed
	*	@param srcSize The size of src
	*	@param dst The data buf of decompressed
	*	@param dstSize The size of dst
	*	@param szErrmsg The error message if failed
	*	@return if success return true, else false
	*	@note if dst is NULL or dstSize is small to contain the result, return false, and the dstSize is the need size.
	*	@author yhw
	*	@date 03/26/2013
	*/
	bool Extract(const void* src, const unsigned int& srcSize, void* dst, unsigned int& dstSize, std::string& szErrmsg);
};
