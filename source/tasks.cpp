#include"tasks.h"
#include"random"

void random_pfile_generator(double left_end, double right_end, unsigned int points_number, ostream &output)
{
    random_device random_device;
    std::mt19937 generator(random_device());

    for (unsigned int it = 0; it < points_number; ++it)
    {
        uniform_real_distribution<double> distribution(left_end, right_end);
        output << distribution(generator) << "\t" << distribution(generator) << endl;
    }
}

void plot(string outputfilename) {
	ofstream plot("source/plot.dat");
	plot << "set xlabel 'X axis'" << endl;
	plot << "set ylabel 'Y axis'" << endl;
	plot << "plot '" << outputfilename << "' using 1:2 w points lt rgb 'red' pt 7 title '" << outputfilename << "'" << endl;
	plot << "pause - 1" << endl;

	system("gnuplot source/plot.dat");
}