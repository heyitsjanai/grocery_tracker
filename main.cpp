/*Project 3: Chada Teck Grocery Tracker
* Author: Janai Cano
* Date: August 14, 2022
*/

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <stdio.h>
#include <fstream> //for reading & writing files

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonProject3");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

/*Function that displays an options menu as long as the user does not exit*/
void displayMenu() {
	int userOption = 0;

	do {
		//menu options
		cout << "--------------Welcome to Corner Grocer--------------" << endl;
		cout << "        Please choose from the following options:   " << endl;
		cout << "1: Display all items purchased today                " << endl;
		cout << "2: Search by specific item for purchase history     " << endl;
		cout << "3: Display chart of all items purchased today       " << endl;
		cout << "4: Exit program                                     " << endl;
		cout << "Enter your selection by number option (1,2, 3, or 4)" << endl;

		//gets user input into local int variable
		cin >> userOption;

		//menu option 1
		if (userOption == 1) {
			CallProcedure("itemCount"); //see Python function itemCount
			displayMenu(); //displays menu options again
			break; //breaks the while loop to get new user input
		}
		//menu option 2
		else if (userOption == 2) {
			string item; 
			//prompts user to enter an item name
			cout << "Enter the item name (capitalize the first letter): " << endl; 
			//puts  user input into local variable
			cin >> item;
			cout << callIntFunc("itemFrequency", item) << endl; //calls Python function itemFrequency using specified user input
			displayMenu(); //displays menu options again 
			break; //breaks the while loop to get new user input
		}
		//menu option 3
		else if (userOption == 3) {
			CallProcedure("itemHistogram"); //see Python function itemHistogram
			//opening file frequency.dat
			ifstream histoFile("C:\\Users\\justj\\OneDrive\\Desktop\\frequency.dat");
			//declaring local variables
			string itemName;
			int itemQuantity;
			string stars = "*";
			//checks to make sure the file is open
			if (histoFile.is_open()) {
				//while loop executes until the end of the file
				while (histoFile) {
					//puts first string into itemName variable
					itemName = histoFile.get();
					//puts next integer into itemQuantity variable
					itemQuantity = histoFile.get();
					//prints out the item name
					cout << itemName << " ";
					//prints out asteriks equal to itemQuantity
					for (int i = 0; i < itemQuantity; ++i) {
						cout << stars;
					}
					//ends with a new line, loop continues until end of file reached
					cout << endl;
				}		
			}
			displayMenu();
			break;
		}
		//menu option 4 exits the program
		else if (userOption == 4) {
			cout << "Goodbye!" << endl;
			exit;
		}
		//input validation makes sure user inputs correct menu option
		else {
			cout << "Invalid entry. Enter 1, 2, 3, or 4" << endl;
			displayMenu();
		}
	} while (true);

	
}
int main()
{
	//calls the display menu function
	displayMenu();

	return 0;
}