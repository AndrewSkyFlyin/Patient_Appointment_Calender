/*
DESCRIPTION:

	Handles storage of Patient and Appointment objects in file memory during program execution.
	Also handles reading and writing such objects into the file system upon startup and
	program termination.

*/

#pragma once
#include "Patient.h"
#include "Appointment.h"
#include <list>

class StorageServices
{
public:

	void LoadSavedInfo(int &PatientCounter, int &AppointmentCounter); //Loads data at startup.
	void SaveInfo(int PatientCounter, int AppointmentCounter); //Saves data at exit.

	void DisplayPatientList(int PatientCounter);
	void CreatePatient(int &PatientCounter);

	void CreateAppointment(int PatientCounter, int &AppointmentCounter);
	void DisplayAppointmentList(Date Today);   //Displays this week's appointments.
	void DisplayAppointmentHelper(Date Today); //Helper function
	void DisplayAppointmentsOneDay(Date x);    //Displays a specified day's appointments.
	void CancelAppointment(int &AppointmentCounter);

private:

	list<Appointment> m_AppList;
	list<Patient> m_PatList;
};