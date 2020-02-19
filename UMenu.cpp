#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;


//All the class definitions with their functions inside them

class student {
private:
	string name;
	long id;
	double gpa;
	vector <student> allstudents;
public:
	void studentmenu();
	void news();
	void dels();
	void lists();
	bool validatesid(long);
	friend class section;
};

class section {
private:
	int snumber;
	string days;
	string code;
	string professor;
	string time;
public:
	vector <student> students;
	void sectionmenu();
	void createsection();
	void modifysection();
	void delsection();
	void registudent();
	void unregistudent();
	void listall();
	friend class course;
};

class course {
private:
	string cname;
	int credits;
	string description;
	vector <string> prereq;
	string code;
	vector <section> sections;
	vector <course> allcourses;
public:
	void listall();
	void coursemenu();
	void addc();
	void modifyc();
	void deletec();
	void listsections();
	bool validatecode(string a);
	friend class section;
	void loadcat();
	void storecat();
};

class professor {
private:
	string name;
	long id;
	vector <professor> allprof;
public:
	void professormenu();
	void newprof();
	void delprof();
	void listprof();
	bool validateid(long);
};

class aucmenu {
private:

public:
	course cm;
	section sm;
	student stm;
	professor pm;
	void Aucmenu();
};

class catalog {
private:
	vector <course> courses;
	int year;
public:
};


int main() {
	aucmenu f;
	f.Aucmenu();
	return 0;
	system("pause");
}

void drawline() {			//Function that draws a line
	cout << "#################################################\n";
}

void aucmenu::Aucmenu() {			//Function that displays the initial menu which can transfer to any other menu
	int x;
	aucmenu f;
	drawline();
	cout << "1. Course Menu\n"
		<< "2. Section Menu\n"
		<< "3. Professor Menu\n"
		<< "4. Student	Menu\n"
		<< "5. List	all	courses\n"
		<< "6. Exit\n";
	drawline();
	cout << "Enter your choice [1-6]\n";
	cin >> x;
	while ((x < 1) || (x > 6)) { cout << "Invalid choice, please try again\n"; cin >> x; }
	switch (x)
	{
	case 1:
		f.cm.coursemenu();
		break;
	case 2:
		f.sm.sectionmenu();
		break;
	case 3:
		f.pm.professormenu();
		break;
	case 4:
		f.stm.studentmenu();
		break;
	case 5:
		f.cm.listall();
		break;
	case 6:
		exit(1);
	default:
		cout << "Outside of the range. Try again\n";
		f.Aucmenu();
	}
}

void course::coursemenu() {			//Function which represents the course menu which can transfer to sub-functions
	int x;
	aucmenu f;
	course z;
	drawline();
	cout << "1. Add	course\n" //(make	sure	no	two	duplicate	course	numbers	exist)
		<< "2. Modify	course\n" //(selected	by	the	course	number)
		<< "3. Delete	course\n"
		<< "4. List	all	sections\n"
		<< "5. Load the course from the catalog file\n"		//two new options to maintain new file functionality
		<< "6. Store the courses in the catalog file\n"
		<< "7. Back\n";
	drawline();
	cout << "Enter your choice[1-7]\n";
	cin >> x;
	while ((x < 1) || (x > 7)) { cout << "Invalid choice, please try again\n"; cin >> x; }
	switch (x) {
	case 1:
		z.addc();
		break;
	case 2:
		z.modifyc();
		break;
	case 3:
		z.deletec();
		break;
	case 4:
		z.listsections();	//cout all of what is inside the vector
		break;
	case 5:
		z.loadcat();			//sending the user to the necessary functions
		break;
	case 6:
		z.storecat();
		break;
	case 7:
		f.Aucmenu();
		break;
	default:
		cout << "Outside of range, please try again\n";
		z.coursemenu();
		break;
	}
	return;
}

void professor::professormenu() {			//Function that presents the professor menu and can transfer to sub-functions
	int x;
	professor fcall;
	aucmenu f;
	drawline();
	cout << "1. New	Professor\n" <<
		"2. Delete	Professor\n" <<
		"3. List	Professors\n" <<
		"4. Back\n";
	drawline();
	cout << "Enter your choice [1-4]\n";
	cin >> x;
	switch (x) {
	case 1:
		fcall.newprof();
		break;
	case 2:
		fcall.delprof();
		break;
	case 3:
		fcall.listprof();
		break;
	case 4:
		f.Aucmenu();
		break;
	default:
		cout << "Outside of range, please try again\n";
		fcall.professormenu();
		break;
	}
	return;
}

