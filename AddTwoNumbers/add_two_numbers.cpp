
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
	LinkedList()
	{
	    this->first_node = nullptr;
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
	    
	    // check if there was nothign in the list
	    if ( nextnode == nullptr && thisnode == nullptr )
	    {
		// set to first node if no prior node
		this->first_node = newnode;
	    }
	    else
	    {
		// append node to end of list
		thisnode->set_next_node(newnode);
	    }
	    // newnode already has nullptr set done!
	    std::cout << "added new node..." << std::endl;

	}

	void removenode(int x)
	{
	    // loop through list, and look for x value and remove it...
	    Node* nextnode = this->first_node;
	    
	    if (nextnode == nullptr)
	    {
		// there is nothign to be done:
		return;
	    }

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
	int value_at_node(int node_num)
	{
	    Node *this_node = nullptr;
	    Node *next_node = this->first_node;
	    int i {};
	    
	    while(next_node != nullptr && i < node_num)
	    {
		// walk the node
		this_node = next_node;
		next_node = next_node->get_next_node();
		i++;
	    }
	    // make sure list isn't empty
	    if(this_node != nullptr)
	    {
		return this_node->get_value();
	    }
	    else
	    {
		return 0;
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

void linkedlist_ify(int numbers [3], LinkedList *list)
{
    for( int i {}; i < 3; i++ )
    {
	// add the number as a node
	list->addnode(numbers[i]);
    }
}

void add_these_two(LinkedList *left, LinkedList *right,LinkedList *result)
{
    // start at end of list and work back
    int length_of_lists = 3;
    int now_round{};
    int result_array [3];
    for( int i{length_of_lists}; i >= 1; i-- )
    {
	int next_round {};
	// calculate rounding value
	next_round = (left->value_at_node(i) + right->value_at_node(i) + now_round) / 10;
	result_array[i-1] = (left->value_at_node(i) + right->value_at_node(i) + now_round) % 10;
	now_round = next_round;
    }
    // turn it into a linked list
    linkedlist_ify(result_array, result);
}

int main()
{
    LinkedList *test1 = new LinkedList;
    int numbers1[3] = { 1,2,5 };
    LinkedList *test2 = new LinkedList;
    int numbers2[3] = { 4,5,5 };
    LinkedList *result = new LinkedList;

    linkedlist_ify(numbers1, test1);
    linkedlist_ify(numbers2, test2);
    add_these_two(test1, test2, result);

    test1->printlist();
    test2->printlist();
    result->printlist();

    delete test1;
    delete test2;
    delete result;
    
    return 0;
}
