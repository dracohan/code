//merge file1 and file2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string trimString(string &str)
{
	string delims(" \t");
    int s = str.find_first_not_of(delims);
    int e = str.find_last_not_of(delims);
    return str.substr(s,e-s+1);
}

int main() {

	string majorline1, majorline2,minorline1, minorline2,criticalline1, criticalline2;

	ifstream majorinFile1("D:\\cygwin\\home\\baoweih\\script\\LTE\\rfm_fault_major_name.txt");
	ifstream majorinFile2("D:\\cygwin\\home\\baoweih\\script\\LTE\\rfm_fault_major_value.txt");
	ofstream majoroutFile("D:\\cygwin\\home\\baoweih\\script\\LTE\\rfm_fault_major_case.txt");
	ifstream minorinFile1("D:\\cygwin\\home\\baoweih\\script\\LTE\\rfm_fault_minor_name.txt");
	ifstream minorinFile2("D:\\cygwin\\home\\baoweih\\script\\LTE\\rfm_fault_minor_value.txt");
	ofstream minoroutFile("D:\\cygwin\\home\\baoweih\\script\\LTE\\rfm_fault_minor_case.txt");
	ifstream criticalinFile1("D:\\cygwin\\home\\baoweih\\script\\LTE\\rfm_fault_critical_name.txt");
	ifstream criticalinFile2("D:\\cygwin\\home\\baoweih\\script\\LTE\\rfm_fault_critical_value.txt");
	ofstream criticaloutFile("D:\\cygwin\\home\\baoweih\\script\\LTE\\rfm_fault_critical_case.txt");
	for(int i = 1; i < 109; ++i)
	{
		getline(majorinFile1, majorline1);
		getline(majorinFile2, majorline2);
		majoroutFile << "lr141/ro/rfm_fault_recovery/rfm_fault_8A -eccm $eccm -active_rfm_ro $rfm_ro -rrh $rrh -fault_name " << trimString(majorline1) << " -severity MAJOR -fault_num \"" << trimString(majorline2) << "\"\n";
	}

	for(int i = 1; i < 18; ++i)
	{
		getline(minorinFile1, minorline1);
		getline(minorinFile2, minorline2);
		minoroutFile << "lr141/ro/rfm_fault_recovery/rfm_fault_8A -eccm $eccm -active_rfm_ro $rfm_ro -rrh $rrh -fault_name " << trimString(minorline1) << " -severity MINOR -fault_num \"" << trimString(minorline2) << "\"\n";

	}

	for(int i = 1; i < 13; ++i)
	{
		getline(criticalinFile1, criticalline1);
		getline(criticalinFile2, criticalline2);
		criticaloutFile << "lr141/ro/rfm_fault_recovery/rfm_fault_8A -eccm $eccm -active_rfm_ro $rfm_ro -rrh $rrh -fault_name " << trimString(criticalline1) << " -severity CRITICAL -fault_num \"" << trimString(criticalline2) << "\"\n";

	}
}