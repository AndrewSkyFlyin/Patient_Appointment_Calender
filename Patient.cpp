#define _CRT_SECURE_NO_WARNINGS
/*
AUTHOR: Nicholas Arroyo
DATE:	November 23, 2015
CLASS:	CPSC362
DESCRIPTION:
	Implementation file for Patient.h.
	Basically, sets up the code for what the functions of Patient should do.
*/

#include "Patient.h"
#include <iostream>
//#include <string>

//Class constrtuctor for Patient object
//Sets up values for the patient when its created, based on info passed into it.
//Alternatively, default values are set if no info is passed into it.
Patient::Patient(const char * FName, const char * LName, long long PhoneNum, int Pref, int ID)
{
	setFirstName(FName);
	setLastName(LName);
	Phone = PhoneNum;
	PreferredContact = Pref;
	PatientID = ID;
	inUse = true;
}

Patient::Patient()
{
	setFirstName("Blank");
	setLastName("Blank");
	Phone = -1;
	PreferredContact = -1;
	PatientID = -1;
	inUse = true;
}

//If name exceeds 18 characters, shorten to 18 characters.
Patient & Patient::setFirstName(const char *g)
{
	if (strlen(g) > 18)
	{
		strncpy(FirstName, g, 18);
		FirstName[18] = '\0';
	}
	else
		strcpy(FirstName, g);
	return (*this);
}

//If name exceeds 18 characters, shorten to 18 characters.
Patient & Patient::setLastName(const char *g)
{
	if (strlen(g) > 18)
	{
		strncpy(LastName, g, 18);
		LastName[18] = '\0';
	}
	else
		strcpy(LastName, g);
	return (*this);
}


//Returns the patient's First Name when requested
const char * Patient::returnFirstName()
{
	return FirstName;
}

//Returns the patient's Last Name when requested
const char * Patient::returnLastName()
{
	return LastName;
}

//Returns the patient's Phone Number when requested
long long Patient::returnPhone()
{
	return Phone;
}

//Returns the patient's Preferred Mode of Contact when requested
//NOTE: 0 = email contact, 1 = text message contact
int Patient::returnPrefContact()
{
	return PreferredContact;
}

//Returns the patient's Unique ID when requested
int Patient::returnID()
{
	return PatientID;
}