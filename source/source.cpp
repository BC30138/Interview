#include"tasks.h"

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream pfile("tests/test_points.dat");
    random_pfile_generator(0, 100, 20, pfile);
    ifstream input_file("tests/test_points.dat");
    task_one test(input_file);
    test.nearest_points();
    // test.show_points();
    // test.nearest_points();
    test.show_results();
    plot("tests/test_points.dat");
}