

#include <iostream>
#include <cmath>
#include <vector>


class Drawable
{
	public:
		virtual bool at_point(int x, int y)
		{
			std::cout << "this will be inheritied" << std::endl;
			return false;
		}
};

class Line: public Drawable
{
	private:
		double slope, y_intercept;

	public:
		Line(double temp_slope, double temp_y_intercept)
		{
			this->slope = temp_slope;
			this->y_intercept = temp_y_intercept;
		}
		bool at_point(int x, int y)
		{
			if (y == round((this->slope * x)) + round(this->y_intercept))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		~Line(){}

};

class Point: public Drawable
{
	private:
		int x, y;
	public:
		Point(int t_x, int t_y)
		{
			this->x = t_x;
			this->y = t_y;
		}
		
		bool at_point(int x, int y)
		{
			if( y == this->y && x == this->x)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		~Point(){}
};

bool drawing(int height, int width, Drawable **drawme)
{
	// prints the boarder
	// print top boarder
	for(int i{1}; i <= (width + 2); i++)
	{
		std::cout << "X";
	}
	std::cout << std::endl;
	
	// start the rest of the boarder
	for(int y{height}; y > 0; y--)
	{
		std::cout << "X";
		// print space inbetween
		for(int x{1}; x <= width; x++)
		{

			if (drawme[0]->at_point(x,y))
			{
				std::cout << '0';
			}
			else if (drawme[1]->at_point(x,y))
			{
				std::cout << '0';
			}
			else if (drawme[2]->at_point(x,y))
			{
				std::cout << '0';
			}
			else
			{
				std::cout << ' ';
			}

		}
		std::cout << "X" << std::endl;
	}
	// print bottom boarder
	for(int i{1}; i <= (width + 2); i++)
	{
		std::cout << "X";
	}
	// send the return
	std::cout << std::endl;
	return 1;
}


int main()
{
	int size = 3;
	Drawable **thing = new Drawable*[size];
	thing[0] = new Line(3,0);
	thing[1] = new Point(10, 10);
	thing[2] = new Line(0, 4);

	drawing(20, 30, thing);

	for(int i{}; i < size; i++)
	{
		delete thing[i];
	}
	delete [] thing;
}
