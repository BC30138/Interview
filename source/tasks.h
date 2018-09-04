#ifndef _TASKS_H_
#define _TASKS_H_

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

struct point
{
    double x, y;
    unsigned int id;
};

struct find_point
{
    unsigned int id;
    find_point(unsigned int id) : id(id) {}
    bool operator () ( const point& m ) const
    {
        return m.id == id;
    }
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

inline void swap(point* a, point* b) 
{ 
    point t = *a; 
    *a = *b; 
    *b = t; 
} 
 
inline void quickSort(vector<point> &points, int low, int high) 
{ 
    if (low < high) 
    { 
        point pivot = points[high]; 
        int i = (low - 1); 
        for (int j = low; j <= high- 1; j++) 
        { 
            if (comp_x(points[j], pivot) || (points[j].x == pivot.x && points[j].y == pivot.y))  
            { 
                i++; 
                swap(&points[i], &points[j]); 
            } 
        } 
        swap(&points[i + 1], &points[high]); 
        int part_index = i + 1; 
        quickSort(points, low, part_index - 1); 
        quickSort(points, part_index + 1, high); 
    } 
} 


class task_one
{
    vector<point> points_; //points list
    pair<unsigned int, unsigned int> nearest_points_id; //pair of nearest points from file
    bool nearest_func_flag; //check the func was started
    double min_dist; //minimum distance

    void update_answer(const point& left_hand, const point& right_hand); //secondary func for nearest points func

    public: 
    task_one(istream& input)
    {   
        unsigned int temp_id = 0;
        //reading points from a file
        point temp;
        while (input >> temp.x >> temp.y) 
        {
            temp.id = temp_id; 
            points_.push_back(temp);
            ++temp_id;
        }   
        nearest_func_flag = false;
        min_dist = 1E20;
        quickSort(points_, 0, points_.size() - 1);
    }
    void nearest_points()
    {
        nearest_points(0, points_.size() - 1);
    }
    void nearest_points(unsigned int left, unsigned int right);
    void show_points();
    //void max_points_circle(double radius);
    //void max_points_ring(double sub_radius);
    void show_results();
};


void plot(string output_filename);
void random_pfile_generator(double left_end, double right_end, unsigned int points_number, ostream &output);

#endif