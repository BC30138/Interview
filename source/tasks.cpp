#include"tasks.h"
#include<fstream>
#include<random>
#include <algorithm>

void random_pfile_generator(double left_end, double right_end, unsigned int points_number, ostream &output)
{
    //making test file
    random_device random_device;
    std::mt19937 generator(random_device());

    for (unsigned int it = 0; it < points_number; ++it)
    {
        uniform_real_distribution<double> distribution(left_end, right_end);
        output << distribution(generator) << "\t" << distribution(generator) << endl;
    }
}

void plot(string outputfilename) 
{
    // plot test file
	ofstream plot("source/plot.dat");
	plot << "set xlabel 'X axis'" << endl;
	plot << "set ylabel 'Y axis'" << endl;
	plot << "plot '" << outputfilename << "' using 1:2 w points lt rgb 'red' pt 7 title '" << outputfilename << "'" << endl;
	plot << "pause - 1" << endl;

	system("gnuplot source/plot.dat");
}

void task_one::update_answer(const point& left_hand, const point& right_hand) //secondary func for nearest points func
    {
        double dist = sqrt(
            (left_hand.x - right_hand.x)*(left_hand.x - right_hand.x) +
            (left_hand.y - right_hand.y)*(left_hand.y - right_hand.y)
         );
        if (dist < min_dist) 
        {
            min_dist = dist;
            nearest_points_id.first = left_hand.id;
            nearest_points_id.second = right_hand.id;
        }
    }

void task_one::show_points()
{
    for (unsigned int it = 0; it < points_.size(); ++it)
        cout << points_[it].x << "\t" << points_[it].y << "\t" << points_[it].id << endl;
}

void task_one::nearest_points(unsigned int left, unsigned int right)
{
	if (right - left <= 3) 
    {
		for (unsigned int i = left; i <= right; ++i)
			for (unsigned int j = i + 1; j <= right ; ++j)
				update_answer (points_[i], points_[j]);
        sort (points_.begin() + left, points_.begin() + right + 1, &comp_y);
        return;
	}
 
	unsigned int middle = (left + right) >> 1;
	double midx = points_[middle].x;
	nearest_points (left, middle), nearest_points (middle + 1, right);
	static vector<point> t;
    t.resize(points_.size());
	merge ( points_.begin() + left, points_.begin() + middle + 1, 
            points_.begin() + middle + 1, points_.begin() + right + 1,
            t.begin(), &comp_y);
	copy (t.begin(), t.begin() + right - left + 1, points_.begin() + left);
 
	int tsz = 0;
	for (unsigned int i = left ; i <= right; ++i)
		if (abs (points_[i].x - midx) < min_dist) {
			for (int j = tsz - 1; j >= 0 && points_[i].y - t[j].y < min_dist; --j)
				update_answer (points_[i], t[j]);
			t[tsz++] = points_[i];
		}
}

void task_one::show_results()
{
    //point first;
    //point second;
    
    auto it_first = find_if(points_.begin(), points_.end(), find_point(nearest_points_id.first));
    auto it_second = find_if(points_.begin(), points_.end(), find_point(nearest_points_id.second));
    cout << it_first->x << "\t" << it_first->y << endl;
    cout << it_second->x << "\t" << it_second->y << endl;
    // cout << points_[nearest_points_id].x << "\t" << points_[nearest_points_id].y << endl;
}