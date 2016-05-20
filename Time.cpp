/*
AUTHOR: Nicholas Arroyo
DATE:	November 25, 2015
CLASS:	CPSC362
DESCRIPTION:
Implementation file for Time.h.
Basically, sets up the code for what the functions of Patient should do.
*/

#pragma once
#include "Time.h"
Time::Time(int _hour, int _min, bool _isPM)
{
	Hour = _hour;
	Minute = _min;
	isPM = _isPM;
}

Time::Time()
{
	Hour = 4;
	Minute = 0;
	isPM = false;
}

//The following methods return the hour, minute, and whether the time is in AM or PM time (respectively)

int Time::hour()
{
	return Hour;
}

int Time::min()
{
	return Minute;
}

bool Time::PM()
{
	return isPM;
}