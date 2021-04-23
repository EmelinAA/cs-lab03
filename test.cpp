#include "histogram.h"
#include "svg.h"
#include <cassert>

void test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({ 1, 2, 3 }, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({ -1,-2,-3 }, min, max);
    assert(min == -3);
    assert(max == -1);
}
void test_same()
{
    double min = 0;
    double max = 0;
    find_minmax({ 1,1,1 }, min, max);
    assert(min == 1);
    assert(max == 1);
}
void test_one()
{
    double min = 0;
    double max = 0;
    find_minmax({ 1 }, min, max);
    assert(min == max);
}
void test_empty()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}
void test_negative_block()
{
    double block_width=-5;
    bool check =svg_check(block_width);
    assert(check==false);
}
void test_big_positive_block()
{
    double block_width=100;
    bool check =svg_check(block_width);
    assert(check==false);
}


int main() {
    test_positive();
    test_same();
    test_negative();
    test_empty();
    test_negative_block();
    test_big_positive_block();
}
