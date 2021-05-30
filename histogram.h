#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <vector>
#include <iostream>
using namespace std;
struct Input
{
vector <double> numbers;
size_t bin_count;
double block_width=10;
} ;
void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<double> input_numbers(istream& in,size_t count);
Input read_input(istream& in, bool prompt);
vector<size_t> make_histogram(const Input &data);
void   show_histogram_text(vector <size_t> bins);
#endif // HISTOGRAM_H_INCLUDED
