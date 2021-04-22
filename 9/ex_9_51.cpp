#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class date
{
public:
	date();
	date(string s);
	string return_date();
private:
	void process_full_months(string s);
	void process_abbrev_months(string s);
	void process_numeric_months(string s);
	unsigned int year = 0;
	unsigned int month = 0;
	unsigned int day = 0;
};

date::date(string s)
{
	vector<string> full_months{"January","February","March","April","May","June",
		"July","August","September","October","November","December"};
	vector<string> abbrev_months{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
		 "Aug", "Sep", "Oct", "Nov", "Dec"};
	for (auto s1: full_months)
	{
		if (s.find(s1) != string::npos)
		{
			process_full_months(s);
			return;
		}
	}
	for (auto s2: abbrev_months)
	{
		if (s.find(s2) != string::npos)
		{
			process_abbrev_months(s);
			return;
		}
	}
	
	process_numeric_months(s);
};

void date::process_full_months(string s)
{
	vector<string> full_months{"January","February","March","April","May","June",
		"July","August","September","October","November","December"};

	for(vector<string>::size_type i=0; i<full_months.size(); ++i)
	{
		if(s.find(full_months[i]) != string::npos)
		{
			month = i+1;
			break;
		}
	}
	string::size_type pos_space = s.find(" ");
	string::size_type pos_comma = s.find(",");

	day = stoi(s.substr(pos_space+1, pos_comma-pos_space-1));
	year = stoi(s.substr(pos_comma+1));

};


void date::process_abbrev_months(string s)
{
	vector<string> abbrev_months{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
		 "Aug", "Sep", "Oct", "Nov", "Dec"};

	for(vector<string>::size_type i=0; i<abbrev_months.size(); ++i)
	{
		string current_month(abbrev_months[i]);
		if(s.find(current_month) != string::npos)
		{
			month = i+1;
			break;
		}
	}
	string::size_type pos_space = s.find(" ");
	string::size_type pos_comma = s.find(",");

	day = stoi(s.substr(pos_space+1, pos_comma-pos_space-1));
	year = stoi(s.substr(pos_comma+1));

};


void date::process_numeric_months(string s)
{
	string::size_type pos_slash_1 = s.find("/");
	string::size_type pos_slash_2 = s.find("/",pos_slash_1+1);

	month = stoi(s.substr(0,pos_slash_1));
	day = stoi(s.substr(pos_slash_1+1, pos_slash_2-pos_slash_1-1));
	year = stoi(s.substr(pos_slash_2+1));


};

string date::return_date()
{
	string val;
	val+=std::to_string(year);
	val+="/";
	val+=std::to_string(month);
	val+="/";
	val+=std::to_string(day);
	return val;

};
int main()
{

	date d1("February 1,1900");
	std::cout << d1.return_date() << std::endl;

	date d2("Mar 2,1910");
	std::cout << d2.return_date() << std::endl;

	date d3("7/4/1776");
	std::cout << d3.return_date() << std::endl;

	return 0;
}
