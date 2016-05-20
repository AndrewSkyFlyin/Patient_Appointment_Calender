/*
DESCRIPTION:

	Implementation file of StorageServices.h.

*/
#include "StorageServices.h"
#include <iomanip>
#include <fstream>

void StorageServices::LoadSavedInfo(int & PatientCounter, int & AppointmentCounter)
{
	Patient temp;
	Appointment temp2;
	ifstream fget;

	fget.open("PatientInfo.bin", ios::binary);

	if (fget.is_open())
	{
		fget.read((char*)&PatientCounter, sizeof(int));

		for (int i = 0; i < PatientCounter; i++)
		{
			fget.read((char*)&temp, sizeof(Patient));
			m_PatList.insert(m_PatList.end(), temp);
		}
		fget.close();
	}
	else
	{
		cout << "Error. Unable to patient read file." << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	fget.open("AppointmentInfo.bin", ios::binary);
	if (fget.is_open())
	{
		fget.read((char*)&AppointmentCounter, sizeof(int));

		for (int i = 0; i < AppointmentCounter; i++)
		{
			fget.read((char*)&temp2, sizeof(Appointment));
			m_AppList.insert(m_AppList.end(), temp2);
		}
		fget.close();
	}
	else
	{
		cout << "Error. Unable to appointment read file." << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
}

void StorageServices::SaveInfo(int PatientCounter, int AppointmentCounter)
{
	ofstream ftrace;
	list<Patient>::iterator itr;
	list<Appointment>::iterator itr2;

	ftrace.open("PatientInfo.bin", ios::binary);
	ftrace.write((char*)&PatientCounter, sizeof(PatientCounter));

	for (itr = m_PatList.begin(); itr != m_PatList.end(); ++itr)
	{
		ftrace.write((char*)&(*itr), sizeof(Patient));
	}
	ftrace.close();

	ftrace.open("AppointmentInfo.bin", ios::binary);
	ftrace.write((char*)&AppointmentCounter, sizeof(AppointmentCounter));

	for (itr2 = m_AppList.begin(); itr2 != m_AppList.end(); ++itr2)
	{
		ftrace.write((char*)&(*itr2), sizeof(Appointment));
	}

	cout << "Patient and Appointment records saved. Quitting." << endl;
}

void StorageServices::DisplayPatientList(int PatientCounter)
{
	list<Patient>::iterator itr;
	system("cls");
	cout << "Number of Patient Records: " << PatientCounter << endl;
	for (itr = m_PatList.begin(); itr != m_PatList.end(); itr++)
	{
		cout << "----------------------------------------" << endl;
		cout << "Patient ID: " << itr->returnID() << ", " << endl;
		cout << "Name: " << itr->returnFirstName() << " " <<
			itr->returnLastName() << endl;
		cout << "Phone: " << itr->returnPhone() << " " << endl;
	}
	cout << "----------------------------------------" << endl;
	cout << "End of Patient List." << endl;
	cout << "----------------------------------------" << endl;
	system("pause");
}

void StorageServices::CreatePatient(int & PatientCounter)
{
	char FirstName[20];
	char LastName[20];
	long long phone;
	int pref;
	int patID;

	cout << "Enter First Name: ";
	cin >> FirstName;
	cout << "Enter Last Name: ";
	cin >> LastName;

	while(1)
	{
		cout << "Enter Phone Number: ";
		cin >> phone;
		//Checks for correct input type
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid Input Type" << endl;
			system("pause");
		}
		else
			break;
	}

	while(1) 
	{
		cout << "Enter contact preference(0 = email, 1 = phone): ";
		cin >> pref;
		//Checks for correct input type.
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid Input Type" << endl;
			system("pause");
		}
		//Checks for correct input range
		else if (pref > 1 || pref < 0)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid Range." << endl;
			system("pause");
		}
		else
			break;
	} 

	
	patID = PatientCounter;
	PatientCounter++;

	Patient *pNewPat = new Patient(FirstName, LastName, phone, pref, patID);
	m_PatList.insert(m_PatList.end(), *pNewPat);

	cout << "----------------------------------------\n";
	cout << "Patient Record Created.\n";
	cout << "----------------------------------------\n";
	system("pause");
}

