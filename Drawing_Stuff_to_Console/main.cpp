

#include <iostream>

class Line
{
	private:
		double slope, y_intercept;

	public:
		Line(double temp_slope, double temp_y_intercept)
		{
			temp_slope = this->slope;
			temp_y_intercept = this->y_intercept;
		}
		bool at_point(int x, int y)
		{
			if (y <= (this->slope * x) + this->y_intercept )
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

bool background(int height, int width, Line drawme)
{
	// prints the boarder
	// print top boarder
	for(int i{1}; i <= (width + 2); i++)
	{
		std::cout << "X";
	}
	std::cout << std::endl;
	
	// start the rest of the boarder
	for(int y{1}; y <= height; y++)
	{
		std::cout << "X";
		// print space inbetween
		for(int x{1}; x <= width; x++)
		{

			if (drawme.at_point(x,y))
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
	Line thing(1,0);
	background(40, 40, thing);

}
