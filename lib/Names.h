#include <iostream>
#include <C:\Users\kordax\Documents\Visual Studio 2013\std_lib_facilities.h>

using namespace std;

namespace Names {

	class NameAge {
	public:
		class Invalid { };

		// Constructor
		NameAge(vector<string> name, vector<double> age);
		NameAge() {};
		// end Constructor

		//========================================================

		void read_names()
		{
			string tempname;
			size = 0;
			for (int i = 0; i <= size; ++i)
			{
				cout << "Enter " << i + 1 << " name or 'q' to quit: ";
				cin >> tempname;
				if (tempname == "q") return;
				//cout << '\n';
				name.push_back(tempname);
				size = size + 1;
			}
		}; // read_names

		//========================================================

		void read_ages()
		{
			double tempage;
			for (int i = 0; i < size; ++i)
			{
				cout << "Enter " << i + 1 << " age: ";
				cin >> tempage;
				//cout << '\n';
				age.push_back(tempage);
			}
		};

		//========================================================

		void print()
		{
			for (int i = 0; i < size; ++i)
			{
				cout << i + 1 << " name is: " << name[i] << ',' << " age is: " << age[i];
				cout << '\n';
			}
		}

		//========================================================

		int return_size()
		{
			return size;
		}

		//========================================================

		void sort()
		{
			for (int i = 0; i < size; ++i)
			for (int n = i + 1; n < size; ++n)
			{
				if (name[n] < name[i])
				{
					buffername = name[n];
					bufferage = age[n];
					name[n] = name[i];
					age[n] = age[i];
					name[i] = buffername;
					age[i] = bufferage;
				}
			}
			// 7 2 4 5 1
			// 1 2 4 5 7
		}

		//========================================================

		void sort_age()
		{
			for (int i = 0; i < size; ++i)
			for (int n = i + 1; n < size; ++n)
			{
				if (age[n] < age[i])
				{
					bufferage = age[n];
					buffername = name[n];
					age[n] = age[i];
					name[n] = name[i];
					age[i] = bufferage;
					name[i] = buffername;
				}
			}
		}

		//========================================================

		void erase_all()
		{
			name.clear();
			age.clear();
			size = 0;
		}

		//========================================================

		//========================================================

		// non-modifying operations:

		vector<string> name;
		vector<double> age;
		int size;
	private:
		string buffername;
		double bufferage;

	}; // end NameAge

	//========================================================

	ostream& operator<<(ostream& os, const NameAge& Pairs)
	{
		for (int i = 0; i < Pairs.size; ++i)
		{
			os << Pairs.name[i] << ", " << Pairs.age[i] << '\n';
		}
		return os;
	};

	//========================================================
} // end namespace Names