void StorageServices::CreateAppointment(int PatientCounter, int & AppointmentCounter)
{
	if (PatientCounter == 0)
	{
		cout << "There are no patients to create appointments for." << endl;
		system("pause");
		return;
	}

	list<Patient>::iterator itr = m_PatList.begin();
	bool Correct = false;
	bool isPM;
	int month, day, year;
	int hour, minute;
	int PatientID;
	char dummy;
	string input;

	while (Correct == false)
	{
		while (1)
		{
			system("cls");
			cout << "-------Create Appointment-----" << endl;
			cout << "Enter Patient ID: ";
			cin >> PatientID;
			//Checks for correct input type.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Invalid Input Type" << endl;
				system("pause");
			}
			else
				break;
		}

		while (itr != m_PatList.end() && PatientID != itr->returnID())
		{
			itr++;
		}

		//Check if Patient ID exists.
		if (itr != m_PatList.end())
		{
			cout << "Patient: " << itr->returnFirstName() << " "
				<< itr->returnLastName() << " |ID: " << itr->returnID() << endl;
			Correct = true;
		}
		else
		{
			cout << "ID match not found. Try again." << endl;
			itr = m_PatList.begin();
			system("pause");
		}
	}

	Correct = false;
	while (Correct == false)
	{
		cout << "Enter Appointment Date(Ex: 2-15-2015): ";
		cin >> month >> dummy >> day >> dummy >> year;
		//Checks for correct input type.
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid Input Type" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			//Checks for valid Date range.
			Date checker(month, day, year);
			if (month != checker.getMonth() || day != checker.getDay()
				|| year != checker.getYear())
			{
				cout << "Invalid Date parameters." << endl;
				system("pause");
				system("cls");
			}
			else
				Correct = true;;
		}
	}

	while (1)
	{
		cout << "Enter Appointment Time(Ex: 9:30 am): ";
		cin >> hour >> dummy >> minute >> input;
		//Checks for correct input type.
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid Input Type" << endl;
			system("pause");
			system("cls");
		}
		else if (hour > 12 || hour < 1 || minute > 59 || minute < 0)
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid Time Range" << endl;
			system("pause");
			system("cls");
		}
		else
			break;
	}

	if (input[0] == 'a' || input[0] == 'A')
	{
		isPM = false;
	}
	else
	{
		isPM = true;
	}

	Date Date_A(month, day, year);
	Time Time_A(hour, minute, isPM);

	Appointment *pNewApp = new Appointment(AppointmentCounter, Date_A, Time_A, false, PatientID);
	m_AppList.insert(m_AppList.end(), *pNewApp);
	AppointmentCounter++;

	cout << "----------------------------------------\n";
	cout << "Appointment Scheduled.\n";
	cout << "----------------------------------------\n";

	cout << "Patient ID: " << itr->returnID() << endl;
	cout << "	   Name: " << itr->returnFirstName() << " " << itr->returnLastName() << endl << endl;
	cout << "Appointment Date: " << Date_A << endl;
	cout << "Appointment Time: " << hour << ":" << setfill('0')
		<< setw(2) << minute;
	if (isPM == true)
		cout << "PM" << endl;
	else
		cout << "AM" << endl;
	cout << "----------------------------------------\n";
	system("pause");
}

void StorageServices::DisplayAppointmentList(Date Today)
{
	Date DateHolder = Today;
	int week = 0;
	string input = " ";
	while (input[0] != '9')
	{
		DateHolder = Today;
		DateHolder += week;
		system("cls");
		DisplayAppointmentHelper(DateHolder);
		getline(cin, input, '\n');
		if (input.length() == 0) continue;
		switch (input[0])
		{
		case '1':
			DateHolder += (0);
			DisplayAppointmentsOneDay(DateHolder);
			break;
		case '2':
			DateHolder += (1);
			DisplayAppointmentsOneDay(DateHolder);
			break;
		case '3':
			DateHolder += (2);
			DisplayAppointmentsOneDay(DateHolder);
			break;
		case '4':
			DateHolder += (3);
			DisplayAppointmentsOneDay(DateHolder);
			break;
		case '5':
			DateHolder += (4);
			DisplayAppointmentsOneDay(DateHolder);;
			break;
		case '6':
			DateHolder += (5);
			DisplayAppointmentsOneDay(DateHolder);
			break;
		case '7':
			DateHolder += (6);
			DisplayAppointmentsOneDay(DateHolder);
			break;
		case 'e':
			week += 7;
			break;
		case 'q':
			if (week != 0)
				week -= 7;
			break;
		default:
			continue;
		}
	}
	system("pause");
}

void StorageServices::DisplayAppointmentHelper(Date Today)
{
	int Label = 1;
	int AppCounter = 0;
	Date DateHolder = Today;
	list<Appointment>::iterator itr;

	for (int i = 0; i < 7; i++)
	{
		cout << Label << ") " << DateHolder << ": ";
		for (itr = m_AppList.begin(); itr != m_AppList.end(); itr++)
		{
			if (DateHolder == itr->getAppointmentDate())
				AppCounter++;
		}
		cout << AppCounter << " Appointments." << endl;
		AppCounter = 0;
		Label += 1;
		DateHolder += 1;
	}
	cout << "Select a day to view it's Appointment list.(1-7)" << endl;
	cout << "Enter e to go forward one week." << endl;
	cout << "Enter q to go back one week." << endl;
	cout << "Enter 9 to return to previous menu." << endl;
	cout << ">";
}

void StorageServices::DisplayAppointmentsOneDay(Date x)
{
	list<Appointment>::iterator itr;

	cout << x << " appointments." << endl;

	for (itr = m_AppList.begin(); itr != m_AppList.end(); itr++)
	{
		if (x == itr->getAppointmentDate())
		{
			cout << "----------------------------------" << endl;
			cout << "Appointment ID: " << itr->returnAppointmentID() << endl;
			cout << "Patient ID: " << itr->returnPatientID() << endl;
			itr->show_StartTime();
			cout << "----------------------------------" << endl;
		}
	}
	cout << "----------------------------------" << endl;
	cout << "End of " << x << "'s appointment list." << endl;
	cout << "----------------------------------" << endl;
	system("pause");
}

void StorageServices::CancelAppointment(int &AppointmentCounter)
{
	list<Appointment>::iterator itr = m_AppList.begin();
	int App_ID;
	int i = 0;

	while (1)
	{
		system("cls");
		cout << "Enter the Appointment ID: ";
		cin >> App_ID;
		//Checks for correct input type
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid Input Type" << endl;
			system("pause");
		}
		else
			break;
	}

	//Searches for Appointment ID
	while (itr != m_AppList.end() && itr->returnAppointmentID() != App_ID)
	{
		itr++;
	}

	//True, if Appointment ID was not found and itr reached 
	//past the end of the list.
	if (itr == m_AppList.end())
	{
		cout << "Appointment ID not found." << endl;
		system("pause");
	}
	else
	{
		m_AppList.erase(itr);
		AppointmentCounter--;
		//Re-numbers the remaining appointments with new AppIDs.
		for (itr = m_AppList.begin(); itr != m_AppList.end(); itr++)
		{
			itr->changeAppointmentID(i);
			i++;
		}
		cout << "Appointment deleted." << endl;
		system("pause");
	}
}
