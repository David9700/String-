#include <iostream>

using std::ostream;
using std::istream;

#include "String.h"
#include <cstring>

//Consts
const int cnStringReadBufferSize = 16;
//------

String& String::operator=(const char* pszString)
{
	if (!pszString)
	{
		Clear();
		return *this;
	}

	int nLen = strlen(pszString);

	if (nLen < m_size)	//If allocated space is enough
		strcpy(m_String, pszString);
	else
	{
		if (m_String)
		{
			delete[] m_String;
			m_String = NULL;
		}

		m_size = nLen + 1;
		m_String = new char[m_size];

		if (!m_String)	//Couldn't allocate
			m_size = 0;
		else
			strcpy(m_String, pszString);
	}

	return *this;
}

void String::Clear()
{
	if (m_size)
		delete[] m_String;

	m_String = NULL;
	m_size = 0;
}

String& String::operator+=(const char* pszString)
{
	int nLen = Length() + strlen(pszString);

	if (nLen >= m_size)	//Reallocation needed
		if (!Reallocate(nLen + 1))
			return *this;

	strcat(m_String, pszString);

	return *this;
}

String String::operator+(String rsString)
{
	String sString(*this);

	sString += rsString;

	return sString;
}
int String :: operator&&(const String& ob1)
{
	int z = 0, i, j;
	for (i = 0; i < strlen(m_String); i++)
	{
		for (j = 0; j < strlen(ob1.m_String); j++)
		{
			if (m_String[i] == ob1.m_String[j])
			{
				i++;
			}
			else break;
		}
		if (j == strlen(ob1.m_String))
		{
			z++;
			i--;
		}
	}
	return z;
}

bool String::Reallocate(int nSize)
{
	char* pszOldStr = m_String;

	m_size = nSize;
	m_String = new char[nSize];

	if (!m_String)	//Couldn't allocate
	{
		if (pszOldStr)
			delete[] pszOldStr;
		m_size = 0;
		return false;
	}

	if (pszOldStr)
	{
		strcpy(m_String, pszOldStr);
		delete[] pszOldStr;
	}
	else
		m_String[0] = '\0';

	return true;
}

char& String::operator[](int index)
{
	if (index >= m_size) throw std::out_of_range("invalid index");
	return m_String[index];
}

String& String::MakeLower()
{
	if (m_String)
		for (int i = 0; m_String[i]; i++)
			m_String[i] = tolower(m_String[i]);

	return *this;
}

String& String::MakeUpper()
{
	if (m_String)
		for (int i = 0; m_String[i]; i++)
			m_String[i] = toupper(m_String[i]);

	return *this;
}

ostream& operator<<(ostream& oStream, String& rsString)
{
	oStream << (const char*)rsString;
	return oStream;
}

istream& operator>>(istream& iStream, String& rsString)
{
	char pszBuffer[cnStringReadBufferSize];
	pszBuffer[0] = '\0';	//Just in case, we make it a valid string

	rsString.Clear();

	do
	{
		iStream.clear();
		iStream.getline(pszBuffer, cnStringReadBufferSize);
		rsString += pszBuffer;
	} while (iStream.fail() && (!iStream.eof()));

	return iStream;
}

