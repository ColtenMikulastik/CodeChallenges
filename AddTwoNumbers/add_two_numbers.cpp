
#include <iostream>

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

class LinkedList
{
    private:
        // the list will just hold a pointer to the first Node
        Node *first_node;
    public:
	LinkedList(int t_x, Node* t_ptr = nullptr)
	{
	    // start list by creating node, and pointing to it
	    this->first_node = new Node(t_x, t_ptr);
	    std::cout << "list created!" << std::endl;
	}
	void printlist()
	{
	    // prints all of the nodes attached to list but more optimised
	    Node* currentNode = this->first_node;
	    std::cout << "printing list:" << std::endl;
	    // loop through list, and print each node
	    while (currentNode != nullptr)
	    {
		// print current node var
		std::cout << currentNode->get_value() << std::endl;
		// go to next node
		currentNode = currentNode->get_next_node();
	    }
	    std::cout << "end of list..." << std::endl;
	}

	void addnode(int t_x)
	{
	    // adds a node to the end of the linked list
	    // create the node that will be added in teh heap
	    Node* newnode = new Node(t_x, nullptr);
	    Node* nextnode = this->first_node;
	    Node* thisnode = nullptr;
	    // loop through the list
	    while (nextnode != nullptr)
	    {
		thisnode = nextnode; 
		nextnode = thisnode->get_next_node();
	    }
	    // list(node(10)-> node(20)-> null)
	    // append node to end of list
	    thisnode->set_next_node(newnode);
	    // newnode already has nullptr set done!
	    std::cout << "added new node..." << std::endl;

	}

	void removenode(int x)
	{
	    // loop through list, and look for x value and remove it...
	    Node* nextnode = this->first_node;
	    
	    if (nextnode->get_value() == x)
	    {
		// then the first node is the value
		this->first_node = nextnode->get_next_node();

		// reallocate memory at the first node
		delete nextnode;

		// set nextnode so no longer pointing to unalloc mem
		nextnode = nullptr;
	    }
	    else
	    {
		// what is the problem, read 
		while (nextnode->get_next_node() != nullptr)
		{
		    // traverse the linked list
		    Node* thisnode = nextnode;
		    nextnode = thisnode->get_next_node();
		    // when the node is found then remove it
		    if (nextnode->get_value() == x)
		    {
			// grab the node after
			Node* rejoin = nextnode->get_next_node();

			// this node set beyond next node
			thisnode->set_next_node(rejoin);

			// after the node is unlinked, then remove the node
			delete nextnode;

			// continue looping
			nextnode = rejoin;

			std::cout << "node deleted :" << x << std::endl;

			// final node deletion exception fix, this is not a loop cond for efficiency
			if (nextnode == nullptr)
			{
			    // is last node, so no need to loop anymore
			    break;
			}
		    }
		}
	    }
	}

	~LinkedList()
	{
	    // starting at the first node, we delete then move to the next adn then delete
	    Node* nextNode = this->first_node;
	    
	    // loop through list
	    while (nextNode != nullptr)
	    {
		// hold this node in one pointer and the next in the other
		Node* thisnode = nextNode;
		nextNode = thisnode->get_next_node();
		// delete one node, while pointer holds on to next node
		delete thisnode;
	    }

	    // make sure that we aren't pointing to heap for no reason
	    this->first_node = nullptr;
	    std::cout << "list deleted!" << std::endl;
	}

};


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
	LinkedList test(10);
	test.addnode(20);
	test.addnode(30);
	test.printlist();
}