void section::sectionmenu() {			//Function that represents section menu and can transfer to sub-functions
	int choice;
	aucmenu x;
	section s;
	drawline();
	cout << "1. Create	section\n" <<
		"2. Modify section\n" <<
		"3. Delete	section\n" <<
		"4. Register student\n" <<
		"5. Unregister student\n" <<
		"6. List	all	students\n"
		"7. Back\n";
	drawline();
	cout << "Enter your choice [1-7]\n";
	cin >> choice;
	switch (choice) {
	case 1:
		s.createsection();
		break;
	case 2:
		s.modifysection();
		break;
	case 3:
		s.delsection();
		break;
	case 4:
		s.registudent();
		break;
	case 5:
		s.unregistudent();
		break;
	case 6:
		s.listall();
		break;
	case 7:
		x.Aucmenu();
		break;
	default:
		cout << "Outside of the range\n";
		x.Aucmenu();
		break;
	}
}

void student::studentmenu() {			//Function that presents student menu and can transfer to sub-functions
	int choice;
	student me;
	aucmenu f;

	drawline();
	cout << "1. New	Student\n" <<
		"2. Delete Student\n" <<
		"3. List Students\n" <<
		"4. Back\n";
	drawline();
	cout << "Enter your choice\n";
	cin >> choice;
	switch (choice) {
	case 1:
		me.news();
		break;
	case 2:
		me.dels();
		break;
	case 3:
		me.lists();
		break;
	case 4:
		f.Aucmenu();
		break;
	default:
		cout << "Outside of range\n";
		f.Aucmenu();
		break;
	}
}

bool course::validatecode(string a) {		//ONLY CHECKS IF CODE DOES NOT EXIST or if it used
	for (auto i = allcourses.begin(); i != allcourses.end(); i++) {
		if (i->code == a)
			return false;
	}
	return true;
}


void course::addc() {		//function that adds a course
	int pre;
	string code;
	aucmenu x;
	course y;
	char confirm;
	cout << "Enter the course's code\n";
	cin >> code;
	if (validatecode(code)) {		//checking if code is used
		course newcourse;
		cout << "Enter the course's name\n";
		cin >> newcourse.cname;
		cout << "Enter the number of credit hours\n";		//adding course
		cin >> newcourse.credits;
		cout << "Enter the description\n";
		cin.ignore();
		getline(cin, newcourse.description, '\n');
		cout << "Enter the number of prerequisites for this course\n";
		cin >> pre;
		for (int i = 0; i < pre; i++) {
			string o;
			cout << "Enter the first prerequisite code\n";
			cin >> o;
			newcourse.prereq.push_back(o);
		}
		newcourse.allcourses.push_back(newcourse);			//adding course to vector
		cout << "Course added successfully\n";
	}
	else {
		cout << "Course code already exists\n";
		cout << "Do you want to try again [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') y.addc();
		else y.coursemenu();
	}
	y.coursemenu();
}

