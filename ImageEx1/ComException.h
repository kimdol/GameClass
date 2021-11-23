#pragma once
#include <exception>
#include <string>
#include <Windows.h>
#include <stdio.h>

class com_exception : public std::exception
{
private:
	HRESULT result;
	std::string description;

public:
	com_exception(HRESULT hr) : result{ hr }, description{} {}
	com_exception(HRESULT hr, std::string msg) : result{ hr }, description{msg} {}
	virtual const char* what() const override
	{
		static char buf[512];

		if (description.length() == 0)
		{
			sprintf_s(buf, 128, "Failure with HRESULT of 0X%08X", result);
			
		}
		else
		{
			sprintf_s(buf, 128, "Failure with HRESULT of 0X%08X\n\n%s", 
				result, description.c_str());
		}

		return buf;
	}

};

inline void ThrowIfFailed(HRESULT hr, std::string msg = "")
{
	if (FAILED(hr))
	{
		throw com_exception(hr, msg);
	}
}
