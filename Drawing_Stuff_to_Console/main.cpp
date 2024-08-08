

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

bool drawing(int height, int width, Drawable **drawme, int size)
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
			bool is_occupied {false};
			// loop through all the elements of list
			for(int i {}; i < size; i++)
			{
				if(drawme[i]->at_point(x,y))
				{
					std::cout << '0';
					is_occupied = true;
					break;
				}
			}
			// if there was not a successful hit in the elements
			// print blank space
			if ( !is_occupied )
			{
				std::cout <<  ' ';
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
	int size = 1;
	std::cout << "how many lines do you want to draw?: ";
	std::cin >> size;

	Drawable **thing = new Drawable *[size];
	for (int i{}; i < size; i++)
	{
		char choice {};
		std::cout << "Line or point? (l/p):";
		std::cin >> choice;
		if ( choice == 'l' )
		{
			double slope {}, y_int{};
			std::cout << "what would you like the slope to be?" << std::endl;
			std::cin >> slope;
			std::cout << "what would you like the y_int to be?" << std::endl;
			std::cin >> y_int;

			thing[i] = new Line(slope, y_int);
		}
		else if ( choice == 'p' )
		{
			double x {}, y {};
			std::cout << "what would like your x value to be?" << std::endl;
			std::cin >> x;
			std::cout << "what would like your y value to be?" << std::endl;
			std::cin >> y;
			
			thing[i] = new Point(x,y);
		}
	}

	drawing(20, 30, thing, size);

	for(int i{}; i < size; i++)
	{
		delete thing[i];
	}
	delete [] thing;
}
