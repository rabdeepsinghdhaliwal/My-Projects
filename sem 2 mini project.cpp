#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<cctype>
#include<fstream>
#include<vector>
using namespace std;
//please keep in mind that this program is a single user program.	
//setup a friend function for this class for the user to create a strong password
//The comments below in the file handling part are extremely important to know what is happening
class customerinfo
{
private:
	string username;
	string password;
	string DOB;
	int mobnumber;
public:
	customerinfo(string name = "none", string pass = "no", string date = "0/0/0", int mob = 0)
	{
		username = name;
		password = pass;
		DOB = date;
		mobnumber = mob;
	}
	void set_name(const string& str)
	{
		username = str;
	}
	void set_dob(const string& ddr)
	{
		DOB = ddr;
	}
	void set_pass(const string& ppr)
	{
		password = ppr;
	}
	void set_mob(int k)
	{
		mobnumber = k;
	}
	string get_name()
	{
		return username;
	}
	string get_pass()
	{
		return password;
	}
	string get_DOB()
	{
		return DOB;
	}
	int get_mob()
	{
		return mobnumber;
	}
	void display_info()
	{
		cout << "\nThe information that you have entered is as follows:-";
		cout << "\nNAME: " << username;
		cout << "\npassword: " << password;
		cout << "\nDOB: " << DOB;
		cout << "\nMobile number: " << mobnumber;
	}
	friend int password_strength_evaluator(const string &pass);
};
class shoppingcart
{
public:
	vector<int> nums = {0};   //the shortisted array object has to be put in this vector object called nums and then calculate the total price.
	friend int bill_calculator(vector<int> tr);
};

int bill_calculator(vector<int> tr)
{
	int sum = 0;
	for (int i = 0; i < tr.size(); i++)
	{
		sum = sum + tr[i];
	}
	return sum;
}


//creating supporting functions for the help of the password strength evaluation's main function

