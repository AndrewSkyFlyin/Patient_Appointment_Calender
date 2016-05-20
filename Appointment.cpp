/*
AUTHOR: Nicholas Arroyo
DATE:	November 25, 2015
CLASS:	CPSC362
DESCRIPTION:
Implementation file for Appointment.h.
Basically, sets up the code for what the functions of Appointmen should do.

int returnAppointmentID();
void show_Appointment_Date();
void show_StartTime();
bool return_Open_Status();
int returnPatientID();
*/


#include "Appointment.h"
#include <iostream>
#include <iomanip>

//Class constructor for Appointment
//Sets up values for the class based on what's passed into it

Appointment::Appointment(int _AppID, Date AppDate, Time _StartTime, bool isOpen, int PID)
{
	AppointmentID = _AppID;
	Appointment_Date = AppDate;
	StartTime = _StartTime;
	OpenStatus = isOpen;
	PatientID = PID;
}

Appointment::Appointment()
{
	AppointmentID = -1;
	Appointment_Date = clean;
	StartTime = clean2;
	OpenStatus = false;
	PatientID = -1;
}

//Return the AppointmentID when called
int Appointment::returnAppointmentID()
{
	return AppointmentID;
}

void Appointment::changeAppointmentID(int x)
{
	AppointmentID = x;
}

//display the Date of the appointment onscreen
void Appointment::show_Appointment_Date()
{
	cout << "Appointment Date: " << Appointment_Date.getMonth() << "/" << Appointment_Date.getDay() << "/" << Appointment_Date.getYear() << std::endl;
}

//display the Starting time of the appointment onscreen
void Appointment::show_StartTime()
{
	cout << "Start Time: " << StartTime.hour() << ":" << setfill('0') 
		<< setw(2) << StartTime.min() << " ";
	if (StartTime.PM() == true)
		cout << "PM" << std::endl;
	else
		cout << "AM" << std::endl;
}

//return whether the appointment is still open or not
bool Appointment::return_Open_Status()
{
	return OpenStatus;
}

//return the ID of the patient whom this appointment is for
int Appointment::returnPatientID()
{
	return PatientID;
}

Date Appointment::getAppointmentDate()
{
	return Appointment_Date;
}