void course::modifyc() {
	string mod;
	char confirm;
	course modify;
	int x, newcredits, choice;
	string newn, descript, newprereq;
	cout << "Enter the code of the course you want to edit\n";
	cin >> mod;
	if (!validatecode(mod)) {
		for (auto i = modify.allcourses.begin(); i != modify.allcourses.end(); i++) {		//Finding course
			if (i->code == mod) {
				cout << "Do you want to modify the course's name? [1]\n"			//options for modification
					<< "or the course's credits? [2] \n"
					<< "or the course's description? [3] \n"
					<< "or the course's prerequisites? [4] \n";
				cin >> x;
				switch (x) {
				case 1:
					cout << "The old name is: " << i->cname << "\n";
					cout << "Please enter the new name\n";
					cin >> newn;
					i->cname = newn;
					break;
				case 2:
					cout << "The course currently has " << i->credits << "credit hours\n";
					cout << "Enter the new number of credits\n";
					cin >> newcredits;
					i->credits = newcredits;
					break;
				case 3:
					cout << "The old course description is: " << i->description << "\n";
					cout << "Enter the new description\n";
					cin.ignore();
					getline(cin, descript, '\n');
					i->description = descript;
					break;
				case 4:
					cout << "The current course prerquisites: ";
					for (auto i = modify.prereq.begin(); i != modify.prereq.end(); i++) {
						cout << *i << "\n";
					}
					cout << "Do you want to add another prerquisite? [1]\n"
						<< "Or delete one of the prerequisites? [2]\n"; //give option to add or delete and to go back and implement
					cin >> choice;
					if (choice == 1) {
						cout << "Enter the new prerequisite code\n";
						cin >> newprereq;
						modify.prereq.push_back(newprereq);
					}
					else {
						cout << "Enter the course code you want to delete\n";
						cin >> newprereq;
						for (auto i = modify.prereq.begin(); i != modify.prereq.end(); i++) {
							if (*i == newprereq) {
								modify.prereq.erase(i);
								break;
							}
						}
						cout << "Course code does not exist\n";
					}
					break;		//breaking the switch
				}
				break;			//breaking the for loop
			}

		}
		modify.coursemenu();	//call the course menu again
	}
	else {
		cout << "Course does not exist\n" <<
			"Do you want to try again?[y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { modify.modifyc(); }
		else { modify.coursemenu(); }
	}
}

void course::deletec() {
	string cd;
	course del;
	char confirm;
	cout << "Enter the code of the course you want to delete\n";
	cin >> cd;
	if (validatecode(cd)) {
		cout << "Course code does not exist\n";
		cout << "Do you want to try again\n? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { del.deletec(); }
		else { del.coursemenu(); }
	}
	else {
		for (auto i = del.allcourses.begin(); i != del.allcourses.end(); i++) {		//finding course index
			if (i->code == cd) {
				del.allcourses.erase(i);		//deleting course
				cout << "Course deleted\n";
				break;		//breaking for loop
			}
		}
	}
}

void course::listsections() {			//listing all sections for a specific course
	course x;
	string str;
	char confirm;

	cout << "Enter the course code\n";
	cin >> str;
	if (x.validatecode(str)) {
		cout << "Course code does not exist\n";
		cout << "Do you want to try again\n? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { x.listsections(); }
		else { x.coursemenu(); }
	}
	else {
		for (auto i = x.allcourses.begin(); i != x.allcourses.end(); i++) {
			if (i->code == str) {
				for (auto k = i->sections.begin(); k != i->sections.end(); k++) {
					cout << "Section number: " << k->snumber << "\n" <<
						"Section professor: " << k->professor << "\n" <<
						"Section days: " << k->days << "\n" <<
						"Section time: " << k->time << "\n";
				}
			}
		}
	}
	x.coursemenu();
}

void course::listall() {			//Lists all existing course
	course list;
	aucmenu f;
	for (auto i = list.allcourses.begin(); i != list.allcourses.end(); i++) {
		cout << i->cname << "\n" <<
			i->code << "\n" <<
			i->credits << "\n" <<
			i->description << "\n"
			<< "Prerequisites: ";
		for (auto j = list.prereq.begin(); j != list.prereq.end(); i++) {
			cout << *j << "\n";
		}
	}
	cout << "All courses listed successfully\n";
	f.Aucmenu();
}

