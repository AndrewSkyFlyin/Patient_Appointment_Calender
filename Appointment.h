/*
AUTHOR: Nicholas Arroyo
DATE:	November 23, 2015
CLASS:	CPSC362
DESCRIPTION:
	Appointment object file. Holds important information for appointments made for patients.
	It will keep track of the data and time of the appointment, whether said appointment is still open,
	and which patient the appointment is scheduled for.
	This means that the Appointment object will save a PatientID that links it to the appropriate patient.

	NOTE:	this class uses a constructor, meaning that revelant information to the Appointment
			must be determined prior to creating the Appointment object!

	NOTE:	this class requires the classes "Date"  and "Time" to work. As the name implies, a "Date" object stores
			a date by saving the month, day, and year in it.
*/

#pragma once
#include "Date.h"
#include "Time.h"

const Date clean;
const Time clean2;

class Appointment
{
	public:
		Appointment(int, Date, Time, bool, int);
		Appointment();

		int returnAppointmentID();
		void changeAppointmentID(int x);
		void show_Appointment_Date();
		void show_StartTime();
		bool return_Open_Status();
		int returnPatientID();
		Date getAppointmentDate();
	private:
		int AppointmentID;
		Date Appointment_Date;
		Time StartTime;
		bool OpenStatus;
		int PatientID;
};