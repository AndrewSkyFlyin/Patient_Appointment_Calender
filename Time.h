#pragma once
/*
AUTHOR: Nicholas Arroyo
DATE:	November 25, 2015
CLASS:	CPSC362
DESCRIPTION:
	Time class file. This class simply stores the time upon creation of the object.
	The times will be stored as integers, and saving the Hour and Minute portions of the time,
	as well as whether it is AM or PM (as a bool, with AM=false, and PM=true).

	This is used in conjunction with the Appointment class to store the time of a scheduled appointment.

	NOTE: the current time should be provided upon creation of the Time object. This will
		  be passed in through the constructor.

*/

class Time
{
	public:
		Time(int, int, bool);
		Time();

		int hour();
		int min();
		bool PM();	//false = AM time, true = PM time
	private:
		int Hour;
		int Minute;
		bool isPM;	//false = AM time, true = PM time
};

