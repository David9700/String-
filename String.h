#pragma once

#include <iostream>
#include <cstring>

class String
{
	char* m_String;	//Allocated buffer
	int m_size;	//Allocated length

public:
	//Construction and destruction
	String() { m_String = NULL; m_size = 0; }
	~String() { if (m_String) delete[] m_String; }

	//Copy constructors
	String(const char* pszString) { m_String = NULL; m_size = 0; operator=(pszString); }
	String(const String& rsString) { m_String = NULL; m_size = 0; operator=(rsString); }

	//Operators (assignment)
	String& operator=(const char*);
	String& operator=(const String& rsString) { return operator=(rsString.m_String); }

	//Operators (concatenation)
	String& operator+=(const char*);
	String& operator+=(String& rsString) { return operator+=(rsString.m_String); }
	String operator+(String);

	//Operators (comparison)
	int operator && (const String&);
	bool operator<(String sString) { return strcmp(operator const char* (), (const char*)sString) < 0; }
	bool operator<=(String sString) { int nCmp = strcmp(operator const char* (), (const char*)sString); return nCmp < 0 || nCmp == 0; }

	bool operator>(String sString) { return strcmp(operator const char* (), (const char*)sString) > 0; }
	bool operator>=(String sString) { int nCmp = strcmp(operator const char* (), (const char*)sString); return nCmp > 0 || nCmp == 0; }

	bool operator==(String sString) { return strcmp(operator const char* (), (const char*)sString) == 0; }
	bool operator!=(String sString) { return !operator==(sString); }
	char& operator[](int);
	//Operations
	void Clear();
	String Lower() { String sTmp = *this; sTmp.MakeLower(); return sTmp; }
	String Upper() { String sTmp = *this; sTmp.MakeUpper(); return sTmp; }

	//Information
	int Length() { return m_String ? strlen(m_String) : 0; }

	//Cast operators
	operator const char* () { return m_String ? m_String : ""; }

protected:	//Helper functions
	bool Reallocate(int);

	String& MakeLower();
	String& MakeUpper();
};

//Output and input
std::ostream& operator<<(std::ostream& oStream, String& rsString);
std::istream& operator>>(std::istream& iStream, String& rsString);