#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <vector>
#include <string>
#include <windows.h>
#include <sstream>

using namespace std;
bool svg_check(double block_width);
void svg_end();
void svg_begin(double width, double height);
string make_info_text();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string line_colour = "black", string fill = "black");
void show_histogram_svg(const vector<size_t>& bins);
#endif // SVG_H_INCLUDED