void course::loadcat() {		//function that loads data from a file into the vector of courses
	course list;				//used variables
	ifstream file;
	char confirm;
	char* a;
	string b;

	file.open("catalog.txt");		//opening the file
	if (file.is_open()) {		//checking if file is open and if we can proceed with extracting data
		while (!file.eof()) {		//loop until file reaches its end
			file.ignore();				//ignoring so that we can take a whole line into a string and not just one word
			getline(file, b);
			a = &b[0];					//using a char pointer so we can use tokenizer funtion, pointing the pointer to the beginning of the string
			list.code = strtok(a, "Number: ");		//storing the data received (course code) into a temporary course variable

			file.ignore();			//repeating the process with name
			getline(file, b);
			a = &b[0];
			list.cname = strtok(a, "NAME:");

			file.ignore();			//repeating process with credit hours
			getline(file, b);
			a = &b[0];
			list.credits = atoi(strtok(a, "CH: "));			//changing the stored variable into an integer before storing it

			file.ignore();		//repeated process
			getline(file, b);
			cout << b << endl;
			a = &b[0];
			list.description = strtok(a, "DESCRIPTION:");

			file.ignore();			//repeated process
			getline(file, b);
			a = &b[0];
			list.prereq.push_back(strtok(a, "Prereq: "));			//token is pushed into the vector of prerequisites

			list.allcourses.push_back(list);		//pushing the loaded course into the catalog vector
			cout << "Code: " << list.code << "\n" <<
				"Name: " << list.cname << "\n" <<
				"Credits: " << list.credits << "\n" <<
				"Description: " << list.description << "\n" <<
				"Prerequisite: " << list.prereq.back() << "\n";
		}
		file.close();		//closing the file when we are done
	}
	else {
		cout << "File opening failed\n";			//if file opening fails user is prompted if they want to try again
		cout << "Do you want to try again? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { list.loadcat(); }
		else { list.coursemenu(); }
	}
	list.coursemenu();
}

void course::storecat() {		//course that writes into the catalog file
	course list;
	ofstream file;
	char confirm;
	file.open("catalog.txt");			//opening the file
	if (file.is_open()) {		//checking if it succeeded so we can proceed
		for (auto i = list.allcourses.begin(); i != list.allcourses.end(); i++) {		//for loop to insert all the courses in the vector
			file << "Number: " << i->code << "\n" <<		//Entering every detail of the course
				"Name: " << i->cname << "\n" <<
				"CH: " << i->credits << "\n" <<
				"Description: " << i->description << "\n"
				<< "Prerequisites: ";
			for (auto j = list.prereq.begin(); j != list.prereq.end(); i++) {		//nested for loop in case there are multiple prerequisites
				file << *j << "\n";
			}
		}
		file.close();		//closing the file when we are done
	}
	else {
		cout << "File opening failed\n";			//if file opening fails user is prompted if they want to try again
		cout << "Do you want to try again? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { list.storecat(); }
		else { list.coursemenu(); }
	}
	list.coursemenu();
}

void student::news() {		//This function creates a new student
	long num;
	student x;
	char confirm;

	cout << "Enter the student's id\n";
	cin >> num;
	if (x.validatesid(num)) {		//If the function returns true then the student does not exist
		x.id = num;
		cout << "Enter the student's name\n";
		cin >> x.name;
		cout << "Enter the student's GPA\n";
		cin >> x.gpa;
		x.allstudents.push_back(x);
		cout << "Student added successfully\n";
	}
	else {
		cout << "Student already exists\n" <<
			"would you like to try again? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { x.news(); }
		else { x.studentmenu(); }
	}
	x.studentmenu();
}

void student::dels() {		//This function deletes an existing student
	long sid;
	student del;
	char confirm;

	cout << "Enter the student id\n";
	cin >> sid;
	if (!del.validatesid(sid)) {	//if the function returns false then the student exists so we can delete them
		for (auto i = del.allstudents.begin(); i != del.allstudents.end(); i++) {
			if (i->id == sid) {
				del.allstudents.erase(i);
				cout << "Student successfully deleted\n";
				break;
			}
		}
	}
	else {
		cout << "Student does not exist\n" << "would you like to try again? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { del.dels(); }
		else { del.studentmenu(); }
	}
	del.studentmenu();
}

void student::lists() {			//This function lists all existing students
	student list;

	for (auto i = list.allstudents.begin(); i != list.allstudents.end(); i++) {
		cout << "Student name: " << i->name << "\n" <<
			"ID: " << i->id << "\n" <<
			"GPA: " << i->gpa << "\n";
	}
	list.studentmenu();
}

bool student::validatesid(long a) {		//This function checks if a certain ID is already acquired by a student or if it is unused
	for (auto i = allstudents.begin(); i != allstudents.end(); i++) {
		if (i->id == a) {
			return false;
		}
	}
	return true;
}

