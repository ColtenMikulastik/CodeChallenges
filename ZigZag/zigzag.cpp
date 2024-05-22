
#include <iostream>
#include <string>


class Solution
{
	private:
		std::string input;
		std::string *zig_stuff;
		int k;
	public:
		Solution(std::string t_input, int t_k)
		{
			this->input = t_input;
			this->k = t_k;
			this->zig_stuff = new std::string[t_k];
			
			// fill zig_stuff string with blank chars
			for(int i{}; i <= (k - 1); i++)	
				for (int j{}; j <= (t_input.length() / 2); j++)
					this->zig_stuff[i].push_back(' ');
		}

		bool zig_n_zag()
		{
			int index_x {}, index_y {};
			bool do_go_up = false;

			for(char character : this->input)
			{
				this->zig_stuff[index_x][index_y] = character;
				if(index_x == 0)
				{
					do_go_up = false;
				}
				if(index_x == (k - 1) || do_go_up)
				{
					index_x--;
					index_y++;
					do_go_up = true;
				}
				else
				{
					index_x++;
				}
			}
			return true;
		}

		void print_zig_string()
		{
			for( int i{}; i <= (this->k-1); i++)
			{
				std::cout << this->zig_stuff[i] << std::endl;
			}

		}

		~Solution()
		{
			delete [] this->zig_stuff;
		}
};


int main()
{
	std::string input = "big ups the whole island, masive its ya boy chet\"ina\" boyaka boyaka errrrrr";
	int k = 5;
	std::cout << "Please give a string to zigzag: ";
	std::cin >> input;
	std::cout << "Please give a number to zig and zag to: ";
	std::cin >> k;
	Solution test(input, k);
	test.zig_n_zag();
	test.print_zig_string();
}
