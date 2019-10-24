#pragma once
#include <algorithm>
#include <random>
#include <vector>


struct point {
	double x;
	double y;
};

class Integral {
	static unsigned int getTick(void) {
		_asm rdtsc
	}
public:
	static double min;
	static double max;

	static double Numeric(double(*f)(double), double a, double b, unsigned int countPoints = 1000) {
		double square = 0;
		double step_h = (b - a) / (double)countPoints;
		for (double x = a; x < b; x += step_h) {
			square += std::max(f(x), 0.0);
		}
		return step_h * square;
	}

	static point fMinfMax(double(*f)(double), double a, double b, unsigned int N) {
		double f_val;
		double f_min;
		double f_max;
		double f_step;


		f_min = f(a);
		f_max = f_min;
		f_step = (b - a) / (double)N;

		for (double x = a; x < b; x += f_step) {
			f_val = f(x);
			if (f_val > f_max) { f_max = f_val; }
			if (f_val < f_min) { f_min = f_val; }
		}

		return { f_min, f_max };
	}

	static std::vector<point> uniformRandomOnSquare(point x0y0, point x1y1, unsigned int N) {

		std::vector<point> squarePoints;

		std::mt19937 GRN;
		GRN.seed(getTick());
		std::uniform_real_distribution<> urd_Ox(x0y0.x, x1y1.x);
		std::uniform_real_distribution<> urd_Oy(x0y0.y, x1y1.y);

		for (unsigned int i = 0; i < N; i++) {
			squarePoints.push_back({
				urd_Ox(GRN),
				urd_Oy(GRN)
			});
		}

		return squarePoints;
	}

	static double ratioIn(double(*f)(double), std::vector<point> squarePoints) {
		unsigned int countIn = 0;
		unsigned int length = squarePoints.size();

		for (unsigned int i = 0; i < length; i++) {
			if (squarePoints[i].y <= f(squarePoints[i].x)) {
				countIn += 1;
			}
		}

		return ((double)countIn / (double)length);
	}

	static double MonteCarlo_V1(double(*f)(double), double a, double b, std::vector<point> squarePoints) {
		double f_max;
		f_max = fMinfMax(f, a, b, squarePoints.size()).y;
		return ratioIn(f, squarePoints) * (b - a) * (f_max);
	}
};

