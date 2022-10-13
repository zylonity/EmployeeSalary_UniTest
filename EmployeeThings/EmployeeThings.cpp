#include <iostream>
#include <vector> // for vector (dynamic array, since idk how many people they're going to input)
#include <fstream> // for file input
#include <string> //for getline


using namespace std;

//Arrays with employee data
vector<string> allEmployees;
vector<float> allGrossSalaries, allBonuses, allNetSalaries, allSalaryPoints;

bool programRunning = true;

void clearScreen() {
	int n;
	for (n = 0; n < 10; n++)
		cout << "\n\n\n\n\n\n\n\n\n\n";
}

void pauseScreen() {
	cout << "Press enter to continue...";
	cin.ignore();
	cin.get();
}



int addEmployee() {
	
	string employeeName;

	int monthToView;
	int salaryPoint;
	float annualSalary, decemberSalary, grossSalary;

	const int salaryMultiplier = 2000;
	const float bonusPercent = 0.025; //2.5%

	cout << "Enter employee name: ";
	cin >> ws;
	getline(cin, employeeName);
	allEmployees.push_back(employeeName); //Add name to array and push it back

	cout << '\n' << "Name: " << employeeName << endl;
	cout << "Enter the salary point(1 - 24): "; //Spec says to assume user's not an idiot (no need to validate)
	cin >> salaryPoint;


	//calculate gross, bonus and net salary
	grossSalary = salaryPoint * salaryMultiplier;
	decemberSalary = grossSalary * bonusPercent;

	annualSalary = grossSalary + decemberSalary;

	//add values to corresponding arrays
	allGrossSalaries.push_back(grossSalary);
	allBonuses.push_back(decemberSalary);
	allNetSalaries.push_back(annualSalary);
	allSalaryPoints.push_back(salaryPoint);

	
	cout << "Enter the month to view (1-12): ";
	cin >> monthToView;

	cout << '\n' << '\n' << employeeName << "'s Annual salary is: " << annualSalary << endl;			//print anual salary before anything else

	//check month inputted and display the corresponding salary
	if (monthToView == 12)
	{
		cout << "Salary for " << employeeName << " for December is " << (grossSalary / 12) + decemberSalary << endl;
	}
	else
	{
		cout << "Salary for " << employeeName << " for month " << monthToView << " is " << grossSalary / 12 << endl;
	}

	return 0;


	
}

int saveDataToFile() {

	ofstream employeeData; //variable for file
	employeeData.open("Employee_Data.txt");
	
	//write data to file

	for (int k = 0; k < allEmployees.size(); k++)
	{
		employeeData << allEmployees[k] << ":";
	}

	employeeData << '\n'; 			//separate data using newlines

	for (int j = 0; j < allEmployees.size(); j++)
	{
		employeeData << allSalaryPoints[j] << ":";
	}

	employeeData << '\n';

	for (int y = 0; y < allEmployees.size(); y++)
	{
		employeeData << allGrossSalaries[y] << ":";
	}

	employeeData << '\n';

	for (int x = 0; x < allEmployees.size(); x++)
	{
		employeeData << allBonuses[x] << ":";
	}

	employeeData << '\n';

	for (int z = 0; z < allEmployees.size(); z++)
	{
		employeeData << allNetSalaries[z] << ":";
	}

	employeeData.close(); //close file
	return 0;
}


int moveSavedDataToArray() {

	ifstream employeeData("Employee_Data.txt"); //variable for file
	
	string line;
	int i = 1;
	for (string line; getline(employeeData, line); i++){	//read file line by line
		
		if (i == 1) { //if first line, parse and add to allEmployees array
			string name;
			int colonPos;
			while ((colonPos = line.find(":")) != std::string::npos) {		//find semi colon and loop till there's no more. string::npos means "until the end of the string".
				name = line.substr(0, colonPos); //grab the name before the colon

				allEmployees.push_back(name); //add name to array
				line.erase(0, colonPos + 1); //erase the name and the colon
			}
			
		}

		
		//Process salary points
		else if (i == 2) {
			string sPoint;
			int salPointConverted;
			
			int colonPos;
			while ((colonPos = line.find(":")) != std::string::npos) {		
				sPoint = line.substr(0, colonPos); 

				salPointConverted = stoi(sPoint); //convert string to int
				
				allSalaryPoints.push_back(salPointConverted);
				line.erase(0, colonPos + 1); 
			}
		}

		
		//Process gross salary values
		else if (i == 3) { 
			string gSalary;
			int gSalaryConverted;

			int colonPos;
			while ((colonPos = line.find(":")) != std::string::npos) {
				gSalary = line.substr(0, colonPos);

				gSalaryConverted = stof(gSalary); //convert string to float

				allGrossSalaries.push_back(gSalaryConverted);
				line.erase(0, colonPos + 1);
			}
		}

		//Process bonus values
		else if (i == 4) {
			string bonus;
			int bonusConverted;

			int colonPos;
			while ((colonPos = line.find(":")) != std::string::npos) {
				bonus = line.substr(0, colonPos);

				bonusConverted = stof(bonus); //convert string to float

				allBonuses.push_back(bonusConverted);
				line.erase(0, colonPos + 1);
			}
		}

		//Process net salary values
		else if (i == 5) {
			string nSalary;
			int nSalaryConverted;

			int colonPos;
			while ((colonPos = line.find(":")) != std::string::npos) {
				nSalary = line.substr(0, colonPos);

				nSalaryConverted = stof(nSalary); //convert string to float

				allNetSalaries.push_back(nSalaryConverted);
				line.erase(0, colonPos + 1);
			}
		}

		
		
	}
	

	return 0;
	
}


