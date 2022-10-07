#include <iostream>
#include <vector> // for vector (dynamic array, since idk how many people they're going to input)
#include <fstream> // for file input


using namespace std;


int main()
{
	//Arrays with employee data
	vector<string> allEmployees;
	vector<float> allGrossSalaries, allBonuses, allNetSalaries, allSalaryPoints;

	ofstream employeeData; //variable for file
	employeeData.open("Employee_Data.txt");

	while (true) {
		string employeeName;

		int monthToView;
		int salaryPoint;
		float annualSalary, decemberSalary, grossSalary;



		cout << "Enter employee name: ";
		cin >> employeeName;
		allEmployees.push_back(employeeName); //Add name to array and push it back

		cout << "Name: " << employeeName << endl;
		cout << "Enter the salary point: ";
		cin >> salaryPoint;


		//calculate gross, bonus and net salary
		grossSalary = salaryPoint * 2000;
		decemberSalary = grossSalary * 0.025;

		annualSalary = grossSalary + decemberSalary;

		//add values to corresponding arrays
		allGrossSalaries.push_back(grossSalary);
		allBonuses.push_back(decemberSalary);
		allNetSalaries.push_back(annualSalary);
		allSalaryPoints.push_back(salaryPoint);

		cout << "Enter the month to view (1-12): ";
		cin >> monthToView;

		cout << employeeName << "'s Annual salary is: " << annualSalary << endl;			//print anual salary before anything else

		//check month inputted and display the corresponding salary
		if (monthToView == 12)
		{
			cout << "Salary for " << employeeName << " for December is " << (grossSalary / 12) + decemberSalary << endl;
		}
		else
		{
			cout << "Salary for " << employeeName << " for month " << monthToView << " is " << grossSalary / 12 << endl;
		}


		//ask about restarting, if yes, loop again, if no, break
		string continueProgram;
		cout << '\n' << "Do you want to start again: ";
		cin >> continueProgram;
		cout << '\n';

		if (continueProgram == "no" || continueProgram == "n")
		{
			for (int i = 0; i < allEmployees.size(); i++)
			{
				//output data to console
				cout << allEmployees[i] << ": " << endl;
				cout << "Gross Salary: " << allGrossSalaries[i] << endl;
				cout << "Bonus: " << allBonuses[i] << endl;
				cout << "Annual Salary: " << allNetSalaries[i] << '\n' << endl;

				//write data to file
				employeeData << allEmployees[i] << ": ";
				employeeData << "Salary Points: " << allSalaryPoints[i] << endl;
				employeeData << "Gross Salary: " << allGrossSalaries[i] << endl;
				employeeData << "Bonus: " << allBonuses[i] << endl;
				employeeData << "Annual Salary: " << allNetSalaries[i] << '\n' << endl;

			}

			break;
		}


	}

	employeeData.close(); //close file
	return 0;


}
