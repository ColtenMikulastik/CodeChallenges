

#include <iostream>
#include <cmath>


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

bool background(int height, int width, Drawable *drawme)
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

			if (drawme->at_point(x,y))
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
	Drawable *thing;
	thing = new Point(3, 3);
	background(20, 30, thing);
	delete [] thing;
}
