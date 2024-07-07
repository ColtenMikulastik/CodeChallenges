
// luca's stuff

class Node 
{
	private:
		Node *next_node {};
		int value {};
	public:
		Node(int value, Node *next_node=nullptr)
		{
			this->value=value;
			this->next_node=next_node;
		}
		void set_value(int t_value)
		{
			this->value = t_value;
		}

		void set_next_node(Node *t_next_node)
		{
			this->next_node = t_next_node;
		}
		
		int get_value()
		{	
			return this->value;
		}
		Node *get_next_node()
		{
			return this->next_node;
		}

};


#include <iostream>

void print_node_list(Node *node_index)
{
	int node_number {1};
	do
	{
		std::cout << node_number << "(st/nd) node's value is: " << node_index->get_value() << std::endl;
		node_index = node_index->get_next_node();
		node_number++;
	}
	while( node_index != nullptr );
}


int main()
{
	Node first_node(10, nullptr);
	Node second_node(20, &first_node);
	Node third_node(30, &second_node);
	print_node_list(&third_node);
	std::cout << "test" << std::endl;
}