void professor::newprof() {		//This function creates a new professor
	professor newprof;
	long id;
	char confirm;
	cout << "Enter the new professor's id\n";
	cin >> id;
	if (validateid(id)) {
		newprof.id = id;
		cout << "Enter the professor's name\n";
		cin >> newprof.name;
		newprof.allprof.push_back(newprof);
	}
	else {
		cout << "This professor ID already exits\n";
		cout << "Do you want to try again? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') {
			newprof.newprof();
		}
		else { newprof.professormenu(); }
	}
	newprof.professormenu();
}

void professor::delprof() {		//This function deletes an existing professor
	long id;
	char confirm;
	professor del;
	cout << "Enter the ID of the professor you want to delete\n";
	cin >> id;
	if (validateid(id)) {		//checking if professor exists
		cout << "Professor does not exist\n";
		cout << "Would you like to try again? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { del.delprof(); }
		else { del.professormenu(); }
	}
	else {
		for (auto i = del.allprof.begin(); i != del.allprof.end(); i++) {		//finding the professor index in the vector
			if (i->id == id) {
				del.allprof.erase(i);		//deleting professor
				cout << "Professor deleted\n";
				break;		//breaking for loop
			}
		}
	}
}

void professor::listprof() {
	professor list;
	for (auto i = list.allprof.begin(); i != list.allprof.end(); i++) {		//for loop to list all professors
		cout << "Professor Name: " << i->name << "\n"
			<< "Professor ID: " << i->id << "\n";
	}
}

bool professor::validateid(long id) {		//checks if a professor ID is already acquired or unused
	professor p;
	for (auto i = p.allprof.begin(); i != p.allprof.end(); i++) {
		if (i->id == id) {
			return false;
		}
	}
	return true;
}

void section::createsection() {			//This function takes a course code from the user and adds an empty section to the course if it finds it
	course c;
	section news;
	char confirm;
	int num;

	cout << "Enter the section number\n";
	cin >> news.snumber;
	cout << "Enter the course code\n";
	cin >> code;
	if (c.validatecode(code)) {
		cout << "Course does not exist\n" <<
			"Would you like to try again? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { news.createsection(); }
		else {
			news.sectionmenu();
		}
	}
	else {
		news.code = code;
	}
	cout << "Enter the combination of days this section has classes on [UW/MR]\n";
	cin >> news.days;
	cout << "Enter the professor's name\n";
	cin >> news.professor;
	cout << "Enter the time of the class\n";
	cin >> news.time;
	c.sections.push_back(news);
	cout << "Section addded successfully\n";
	news.sectionmenu();
}

void section::modifysection() {			//This function takes a course from the user, if it finds the course, the function then takes\
	a section number, if it finds that section it will ask the user what they want to modify and apply the modifications required
	string str;
	course c;
	char confirm;
	section sec;
	int num;
	int x;
	string newd, newp, newt;

	cout << "Enter the course code\n";
	cin >> str;
	if (c.validatecode(str)) {
		cout << "Course code does not exist\n";
		cout << "Do you want to try again\n? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { sec.modifysection(); }
		else { sec.sectionmenu(); }
	}
	else {
		for (auto i = c.allcourses.begin(); i != c.allcourses.end(); i++) {		//loop to find the course
			if (i->code == str) {
				cout << "Enter the section number\n";
				cin >> num;
				for (auto k = i->sections.begin(); k != i->sections.end(); k++) {		//loop to find the section
					if (k->snumber == num) {
						cout << "Do you want to modify the section's days? [1]\n"		//Options to modify
							<< "or the sections's time? [2] \n"
							<< "or the section's professor? [3] \n"
							<< "or go back? [4]\n";
						cin >> x;
						switch (x) {			//Modifications implementation
						case 1:
							cout << "The old days are: " << k->days << "\n";
							cout << "Please enter the new days\n";
							cin >> newd;
							k->days = newd;
							break;
						case 2:
							cout << "The old section time is: " << k->time << "\n";
							cout << "Enter the new time\n";
							cin >> newt;
							k->time = newt;
							break;
						case 3:
							cout << "This section's professor is " << k->professor << "\n";
							cout << "Enter the new professor\n";
							cin >> newp;
							k->professor = newp;
							break;
						case 4:
							sec.sectionmenu();
						default:
							cout << "Outside of range. Try again\n";
							sec.modifysection();
						}
					}
				}
			}
		}
	}
	sec.sectionmenu();
}

