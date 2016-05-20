/*
DESCRIPTION:
	
	AppointmentHandler class file.  Will retrieve Patient and Appointment objects
	from the StorageServices Class at startup.  
	
	Afterwards, it will serve as the main controller for creation and deletion 
	of patient/appointment entries.  Though, StorageService will still do the actual
	creation and deletion.
	
	Also functions as console UI handler.

*/

#pragma once
#include "Time.h"
#include "Appointment.h"
#include "Patient.h"

class AppointmentHandler
{
public:
	
	void Run();
	

private:
	
	void ShowMenu(Date Today);
};
