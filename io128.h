// __int128 IO header

/*
 This header provides IO to __int128, the non-standard type of GNU Complier Collection.
 This header is under a GNU LGPLv2.1+ license.
*/ 

#ifdef __GNUC__

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>

/*
 Read a __int128 from in.
 If it finds a character that is not a '-' or a number, it sets in's flag to ios::fail and returns a undefined value.
*/
__int128 read128(std::istream &in = std::cin)
{
	__int128 res = 0;
	bool negative = false;
	
	std::string s;
	in >> s;
	if (s[0] == '-') negative = true;
	
	for (unsigned int i = (unsigned int)negative; i < s.size(); i++)
	{
		if (!isdigit(s[i]))
		{
			in.setstate(std::ios::failbit);
			break;
		}
		res *= 10;
		res += s[i] - '0';
	}
	
	if (negative) res = -res;
	return res;
}

// Write a __int128 to out.
void write128(__int128 n, std::ostream &out = std::cout)
{
	if (n < 0)
	{
		out << '-';
		n = -n;
	}
	
	std::string tmp = "";
	while (n > 0)
	{
		tmp += n % 10 + '0';
		n /= 10;
	}
	
	std::reverse(tmp.begin(), tmp.end());
	
	for (int i = 0; i < tmp.size(); i++)
	{
		out << tmp[i];
	}
}

#endif