void section::delsection() {		//This function takes a course code, if it finds it, it will then take the section number, and if it finds\
	the section it will remove it from the vector
	course s;
	string str;
	char confirm;
	section del;
	int num;

	cout << "Enter the course code\n";
	cin >> str;
	if (s.validatecode(str)) {
		cout << "Course does not exist\n" <<
			"Would you like to try again? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { del.delsection(); }
		else {
			del.sectionmenu();
		}
	}
	else {
		cout << "Enter the section number you want to delete\n";
		cin >> num;
		for (auto i = s.allcourses.begin(); i != s.allcourses.end(); i++) {
			if (i->code == str) {
				for (auto k = i->sections.begin(); k != i->sections.end(); k++) {
					if (k->snumber == num) {
						s.sections.erase(k);
						break;
					}
				}
				break;
			}
		}
		cout << "Section deleted successfully\n";
	}
	del.sectionmenu();
}

void section::registudent() {		//This function takes a course code and a section number and adds a student to that section in the course
	string str;
	course c;
	char confirm;
	section sec;
	int num;
	student x;

	cout << "Enter the course code\n";
	cin >> str;
	if (c.validatecode(str)) {
		cout << "Course code does not exist\n";
		cout << "Do you want to try again\n? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { sec.registudent(); }
		else { sec.sectionmenu(); }
	}
	else {
		for (auto i = c.allcourses.begin(); i != c.allcourses.end(); i++) {
			if (i->code == str) {
				cout << "Enter the section number\n";
				cin >> num;
				for (auto k = i->sections.begin(); k != i->sections.end(); k++) {
					if (k->snumber == num) {
						k->students.push_back(x);
						break;
					}
				}
				break;
			}
		}
		cout << "Student registered successfully\n";
		sec.sectionmenu();
	}
}

void section::unregistudent() {		//This function takes a course code and a section num and a student id and deletes that student from the\
	section if it finds them
	string str;
	course c;
	char confirm;
	section sec;
	int num;
	student x;
	long sid;

	cout << "Enter the course code\n";
	cin >> str;
	if (c.validatecode(str)) {
		cout << "Course code does not exist\n";
		cout << "Do you want to try again\n? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { sec.unregistudent(); }
		else { sec.sectionmenu(); }
	}
	else {
		for (auto i = c.allcourses.begin(); i != c.allcourses.end(); i++) {
			if (i->code == str) {
				cout << "Enter the section number\n";
				cin >> num;
				for (auto k = i->sections.begin(); k != i->sections.end(); k++) {
					if (k->snumber == num) {
						cout << "Enter the student ID\n";
						cin >> sid;
						for (auto j = k->students.begin(); j != k->students.end(); j++) {
							if (j->id == sid) {
								sec.students.erase(j);
							}
							break;
						}
						break;
					}
				}
				break;
			}
		}
		cout << "Student unregistered successfully\n";
		sec.sectionmenu();
	}
}

void section::listall() {		//This functions takes a course num and a sec num and lists all the students in that section
	string str;
	course c;
	char confirm;
	section sec;
	int num1;

	cout << "Enter the course code\n";
	cin >> str;
	if (c.validatecode(str)) {
		cout << "Course code does not exist\n";
		cout << "Do you want to try again\n? [y/n]\n";
		cin >> confirm;
		if (confirm == 'y') { sec.listall(); }
		else { sec.sectionmenu(); }
	}
	else {
		for (auto i = c.allcourses.begin(); i != c.allcourses.end(); i++) {
			if (i->code == str) {
				cout << "Enter the section number\n";
				cin >> num1;
				for (auto k = i->sections.begin(); k != i->sections.end(); k++) {
					if (k->snumber == num1) {
						for (auto j = k->students.begin(); j != k->students.end(); j++) {
							cout << "Student name: " << j->name << "\n" <<
								"ID: " << j->id << "\n" <<
								"GPA: " << j->gpa << "\n";
						}
						break;
					}
				}
				break;
			}
		}
		sec.sectionmenu();
	}
}
