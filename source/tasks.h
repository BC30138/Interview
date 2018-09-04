#ifndef _TASKS_H_
#define _TASKS_H_

#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

struct point
{
    double x, y;
};

inline bool comp_x(const point& left_hand, const point& right_hand)
{
    return left_hand.x < right_hand.x || 
            (left_hand.x == right_hand.x && left_hand.y < right_hand.y); 
}

inline bool comp_y(const point& left_hand, const point& right_hand)
{
    return left_hand.y < right_hand.y;
}

class task_one
{
    vector<point> points_;
    pair<unsigned int, unsigned int> nearest_points_id_;
    bool nearest_func_flag;

    public: 
    task_one(istream& input)
    {   
        //reading points from a file
        while (!input.eof()) 
        {
            point temp;
            input >> temp.x >> temp.y; 
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