int modifySpecificEmployee(int pos) {

	string employeeName;

	int monthToView;
	int salaryPoint;
	float annualSalary, decemberSalary, grossSalary;


	cout << "Enter employee name: ";
	cin >> ws;
	getline(cin, employeeName);

	cout << '\n' << "Name: " << employeeName << endl;
	cout << "Enter the salary point: ";
	cin >> salaryPoint;


	//calculate gross, bonus and net salary
	grossSalary = salaryPoint * 2000;
	decemberSalary = grossSalary * 0.025;

	annualSalary = grossSalary + decemberSalary;

	//delete values from each array
	allEmployees.erase(allEmployees.begin() + pos);
	allGrossSalaries.erase(allGrossSalaries.begin() + pos);
	allBonuses.erase(allBonuses.begin() + pos);
	allNetSalaries.erase(allNetSalaries.begin() + pos);
	allSalaryPoints.erase(allSalaryPoints.begin()+ pos);

	//add values to corresponding arrays
	allEmployees.insert((allEmployees.begin() + pos), employeeName);
	allGrossSalaries.insert((allGrossSalaries.begin() + pos), grossSalary);
	allBonuses.insert(allBonuses.begin() + pos, decemberSalary);
	allNetSalaries.insert(allNetSalaries.begin() + pos, annualSalary);
	allSalaryPoints.insert(allSalaryPoints.begin() + pos, salaryPoint);

	
	return 0;
}


int viewSpecificEmployee() {
	
	string viewName;
	
	//list all employees
	cout << "To view a specific employee, please enter their name EXACTLY as shown on the list: " << '\n' << '\n';
	for (int i = 0; i < allEmployees.size(); i++)
	{
		cout << allEmployees[i] << endl;
	}

	cout << '\n' << "Enter the name of the employee you wish to view: ";
	cin >> ws;
	getline(cin, viewName);
	
	//check if employee exists, and store it in an iterator
	vector<string>::iterator it = find(allEmployees.begin(), allEmployees.end(), viewName);
	
	//cast iterator into integer
	int index = distance(allEmployees.begin(), it);
	

	//if employee exists, display their details
	if (it != allEmployees.end()) {
		cout << '\n' << allEmployees[index] << ": " << endl;
		cout << "Salary Point(s): " << allSalaryPoints[index] << endl;
		cout << "Gross Salary: " << allGrossSalaries[index] << endl;
		cout << "Bonus: " << allBonuses[index] << endl;
		cout << "Annual Salary: " << allNetSalaries[index] << '\n' << endl;

		
		//ask if user wants to modify employee
		char confirmation;
		cout << "Do you want to modify this employee? (Y/N): " << endl;
		cin >> confirmation;
		if (confirmation == 'Y') {
			modifySpecificEmployee(index);
		}

	}
	else {
		cout << "Employee not found. Please try again." << '\n' << endl; 
	}
	

	

	return 0;
	
}


int menuQuestion() {

	int menuItem;
	
	cout << "Welcome to the Employee Salary Calculator" << endl;
	cout << "----------------------------------------" << endl;

	cout << "Please choose from the following options" << endl;
	cout << "1) Add new employee to the system" << endl;
	cout << "2) View all employee details" << endl;
	cout << "3) View a SPECIFIC employee's details" << endl;
	cout << "4) Save and exit" << endl;
	cout << '\n' << "----------------------------------------" << '\n' << endl;

	cin >> menuItem;


	
	return menuItem;
}


int menuBrowser(bool firstRun) {
	//check what the user wants to do

	if (firstRun) {
		moveSavedDataToArray(); //move data from file to arrays at startup
		firstRun = false;
	}


	while (programRunning == true) {
		clearScreen(); //clears the console to tidy things up
		switch (menuQuestion()) {
		case 1:
			while (true) {
				clearScreen();
				addEmployee();


				//ask about adding more employees, if yes, loop again, if no, break
				string continueProgram;
				cout << '\n' << "Do you want to add another employee?(Y/N): ";
				cin >> continueProgram;
				cout << '\n';
				if (continueProgram == "N")
				{
					break;
				}
			}
			break;
		case 2:
			clearScreen();
			for (int i = 0; i < allEmployees.size(); i++)
			{
				cout << allEmployees[i] << ": " << endl;
				cout << "Salary Point(s): " << allSalaryPoints[i] << endl;
				cout << "Gross Salary: " << allGrossSalaries[i] << endl;
				cout << "Bonus: " << allBonuses[i] << endl;
				cout << "Annual Salary: " << allNetSalaries[i] << '\n' << endl;

			}
			pauseScreen();
			clearScreen();
			break;
		case 3:
			clearScreen();
			viewSpecificEmployee();
			break;
		case 4:
			saveDataToFile();
			programRunning = false;
			break;
		}
	}

	return 0;
	
}



int main()
{
	
	menuBrowser(true);

	
	return 0;
}