int has_upper(const string& trass)
{
	int count = 0;
	for(int i = 0; i < trass.length(); i++)
	{
		if (trass[i] >= 65 && trass[i] <= 90)
		{
			count++;
		}
	}
	if (count == 0)
		return 0;
	else
		return 1;
}
int has_lower(const string& grass)
{
	int count = 0;
	for (int i = 0; i < grass.length(); i++)
	{
		if (grass[i] >= 97 && grass[i] <= 122)
		{
			count++;
		}
	}
	if (count == 0)
		return 0;
	else
		return 1;
}
int has_specialcharacters(const string& lass)
{
	int count = 0;
	for (int i = 0; i < lass.length(); i++)
	{
		if (!(isalnum(lass[i])))
		{
			count++;   //if the character is NOT alphanumeric then +1
		}
	}
	if (count == 0)
		return 0;
	else
		return 1;
}
//the function of the password generator that will be called in the main function
int password_strength_evaluator(const string& pass)  //if this function upon evaluation return 0 the user will be asked to set the password again.
{                                                    //this function is set to return 0 if pass is not strong and 1 if the pass is strong.
	cout << "\nSending the password to the other helper functions for evaluation";
	if ((has_upper(pass) == 1) && (has_lower(pass) == 1) && (has_specialcharacters(pass) == 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
	customerinfo c1;  //only one object of the class is required as the programme is limited to one user only
	while (true)  //this is an infinite loop which will keep on executing until a break statement is encountered because the statement true will always remain true.
	{
		cout << "\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
		cout << "\n\n\n\t\t\t\t\t\t\tFOOD FRENZY";
		cout << "\n\n\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
		cout << "\n\n\n->Please press 1 to SIGN UP";
		cout << "\n->Please press 2 to LOG IN";
		cout << "\n->Please press 3 to LOG OUT/EXIT";
		int choice;
		cin >> choice;
		cin.ignore();
		if (choice == 1)   //the user has chosen to sign up
		{
			system("cls");
			cout << "\nYou have chosen to create a new account\nPlease enter the following details:-\n";
			cout << "USERNAME: ";
			string n;
			getline(cin, n);
			c1.set_name(n);
			cout << "\nDate of birth: ";
			string d;
			getline(cin, d);
			c1.set_dob(d);
			string pass;
			int strength;
			do
			{
				cout << "\nPassword to be set: ";
				getline(cin, pass);
				strength = password_strength_evaluator(pass);
				if (strength == 0)
				{
					cout << "\nThe password that you have entered is not strong. Please reenter the password.";
					cout << "\nIt should contain at least one uppercase , one lowercase and one special character!!";
				}
			} while (strength == 0);

			cout << "\nThe password is strong, so the new password is set";
			c1.set_pass(pass);
			cout << "\nMobile number: ";
			int k;
			cin >> k;
			cin.ignore();
			c1.set_mob(k);
			cout << "\nThe information that you have entered is: ";
			c1.display_info();
			//NOW A FILE HAS TO BE CREATED VIA FILE HANDLING TO CREATE A SEPARATE FILE FOR THE USER
			ofstream objfile("Customerinfo_from_project.txt");  //this will open a text file named customerinfo_from_project.
			objfile << c1.get_name() << endl;    //these statements are there to insert all the content into the file to create the file 
			objfile << c1.get_DOB() << endl;     //this order in which the information if fed inside the file is paramount to t=retrieve it back also
			objfile << c1.get_pass() << endl;
			objfile << c1.get_mob() << endl;
			objfile.close();
			break;
		}
		else if (choice == 2)   //the user has chosen to log in 
		{
			system("cls");
			bool check = false;
			do
			{
				string* conpass = new string;
				cout << "\nPlease enter the password to login to your account, retrieve your information and see your previous orders: ";
				getline(cin, *conpass);
				ifstream infile;   //file object and ifstream is written for reading the contents from the file.
				infile.open("Customerinfo_from_project.txt");  //this will open the file which is ALREADY/MUST BE existing.
				if (!infile)
				{
					cout << "\nThe file can't be opened";
					return 0;
				}
				//NOW CHECK FOR THE PASS SAME AS THE CONPASS INSIDE THE FILE!!
				//the order is name dob password and then mobile number for each user so we will use a while loop to read all of these things in order and then check the conpass with the password until true 
				string username, dob, password;
				int mobile;

				while (infile >> username >> dob >> password >> mobile)  //read everything in order from the existing file into thhe infile ifstream(reading) object
				{                                    //In summary, the loop will read as many sets of values from the file as there are, and it will stop when it encounters the end of the file or when it fails to read values into any of the variables. Any remaining values in the file after reading all the variables will be left untouched.
					if (password == *conpass)
					{
						cout << "\nThe login was successful! your information is as follows:-";
						//cannot use the display function as we have to read from the file only WHICH IS ARRANGED IN A SPECIFIC ORDER for EACH USER
						cout << "\nWELCOME BACK " << username << "!!";
						cout << "\npassword: " << password;
						cout << "\nDOB: " << dob;
						cout << "\nMobile number: " << mobile;
						check = true;
						break;    //since EOF has been achieved the break statement may or may not be necessary. this can be verified by running the program even after this break is removed
					}
				}
				if (!check)
				{
					cout << "\nLOGIN UNSUCESSFULL";
					cout << "\nThe password that you have entered is incorrect";
					cout << "\nPlease reenter the correct password.";
					//After reading in the values from the file below...I will have to set the file pointer again back to the beggining for reexecution!!
				}
				delete conpass;
				infile.close();
			} while (!check);   //this means do the abve tasks while the check2 boolean is not true


			break;
		}
		else if (choice == 3)
		{
			for (int i = 0; i <= 5; i++)
			{
				cout << "\nThe programme has ended !!" << flush;
				this_thread::sleep_for(chrono::seconds(1));  //pauses the execution of the program for 1 seconds.
				cout << "\r                        " << flush;    //clears the previous message
				this_thread::sleep_for(chrono::seconds(1));   //pauses the programme for 1 second until the executions of the code is not completed for 5 times
			}
			return 0;
		}
		else
		{
			cout << "\nPlease enter a valid choice";    //upon the user entering any other invalid choice the user will be prompted to enter the choices again.
		}
	}
	this_thread::sleep_for(chrono::seconds(5));
	
	system("cls");
	
	shoppingcart s1;   //this has to be declared outside because if the user decides to order more dishes again from a different cuisines I will have to add th price total
	int ultimate = 0;
	while (ultimate == 0)
	{
		cout << "\nPlease enter index of one of the following choices as per your requirement";
		int tr = 0;
		while (tr == 0)
		{
			cout << "\n1.]AVAILABLE CUISINES\n2.]MOST ORDERED DISHES\n3.]BEST RESTAURANTS \nindex: ";
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				tr = 1;
				cout << "\nThe available cuisines are as follows: ";
				cout << "\n1.]Chinese\n2.]Continental\n3.]Italian\n4.]Mughlai\n5.]South Indian\n6.]Mexican";
				cout << "\nPlease enter the index of the cuisine that you want to order: ";
				int choicecuisine;
				bool isvalid = true;
				do
				{
					cin >> choicecuisine;
					switch (choicecuisine)
					{

					case 1:
					{
						cout << "\nThe Chinese dishes are as follows :-";
						cout << "\n1.}Honey chilli potato => 200/-";
						cout << "\n2.}Dumplings => 50/-";
						cout << "\n3.}Chowmein => 300/-";
						cout << "\n4.}Peking Duck => 400/-";
						cout << "\n5.}Kung Pao Chicken  => 300/-";
						cout << "\n6.}Hot Pot => 300/-";
						cout << "\n7.}Spring Rolls => 200/-";
						cout << "\n8.}Mapo Tofu => 250/-";
						cout << "\n9.}Szechuan Beef  => 200/-";
						cout << "\n10.}Shrimp Fried Rice => 400/-";
						cout << "\n11.}Sweet and Sour Pork  => 500/-";
						cout << "\n12.}Egg Rolls  => 300/-";
						cout << "\n13.}Ma Po Dou Fu=> 300/-";
						cout << "\n14.}Char Siu => 100/-";
						cout << "\n15.}Dim Sum=> 150/-";
						cout << "\n16.}Yangzhou Fried Rice => 300/-";
						cout << "\n17.}Sesame Chicken => 300/-";
						cout << "\n18.}Scallion Pancakes  => 300/-";
						cout << "\n19.}Wonton Soup  => 250/-";
						cout << "\n20.}Beef Noodle Soup => 200/-";
						cout << "\n21.}Xiao Long Bao=> 300/-";
						cout << "\n22.}General Tso's Chicken  => 300/-";
						cout << "\n23.}Salt and Pepper Squid  => 400/-";
						cout << "\n24.}Baozi  => 400/-";
						cout << "\n25.}Sichuan Hot Pot  => 500/-";
						cout << "\n26.}Fried Wontons   => 200/-";
						cout << "\n27.}Buddha's Delight  => 300/-";
						cout << "\n28.}Pineapple Chicken => 500/-";
						cout << "\n29.}Steamed Fish  => 500/-";
						cout << "\n30.}Dan Dan Noodles  => 300/-";
						int counttillnumofdishes;
						do
						{
							cout << "\nPlease enter the index of the dish that you desire: ";
							int* choiceofdish = new int;
							int* qty = new int;
							bool validity = true;
							int arr[30] = { 200, 50, 300, 400, 300, 300, 200, 250, 200, 400, 500, 300, 300, 100, 150, 300, 300, 300, 250, 200, 300, 300, 400, 400, 500, 200, 300, 500, 500, 300 };
							do
							{
								cin >> *choiceofdish;
								if (*choiceofdish == 1)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;   //handle the error for the incorrect quantity entered.
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[0]);
									}
								}
								else if (*choiceofdish == 2)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[1]);
									}
								}
								else if (*choiceofdish == 3)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[2]);
									}
								}
								else if (*choiceofdish == 4)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[3]);
									}
								}
								else if (*choiceofdish == 5)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[4]);
									}
								}
								else if (*choiceofdish == 6)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[5]);
									}
								}
								else if (*choiceofdish == 7)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[6]);
									}
								}
								else if (*choiceofdish == 8)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[7]);
									}
								}
								else if (*choiceofdish == 9)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[8]);
									}
								}
								else if (*choiceofdish == 10)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[9]);
									}
								}
								else if (*choiceofdish == 11)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[10]);
									}
								}
								else if (*choiceofdish == 12)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[11]);
									}
								}
								else if (*choiceofdish == 13)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[12]);
									}
								}
								else if (*choiceofdish == 14)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[13]);
									}
								}
								else if (*choiceofdish == 15)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[14]);
									}
								}
								else if (*choiceofdish == 16)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[15]);
									}
								}
								else if (*choiceofdish == 17)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[16]);
									}
								}
								else if (*choiceofdish == 18)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[17]);
									}
								}
								else if (*choiceofdish == 19)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[18]);
									}
								}
								else if (*choiceofdish == 20)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[19]);
									}
								}
								else if (*choiceofdish == 21)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[20]);
									}
								}
								else if (*choiceofdish == 22)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[21]);
									}
								}
								else if (*choiceofdish == 23)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[22]);
									}
								}
								else if (*choiceofdish == 24)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[23]);
									}
								}
								else if (*choiceofdish == 25)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[24]);
									}
								}
								else if (*choiceofdish == 26)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[25]);
									}
								}
								else if (*choiceofdish == 27)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[26]);
									}
								}
								else if (*choiceofdish == 28)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[27]);
									}
								}
								else if (*choiceofdish == 29)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[28]);
									}
								}
								else if (*choiceofdish == 30)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[29]);
									}
								}
								else
								{
									validity = false;
									cout << "\nPlease enter the correct choice: ";
								}
								delete qty;
								delete choiceofdish;
							} while (validity == false);
							cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
							int tried;
							cin >> tried;
							if (tried == 1)
							{
								counttillnumofdishes = 0;
							}
							else if (tried == 2)
							{
								counttillnumofdishes = 1;
							}
						} while (counttillnumofdishes == 0);

						isvalid = true;

						break;
					}
					case 2:
					{
						cout << "\nThe Continental dishes are as follows :-";
						cout << "\n1.}Coq Au Vin => 520/-";
						cout << "\n2.}Ratatouille => 870/-";
						cout << "\n3.}Moussaka => 1000/-";
						cout << "\n4.}Beef Bourguignon => 1010/-";
						cout << "\n5.}Paella => 1015/-";
						cout << "\n6.}Beef Wellington => 1020/-";
						cout << "\n7.}Chicken Cordon Bleu => 1025/-";
						cout << "\n8.}Quiche Lorraine => 1030/-";
						cout << "\n9.}Beef Stroganoff => 1035/-";
						cout << "\n10.}Fish and Chips => 1040/-";
						cout << "\n11.}Chicken Parmesan => 1045/-";
						cout << "\n12.}Caesar Salad => 1050/-";
						cout << "\n13.}Shepherd's Pie => 1055/-";
						cout << "\n14.}Tiramisu => 1060/-";
						cout << "\n15.}Risotto => 1065/-";
						cout << "\n16.}Chicken Alfredo => 1070/-";
						cout << "\n17.}Bouillabaisse => 1075/-";
						cout << "\n18.}Croque Monsieur => 1080/-";
						cout << "\n19.}Beef Carpaccio => 1085/-";
						cout << "\n20.}Goulash => 1090/-";
						cout << "\n21.}Potato Gratin => 1095/-";
						cout << "\n22.}Eggs Benedict => 1100/-";
						cout << "\n23.}Beef Tacos => 1105/-";
						cout << "\n24.}French Onion Soup => 1110/-";
						cout << "\n25.}Beef Lasagna => 1115/-";
						cout << "\n26.}Duck à l'Orange => 1120/-";
						cout << "\n27.}Shrimp Scampi => 1125/-";
						cout << "\n28.}Beef Ragù => 1130/-";
						cout << "\n29.}Chicken Fricassee => 1135/-";
						cout << "\n30.}Spaghetti and meatballs => 305/-";
						int counttillnumofdishes;
						do
						{
							cout << "\nPlease enter the index of the dish that you desire: ";
							int* choiceofdish = new int;
							int* qty = new int;
							bool validity = true;
							int arr[30] = { 520, 870, 1000, 1010, 1015, 1020, 1025, 1030, 1035, 1040, 1045, 1050, 1055, 1060, 1065, 1070, 1075, 1080, 1085, 1090, 1095, 1100, 1105, 1110, 1115, 1120, 1125, 1130, 1135, 305 };
							do
							{
								cin >> *choiceofdish;
								if (*choiceofdish == 1)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;   //handle the error for the incorrect quantity entered.
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[0]);
									}
								}
								else if (*choiceofdish == 2)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[1]);
									}
								}
								else if (*choiceofdish == 3)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[2]);
									}
								}
								else if (*choiceofdish == 4)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[3]);
									}
								}
								else if (*choiceofdish == 5)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[4]);
									}
								}
								else if (*choiceofdish == 6)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[5]);
									}
								}
								else if (*choiceofdish == 7)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[6]);
									}
								}
								else if (*choiceofdish == 8)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[7]);
									}
								}
								else if (*choiceofdish == 9)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[8]);
									}
								}
								else if (*choiceofdish == 10)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[9]);
									}
								}
								else if (*choiceofdish == 11)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[10]);
									}
								}
								else if (*choiceofdish == 12)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[11]);
									}
								}
								else if (*choiceofdish == 13)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[12]);
									}
								}
								else if (*choiceofdish == 14)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[13]);
									}
								}
								else if (*choiceofdish == 15)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[14]);
									}
								}
								else if (*choiceofdish == 16)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[15]);
									}
								}
								else if (*choiceofdish == 17)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[16]);
									}
								}
								else if (*choiceofdish == 18)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[17]);
									}
								}
								else if (*choiceofdish == 19)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[18]);
									}
								}
								else if (*choiceofdish == 20)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[19]);
									}
								}
								else if (*choiceofdish == 21)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[20]);
									}
								}
								else if (*choiceofdish == 22)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[21]);
									}
								}
								else if (*choiceofdish == 23)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[22]);
									}
								}
								else if (*choiceofdish == 24)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[23]);
									}
								}
								else if (*choiceofdish == 25)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[24]);
									}
								}
								else if (*choiceofdish == 26)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[25]);
									}
								}
								else if (*choiceofdish == 27)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[26]);
									}
								}
								else if (*choiceofdish == 28)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[27]);
									}
								}
								else if (*choiceofdish == 29)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[28]);
									}
								}
								else if (*choiceofdish == 30)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[29]);
									}
								}
								else
								{
									validity = false;
									cout << "\nPlease enter the correct choice: ";
								}
								delete qty;
								delete choiceofdish;
							} while (validity == false);
							cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
							int tried;
							cin >> tried;
							if (tried == 1)
							{
								counttillnumofdishes = 0;
							}
							else if (tried == 2)
							{
								counttillnumofdishes = 1;
							}
						} while (counttillnumofdishes == 0);

						isvalid = true;
						break;
					}
					case 3:
					{
						cout << "\nThe Italian dishes are as follows :-";
						cout << "\n1.}Pizza => 300/-";
						cout << "\n2.}Pasta => 150/-";
						cout << "\n3.}Spaghetti and meatballs => 490/-";
						cout << "\n4.}Pizza Margherita => 300/-";
						cout << "\n5.}Spaghetti Bolognese=> 300/-";
						cout << "\n6.}Lasagna => 300/-";
						cout << "\n7.}Risotto alla Milanese=> 300/-";
						cout << "\n8.}Fettuccine Alfredo=> 300/-";
						cout << "\n9.}Ravioli => 300/-";
						cout << "\n10.}Osso Buco => 350/-";
						cout << "\n11.}Caprese Salad=> 200/-";
						cout << "\n12.}Tiramisu => 300/-";
						cout << "\n13.}Bruschetta => 550/-";
						cout << "\n14.}Cannelloni => 300/-";
						cout << "\n15.}Carbonara => 350/-";
						cout << "\n16.}Panzanella => 390/-";
						cout << "\n17.}Gnocchi => 300/-";
						cout << "\n18.}Minestrone Soup => 300/-";
						cout << "\n19.}Prosciutto e Melone  => 300/-";
						cout << "\n20.}Arancini => 300/-";
						cout << "\n21.}Focaccia => 890/-";
						cout << "\n22.}Pasta Primavera => 300/-";
						cout << "\n23.}Insalata Caprese => 300/-";
						cout << "\n24.}Calzone => 330/-";
						cout << "\n25.}Polenta => 300/-";
						cout << "\n26.}Orecchiette => 300/-";
						cout << "\n27.}Vitello Tonnato => 300/-";
						cout << "\n28.}Panna Cotta => 300/-";
						cout << "\n29.}Cioppino => 330/-";
						cout << "\n30.}Zuppa Toscana=> 300/-";
						int counttillnumofdishes;
						do
						{
							cout << "\nPlease enter the index of the dish that you desire: ";
							int* choiceofdish = new int;
							int* qty = new int;
							bool validity = true;  //for the correct choice of the dishes.
							//see that the price of the each of the dishes is being stored according to the index in an array.
							int arr[30] = { 300 , 150 , 490 , 300 , 300 , 400 , 300 , 450 , 300 , 350 , 200 , 300 , 550 , 300 , 350 , 390 , 300 , 300 , 300 , 300 , 390 , 300 , 600 , 330 , 300 , 3000 , 300 , 300 , 330 , 300  };  //the size of this array needs to be changed as per the number of teh dishes.
							//even the price of the dish has to be stored in the array beforehand
							do
							{
								cin >> *choiceofdish;
								if (*choiceofdish == 1)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;   //handle the error for the incorrect quantity entered.
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[0]);
									}
								}
								else if (*choiceofdish == 2)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[1]);
									}
								}
								else if (*choiceofdish == 3)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[2]);
									}
								}
								else if (*choiceofdish == 4)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[3]);
									}
								}
								else if (*choiceofdish == 5)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[4]);
									}
								}
								else if (*choiceofdish == 6)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[5]);
									}
								}
								else if (*choiceofdish == 7)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[6]);
									}
								}
								else if (*choiceofdish == 8)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[7]);
									}
								}
								else if (*choiceofdish == 9)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[8]);
									}
								}
								else if (*choiceofdish == 10)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[9]);
									}
								}
								else if (*choiceofdish == 11)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[10]);
									}
								}
								else if (*choiceofdish == 12)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[11]);
									}
								}
								else if (*choiceofdish == 13)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[12]);
									}
								}
								else if (*choiceofdish == 14)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[13]);
									}
								}
								else if (*choiceofdish == 15)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[14]);
									}
								}
								else if (*choiceofdish == 16)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[15]);
									}
								}
								else if (*choiceofdish == 17)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[16]);
									}
								}
								else if (*choiceofdish == 18)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[17]);
									}
								}
								else if (*choiceofdish == 19)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[18]);
									}
								}
								else if (*choiceofdish == 20)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[19]);
									}
								}
								else if (*choiceofdish == 21)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[20]);
									}
								}
								else if (*choiceofdish == 22)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[21]);
									}
								}
								else if (*choiceofdish == 23)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[22]);
									}
								}
								else if (*choiceofdish == 24)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[23]);
									}
								}
								else if (*choiceofdish == 25)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[24]);
									}
								}
								else if (*choiceofdish == 26)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[25]);
									}
								}
								else if (*choiceofdish == 27)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[26]);
									}
								}
								else if (*choiceofdish == 28)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[27]);
									}
								}
								else if (*choiceofdish == 29)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[28]);
									}
								}
								else if (*choiceofdish == 30)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[29]);
									}
								}
								else
								{
									validity = false;
									cout << "\nPlease enter the correct choice: ";
								}
								delete qty;
								delete choiceofdish;
							} while (validity == false);
							cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
							int tried;
							cin >> tried;
							if (tried == 1)
							{
								counttillnumofdishes = 0;
							}
							else if (tried == 2)
							{
								counttillnumofdishes = 1;
							}
						} while (counttillnumofdishes == 0);

						isvalid = true;
						break;
					}
					case 4:
					{
						cout << "\nThe Mughlai dishes are as follows :-";
						cout << "\n1.}Biryani => 300/-";
						cout << "\n2.}Butter chicken => 350/-";
						cout << "\n3.}Rogan Josh => 550/-";
						cout << "\n4.}Chicken Tikka Masala => 140/-";
						cout << "\n5.}Kebabs => 100/-";
						cout << "\n6.}Shahi Paneer => 110/-";
						cout << "\n7.}Chicken Korma => 120/-";
						cout << "\n8.}Mutton Korma => 130/-";
						cout << "\n9.}Dal Makhani => 150/-";
						cout << "\n10.}Tandoori Chicken => 140/-";
						cout << "\n11.}Seekh Kebab => 130/-";
						cout << "\n12.}Palak Paneer => 110/-";
						cout << "\n13.}Chicken Biryani => 120/-";
						cout << "\n14.}Nihari => 100/-";
						cout << "\n15.}Dum Pukht => 140/-";
						cout << "\n16.}Malai Kofta => 140/-";
						cout << "\n17.}Galouti Kebab => 120/-";
						cout << "\n18.}Reshmi Kebab => 130/-";
						cout << "\n19.}Paneer Tikka => 120/-";
						cout << "\n20.}Korma => 150/-";
						cout << "\n21.}Mughlai Paratha => 120/-";
						cout << "\n22.}Mutton Biryani => 130/-";
						cout << "\n23.}Chapli Kebab => 110/-";
						cout << "\n24.}Murgh Malaiwala => 130/-";
						cout << "\n25.}Sheermal => 120/-";
						cout << "\n26.}Boti Kebab => 130/-";
						cout << "\n27.}Murg Musallam => 110/-";
						cout << "\n28.}Chicken Rezala => 120/-";
						cout << "\n29.}Pasanda => 130/-";
						cout << "\n30.}Shami Kebab => 110/-";
						int counttillnumofdishes;
						do
						{
							cout << "\nPlease enter the index of the dish that you desire: ";
							int* choiceofdish = new int;
							int* qty = new int;
							bool validity = true;
							int arr[30] = { 300, 350, 550, 140, 100, 110, 120, 130, 150, 140, 130, 110, 120, 100, 140, 140, 120, 130, 120, 150, 120, 130, 110, 130, 120, 130, 110, 120, 130, 110 };
							do
							{
								cin >> *choiceofdish;
								if (*choiceofdish == 1)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;   //handle the error for the incorrect quantity entered.
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[0]);
									}
								}
								else if (*choiceofdish == 2)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[1]);
									}
								}
								else if (*choiceofdish == 3)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[2]);
									}
								}
								else if (*choiceofdish == 4)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[3]);
									}
								}
								else if (*choiceofdish == 5)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[4]);
									}
								}
								else if (*choiceofdish == 6)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[5]);
									}
								}
								else if (*choiceofdish == 7)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[6]);
									}
								}
								else if (*choiceofdish == 8)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[7]);
									}
								}
								else if (*choiceofdish == 9)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[8]);
									}
								}
								else if (*choiceofdish == 10)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[9]);
									}
								}
								else if (*choiceofdish == 11)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[10]);
									}
								}
								else if (*choiceofdish == 12)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[11]);
									}
								}
								else if (*choiceofdish == 13)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[12]);
									}
								}
								else if (*choiceofdish == 14)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[13]);
									}
								}
								else if (*choiceofdish == 15)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[14]);
									}
								}
								else if (*choiceofdish == 16)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[15]);
									}
								}
								else if (*choiceofdish == 17)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[16]);
									}
								}
								else if (*choiceofdish == 18)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[17]);
									}
								}
								else if (*choiceofdish == 19)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[18]);
									}
								}
								else if (*choiceofdish == 20)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[19]);
									}
								}
								else if (*choiceofdish == 21)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[20]);
									}
								}
								else if (*choiceofdish == 22)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[21]);
									}
								}
								else if (*choiceofdish == 23)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[22]);
									}
								}
								else if (*choiceofdish == 24)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[23]);
									}
								}
								else if (*choiceofdish == 25)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[24]);
									}
								}
								else if (*choiceofdish == 26)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[25]);
									}
								}
								else if (*choiceofdish == 27)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[26]);
									}
								}
								else if (*choiceofdish == 28)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[27]);
									}
								}
								else if (*choiceofdish == 29)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[28]);
									}
								}
								else if (*choiceofdish == 30)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[29]);
									}
								}
								else
								{
									validity = false;
									cout << "\nPlease enter the correct choice: ";
								}
								delete qty;
								delete choiceofdish;
							} while (validity == false);
							cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
							int tried;
							cin >> tried;
							if (tried == 1)
							{
								counttillnumofdishes = 0;
							}
							else if (tried == 2)
							{
								counttillnumofdishes = 1;
							}
						} while (counttillnumofdishes == 0);

						isvalid = true;
						break;
					}
					case 5:
					{
						cout << "\nThe South Indian dishes are as follows :-";
						cout << "\n1.}Uttappam => 200/-";
						cout << "\n2.}Idlii and sambhar => 120/-";
						cout << "\n3.}Vadaa and sambhar => 130/-";
						cout << "\n4.}Dosa and sambhar => 130/-";
						cout << "\n5.}Rasam => 130/-";
						cout << "\n6.}Pongal => 130/-";
						cout << "\n7.}Upma=> 130/-";
						cout << "\n8.}Bisi Bele Bath=> 130/-";
						cout << "\n9.}Lemon Rice => 130/-";
						cout << "\n10.}Coconut Chutneyr => 130/-";
						cout << "\n11.}Medu Vada => 200/-";
						cout << "\n12.}Masala Dosa => 120/-";
						cout << "\n13.}Appam => 130/-";
						cout << "\n14.}Pesarattu=> 130/-";
						cout << "\n15.}Avial=> 130/-";
						cout << "\n16.}Kara Kuzhambu => 130/-";
						cout << "\n17.}Thakkali Thokku=> 130/-";
						cout << "\n18.}Thakkali Thokku => 130/-";
						cout << "\n19.}Mysore Dosa => 130/-";
						cout << "\n20.}Bombard Dosa => 130/-";
						int counttillnumofdishes;
						do
						{
							cout << "\nPlease enter the index of the dish that you desire: ";
							int* choiceofdish = new int;
							int* qty = new int;
							bool validity = true;
							int arr[20] = { 200, 120, 130, 130, 130, 130, 130, 130, 130, 130, 200, 120, 130, 130, 130, 130, 130, 130, 130, 130 };
							do
							{
								cin >> *choiceofdish;
								if (*choiceofdish == 1)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;   //handle the error for the incorrect quantity entered.
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[0]);
									}
								}
								else if (*choiceofdish == 2)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[1]);
									}
								}
								else if (*choiceofdish == 3)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[2]);
									}
								}
								else if (*choiceofdish == 4)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[3]);
									}
								}
								else if (*choiceofdish == 5)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[4]);
									}
								}
								else if (*choiceofdish == 6)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[5]);
									}
								}
								else if (*choiceofdish == 7)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[6]);
									}
								}
								else if (*choiceofdish == 8)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[7]);
									}
								}
								else if (*choiceofdish == 9)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[8]);
									}
								}
								else if (*choiceofdish == 10)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[9]);
									}
								}
								else if (*choiceofdish == 11)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[10]);
									}
								}
								else if (*choiceofdish == 12)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[11]);
									}
								}
								else if (*choiceofdish == 13)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[12]);
									}
								}
								else if (*choiceofdish == 14)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[13]);
									}
								}
								else if (*choiceofdish == 15)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[14]);
									}
								}
								else if (*choiceofdish == 16)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[15]);
									}
								}
								else if (*choiceofdish == 17)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[16]);
									}
								}
								else if (*choiceofdish == 18)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[17]);
									}
								}
								else if (*choiceofdish == 19)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[18]);
									}
								}
								else if (*choiceofdish == 20)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[19]);
									}
								}
								else
								{
									validity = false;
									cout << "\nPlease enter the correct choice: ";
								}
								delete qty;
								delete choiceofdish;
							} while (validity == false);
							cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
							int tried;
							cin >> tried;
							if (tried == 1)
							{
								counttillnumofdishes = 0;
							}
							else if (tried == 2)
							{
								counttillnumofdishes = 1;
							}
						} while (counttillnumofdishes == 0);

						isvalid = true;
						break;
					}
					case 6:
					{
						cout << "\nThe Mexican dishes are as follows :-";
						cout << "\n1.}Tacos => 160/-";
						cout << "\n2.}Burrito => 320/-";
						cout << "\n3.}Quesadillas => 250/-";
						cout << "\n4.} Pozole => 140/-";
						cout << "\n5.}Tamales => 100/-";
						cout << "\n6.}Quesadillas => 110/-";
						cout << "\n7.}Guacamole => 120/-";
						cout << "\n8.}Fajitas => 130/-";
						cout << "\n9.}Mole Poblano => 150/-";
						cout << "\n10.}Carnitas => 140/-";
						cout << "\n11.}Chilaquiles => 130/-";
						cout << "\n12.}Sopes => 110/-";
						cout << "\n13.}Ceviche => 120/-";
						cout << "\n14.}Barbacoa => 100/-";
						cout << "\n15.}Huevos Rancheros => 140/-";
						cout << "\n16.}Tostadas => 140/-";
						cout << "\n17.}Chile Verde => 120/-";
						cout << "\n18.}Menudo => 130/-";
						cout << "\n19.}Camarones a la Diabla => 120/-";
						cout << "\n20.}Pambazos => 150/-";
						cout << "\n21.}Flautas => 120/-";
						cout << "\n22.}Cochinita Pibil => 130/-";
						cout << "\n23.}Sopa de Tortilla => 110/-";
						cout << "\n24.}Birria => 130/-";
						cout << "\n25.}Molletes => 120/-";
						int counttillnumofdishes;
						do
						{
							cout << "\nPlease enter the index of the dish that you desire: ";
							int* choiceofdish = new int;
							int* qty = new int;
							bool validity = true;
							int arr[25] = { 160, 320, 250, 140, 100, 110, 120, 130, 150, 140, 130, 110, 120, 100, 140, 140, 120, 130, 120, 150, 120, 130, 110, 130, 120 };
							do
							{
								cin >> *choiceofdish;
								if (*choiceofdish == 1)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;   //handle the error for the incorrect quantity entered.
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[0]);
									}
								}
								else if (*choiceofdish == 2)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[1]);
									}
								}
								else if (*choiceofdish == 3)
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[2]);
									}
								}
								else if (*choiceofdish == 4)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[3]);
									}
								}
								else if (*choiceofdish == 5)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[4]);
									}
								}
								else if (*choiceofdish == 6)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[5]);
									}
								}
								else if (*choiceofdish == 7)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[6]);
									}
								}
								else if (*choiceofdish == 8)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[7]);
									}
								}
								else if (*choiceofdish == 9)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[8]);
									}
								}
								else if (*choiceofdish == 10)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[9]);
									}
								}
								else if (*choiceofdish == 11)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[10]);
									}
								}
								else if (*choiceofdish == 12)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[11]);
									}
								}
								else if (*choiceofdish == 13)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[12]);
									}
								}
								else if (*choiceofdish == 14)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[13]);
									}
								}
								else if (*choiceofdish == 15)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[14]);
									}
								}
								else if (*choiceofdish == 16)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[15]);
									}
								}
								else if (*choiceofdish == 17)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[16]);
									}
								}
								else if (*choiceofdish == 18)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[17]);
									}
								}
								else if (*choiceofdish == 19)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[18]);
									}
								}
								else if (*choiceofdish == 20)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[19]);
									}
								}
								else if (*choiceofdish == 21)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[20]);
									}
								}
								else if (*choiceofdish == 22)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[21]);
									}
								}
								else if (*choiceofdish == 23)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[22]);
									}
								}
								else if (*choiceofdish == 24)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[23]);
									}
								}
								else if (*choiceofdish == 25)  //add all the prices in Arr first/
								{
									validity = true;
									cout << "\nPlease enter the correct quantity of the dish to be ordered: ";
									cin >> *qty;
									for (int i = 0; i < *qty; i++)
									{
										s1.nums.push_back(arr[24]);
									}
								}
								else
								{
									validity = false;
									cout << "\nPlease enter the correct choice: ";
								}
								delete qty;
								delete choiceofdish;
							} while (validity == false);
							cout << "\nPlease enter 1 for ordering another dish from the same quisine OR 2 for finishing up the order: ";
							int tried;
							cin >> tried;
							if (tried == 1)
							{
								counttillnumofdishes = 0;
							}
							else if (tried == 2)
							{
								counttillnumofdishes = 1;
							}
						} while (counttillnumofdishes == 0);

						isvalid = true;
						break;
					}

					default:
						cout << "\nThe option that you have entered is invalid and so please enter the valid option";
						isvalid = false;
					}
				} while (isvalid == false);


				break;
			}



			else if (choice == 2)
			{
				tr = 1;
				system("clear");
				std::cout << "88888888ba  88888888888 ad88888ba 888888888888 ad88888ba  88888888888 88        88 88888888888 88888888ba   ad88888ba\n";
				std::cout << "88      \"8b 88         d8\"     \"8b     88     d8\"     \"8b 88          88        88 88      \"8b d8\"     \"8b\n";
				std::cout << "88      ,8P 88         Y8,             88     Y8,         88          88        88 88      ,8P Y8,\n";
				std::cout << "88aaaaaa8P' 88aaaaa    `Y8aaaaa,       88     `Y8aaaaa,   88aaaaa     88        88 88aaaaa8P' `Y8aaaaa,\n";
				std::cout << "88\"\"\"\"\"\"8b, 88\"\"\"\"\"      `\"\"\"\"\"8b,     88       `\"\"\"\"\"8b, 88\"\"\"\"\"     88        88 88\"\"\"\"88'     `\"\"\"\"\"8b,\n";
				std::cout << "88      `8b 88                 `8b     88             `8b 88          88        88 88    `8b           `8b\n";
				std::cout << "88      a8P 88         Y8a     a8P     88     Y8a     a8P 88          88        88 88     `8b  Y8a     a8P\n";
				std::cout << "88888888P\"  88888888888 \"Y88888P\"      88      \"Y88888P\"  88888888888 88888888888 88888888888 88      `8b\n";


				cout << "\n The following are the most ordered dishes:-";
				cout << "\n Rogan josh -> 1500";
				cout << "\n Paneer do Pyaza -> 450";
				cout << "\n MAC and CHEESE pasta -> 990";
				cout << "\n Biryani -> 450";
				cout << "\n Butter Chicken (Murgh Makhani) -> 500";
				cout << "\n Tacos al Pastor -> 400";
				cout << "\n Enchiladas Suizas -> 300";
				cout << "\n Chiles Rellenos -> 400";
				cout << "\n Pozole -> 250";
				cout << "\n Tacos al Pastor -> 770";
				cout << "\n Enchiladas Suizas -> 890";
				cout << "\n Chiles Rellenos -> 750";
				cout << "\n Pozole -> 550";
				cout << "\n Tamales -> 650";
				break;
			}



			else if (choice == 3)
			{
				tr = 1;
				system("clear");
				std::cout << "88888888ba    ,ad8888ba,   88888888ba  88        88 88                 db        88888888ba   ad88888ba   " << std::endl;
				std::cout << "88      \"8b  d8\"'    `\"8b  88      \"8b 88        88 88                d88b       88      \"8b d8\"     \"8b  " << std::endl;
				std::cout << "88      ,8P d8'        `8b 88      ,8P 88        88 88               d8'`8b      88      ,8P Y8,          " << std::endl;
				std::cout << "88aaaaaa8P' 88          88 88aaaaaa8P' 88        88 88              d8'  `8b     88aaaaaa8P' `Y8aaaaa,    " << std::endl;
				std::cout << "88\"\"\"\"\"'    88          88 88\"\"\"\"\"\"\"   88        88 88             d8YaaaaY8b    88\"\"\"\"88'     `\"\"\"\"\"8b,  " << std::endl;
				std::cout << "88          Y8,        ,8P 88          88        88 88            d8\"\"\"\"\"\"\"8b   88    `8b           `8b  " << std::endl;
				std::cout << "88           Y8a.    .a8P  88          Y8a.    .a8P 88           d8'        `8b  88     `8b  Y8a     a8P  " << std::endl;
				std::cout << "88            `\"Y8888Y\"'   88           `\"Y8888Y\"'  88888888888 d8'          `8b 88      `8b  \"Y88888P\"   " << std::endl;
				cout << "\nThe following are the best restaurants and the restaurants that are enlisted here and are at your location";
				cout << "\nThe program needs to be run again for ordering the food";
				cout << "\nITC Mughal";
				cout << "\nHotel Amar Vilas";
				cout << "\nSarovar Priemiere";
				cout << "\nBarco's";
				cout << "\nCarnetic";
				cout << "\nDohful";
				cout << "\nAnna's house";
				return 0;
				break;
			}



			else
			{
				cout << "\nPlease enter a valid choice for the requirement: ";
				tr = 0;
			}
		}
		this_thread::sleep_for(chrono::seconds(4));
		system("clear");
		cout << "\nPlease enter 1 for ordering another dish from a DIFFERENT CUISINE THIS TIME or 2 for finishing up the order: ";
		int tried;
		cin >> tried;

		if (tried == 2)
		{
			ultimate = 1; // Set ultimate to a non-zero value to exit the outer loop
		}
		else if (tried != 1)
		{
			// Invalid input OR for continuing ordering
			cout << "\nInvalid input. Please enter 1 to order another dish or 2 to finish up the order.";
		}
	}
	
	cout << "\nNow the bill of the total order will be displayed: ";
	cout << "\nThe total bill is: " << bill_calculator(s1.nums);    //passing on the vector of the costs to the bill calculator function to return the total cost of the order. 
    
	string s;
	cout << "\nYou can Give feedbacks also: ";
	cin >> s;
	cout << "\n THANK YOU VISIT AGAIN :)" << endl;
	return 0;
}