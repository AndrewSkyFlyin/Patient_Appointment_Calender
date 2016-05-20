/*
DESCRIPTION:

	Implementation file of the AppointmentHandler.h.

*/

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#include "Appointment.h"
#include "Time.h"
#include "AppointmentHandler.h"
#include "StorageServices.h"
#include <iostream>
#include <string>
#include <ctime>

void AppointmentHandler::Run()
{
	//Misc initializations
	int PatientCounter = 0;
	int AppointmentCounter = 0;
	

	time_t t = time(0);   // Retrieve today's date
	struct tm * now = localtime(&t);
	Date Today; 
	Today.setDate(now->tm_mon + 1, now->tm_mday, now->tm_year + 1900);

	StorageServices S_Services;

	//Load in Patient and Appointment records from storage bin
	S_Services.LoadSavedInfo(PatientCounter, AppointmentCounter);

	//Main menu module
	string input = " ";
	while (input[0] != '9')
	{
		system("cls");
		ShowMenu(Today);
		getline(cin, input, '\n');
		if (input.length() == 0) continue;
		switch (input[0])
		{
		case '1': 
			//Display all patient records, implemented
			S_Services.DisplayPatientList(PatientCounter);
			break;
		case '2':
			//View Appointments, implemented
			S_Services.DisplayAppointmentList(Today);
			break;
		case '3': 
			//Create Appointment, implemented
			S_Services.CreateAppointment(PatientCounter, AppointmentCounter);
			break;
		case '4':
			//Cancel Appointments, implemented
			S_Services.CancelAppointment(AppointmentCounter);
			break;
		case '5': 
			//Create new patient record, implemented
			S_Services.CreatePatient(PatientCounter);
			break;
		default:
			continue;
		}
	}
	
	//Saves patient records into bin file upon program exit.
	S_Services.SaveInfo(PatientCounter, AppointmentCounter);
}

void AppointmentHandler::ShowMenu(Date Today)
{
	cout << "----------------------------------------\n";
	cout << "Patient and Appointment Application\n";
	cout << "----------------------------------------\n";
	cout << Today << endl; //Displays today's date
	cout << endl << "Please choose one of the following options:" << endl;
	cout << "1 - View Patient List" << endl;
	cout << "2 - View Appointments" << endl;
	cout << "3 - Create Appointments" << endl;
	cout << "4 - Cancel Appointments" << endl;
	cout << "5 - Create New Patient Record" << endl;
	cout << "9 - Quit" << endl;
	cout << ">";
}
