#ifndef _TASKS_H_
#define _TASKS_H_

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

class task_one
{
    vector< pair<double,double> > points_;
    pair<unsigned int, unsigned int> nearest_points_id_;
    bool nearest_func_flag;

    public: 
    task_one(istream& input)
    {   
        //reading points from a file
        while (!input.eof()) 
        {
            pair<double,double> temp;
            input >> temp.first >> temp.second; 
            points_.push_back(temp);
        }   
        nearest_func_flag = false;
    }
    void nearest_points();
    //void max_points_circle(double radius);
    //void max_points_ring(double sub_radius);
    // void show_results();
};

void plot(string output_filename);
void random_pfile_generator(double left_end, double right_end, unsigned int points_number, ostream &output);

#endif