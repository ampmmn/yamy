//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// compiler_specific_func.cpp


#include "compiler_specific_func.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Microsoft Visual C++ 6.0

#if defined(_MSC_VER)

// get compiler version string
tstring getCompilerVersionString()
{
	TCHAR buf[200];
	_sntprintf(buf, NUMBER_OF(buf),
			   _T("Microsoft (R) 32-bit C/C++ Optimizing Compiler Version %d.%02d"),
			   _MSC_VER / 100,
			   _MSC_VER % 100);
	return tstring(buf);
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// unknown

#else
#  error "I don't know the details of this compiler... Plz hack."

#endif
