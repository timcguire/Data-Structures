#include "bst.h"


using namespace std;

bst::bst() 
{
	string stemp;
	double itemp;
	string prev_name;
	ifstream myfile("county_data.txt");


	//while not at the end of myfile
	while (!myfile.eof())
	{
		//get a line of the file
		getline(myfile, stemp);
			string separate = stemp;
			string name;
			int seplength = separate.length();
			string number;
			

			//loop to parse through the line and determine number or string
			for (int i = 0; i < seplength; i++)
			{
				//if the char withhin the string at location i is a digit
				if (isdigit(separate[i]))
				{
					//pushes the char into a separate string called number
					number.push_back(separate[i]);
				}
				//else if char within the string at location i is a letter or space
				else if ((separate[i] >= 'A' && separate[i] <= 'Z') || (separate[i] >= 'a' && separate[i] <= 'z') || separate[i] == ' ')
				{
					//push the char into a string called name
					name.push_back(separate[i]);
				}
			}

			name = name.erase(name.length() - 1);

			itemp = stod(number);
			//if (empty() == true)
			//{
				insert(name, itemp);
				//prev_name = name;
			//}
			/*
			else
			{
				cout << "came into else statement" << "\n";
				treenode* ptr2 = search_tree(prev_name);
				treenode* ptr = inorder_succ(search_tree(prev_name));
				cout << "already added a name\n" << prev_name << "\n";
				insert(ptr, name, itemp);
				prev_name = name;
			}*/
	}
}


/*************************************************************************************
Name: Empty()
precondition: None
postcondition: returns true if bst is empty and false otherwise

description: checks to see if the bst is empty or not
***************************************************************************************/


bool bst::empty()
{
	return (root == 0);
}

/*************************************************************************************
Name: insert aux
precondition: none
postcondition: BST has been modified with item inserted at proper position to maintain bst property

description: insert auxiliary 
***************************************************************************************/


void bst::insert(const string& item, const double& population)
{
	insert(root, item, population);
}

/*************************************************************************************
Name: insert
precondition: none
postcondition: BST has been modified with item inserted at proper position to maintain bst property

description: inserts a treenode into the bst recursively
***************************************************************************************/


void bst::insert(treenode*& loc_ptr, const string& name, const double& population)
{
	if (loc_ptr == 0)
	{
		loc_ptr = new treenode;
		loc_ptr->lchild = loc_ptr->rchild = 0;
		loc_ptr->county_name = name;
		loc_ptr->population_size = population;
	}
	else if (loc_ptr->county_name > name)
		insert(loc_ptr->lchild, name, population);
	else if (loc_ptr->county_name < name)
		insert(loc_ptr->rchild, name, population);
	else
		cout << "the county is already in the tree\n";
}

/*************************************************************************************
Name: search tree aux
precondition: none
postcondition: returns the treenode at root

description: auxilliary search tree function for finding root treenode
***************************************************************************************/


treenode* bst::search_tree(string item)
{
	return search_tree(root, item);
}

/*************************************************************************************
Name: Search_tree
precondition: none
postcondition: returns the treenode location if found 

description: search the bst for an item 
***************************************************************************************/


treenode* bst::search_tree(treenode* loc_ptr, string item)
{
	if (loc_ptr != 0)
	{
		if (loc_ptr->county_name == item)
			return loc_ptr;
		else if (loc_ptr->county_name > item)
			return search_tree(loc_ptr->lchild, item);
		else
			return search_tree(loc_ptr->rchild, item);
	}
	else
		return loc_ptr;
}

/*************************************************************************************
Name: del_name aux
precondition: none
postcondition: BST has been modified with item removed (if present);BST property is maintained

description: auxilliary function that calls del_name at the root of bst
***************************************************************************************/


void bst::del_name(string item)
{
	del_name(root, item);
}

/*************************************************************************************
Name: del_name
precondition: none
postcondition: BST has been modified with item removed (if present); BST property is maintained

description: removes the given treenode item if it was found inside the BST
***************************************************************************************/


void bst::del_name(treenode*& loc_ptr, string item)
{

	if (loc_ptr == 0)
		cout << "item not in tree\n";

	else if (loc_ptr->county_name > item)
		del_name(loc_ptr->lchild, item);

	else if (loc_ptr->county_name < item)
		del_name(loc_ptr->rchild, item);

	else
	{
		treenode* ptr;

		if (loc_ptr->lchild == 0)
		{
			ptr = loc_ptr->rchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else if (loc_ptr->rchild == 0)
		{
			ptr = loc_ptr->lchild;
			delete loc_ptr;
			loc_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(loc_ptr);
			loc_ptr->county_name = ptr->county_name;
			del_name(loc_ptr->rchild, ptr->county_name);
		}
	}

}

/*************************************************************************************
Name: inorder_succ
precondition: none
postcondition: BST has been inorder traversed and pointer returned to the inorder successor

description: returns a pointer to the inorder successor, based on county name
***************************************************************************************/


treenode* bst::inorder_succ(treenode* loc_ptr)
{

	treenode* ptr = loc_ptr->rchild;

	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}

/*************************************************************************************
Name: county_ranges aux
precondition: none
postcondition: calls county_ranges at the root treenode

description: auxilliary function of county_ranges that calls at the root treenode
***************************************************************************************/


void bst::county_ranges(const string& min_name, const string& max_name)
{
	county_ranges(root, min_name, max_name);
}

/*************************************************************************************
Name: county_ranges
precondition: none
postcondition: outputs the county names to the screen between min name and max name

description: prints all the county names to the screen that lie between min_name and max_name inclusive
***************************************************************************************/


void bst::county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name)
{
	
	if (loc_ptr != 0)
	{
		
		if (loc_ptr->county_name < min_name)
		{
			return;
		}
		county_ranges(loc_ptr->lchild,min_name, max_name);
		
		
		if (loc_ptr->county_name > max_name)
		{
			return;
		}
		cout << loc_ptr->county_name << endl;
		county_ranges(loc_ptr->rchild, min_name, max_name);
		
		
	}
}

/*************************************************************************************
Name: print_tree
precondition: none
postcondition: calls print_tree at root treenode

description: auxilliary function of print_tree that calls print_tree at root
***************************************************************************************/


void bst::print_tree()
{
	print_tree(root);
}

/*************************************************************************************
Name: print_tree
precondition: none
postcondition: outputs the county name of each county treenode

description: prints each county record to the screen sorted by county name
***************************************************************************************/


void bst::print_tree(treenode* loc_ptr)
{
	if (loc_ptr != 0)
	{
		print_tree(loc_ptr->lchild);
		cout << loc_ptr->county_name << endl;
		print_tree(loc_ptr->rchild);
	}
}

/*************************************************************************************
Name: sorted_info aux
precondition: none
postcondition: calls sorted_info at root position

description: auxilliary for sorted_info which prints each county record to a file called "county_info.txt" sorted by county name
***************************************************************************************/


void bst::sorted_info()
{
	ofstream myfile("county_info.txt");
	sorted_info(myfile, root);
}

/*************************************************************************************
Name: sorted_info
precondition: none
postcondition: outputs the county records of each county to a file called county_info.txt sorted by county name

description: puts the county records in order to the file county_info.txt by county name
***************************************************************************************/


void bst::sorted_info(ostream& out, treenode*& loc_ptr)
{
	if (loc_ptr != 0)
	{
		sorted_info(out, loc_ptr->rchild);
		out << loc_ptr->county_name << " " << loc_ptr->population_size << endl;
		sorted_info(out, loc_ptr->lchild);
	}

	
}

/*************************************************************************************
Name: deconstructor
precondition: none
postcondition: de-allocated memory assigned to the bst

description: de-allocates dynamic memory allocated for tree bool empty()
***************************************************************************************/


bst::~bst()
{
	while (root != 0)
	{
		del_name(root->county_name);
	}
}


void bst::empty_tree()
{
	this->~bst();
}

/*
int main()
{
	bst B;
	//treenode *root1=0, *root2=0;
	string s;
	char ch;
	string key3;
	string key4;
	string response;
	string r1, r2;
	cout << "enter command, c=count, i=insert item,s=search tree,d=delete item,p=print tree, r = range, e=exit: ";
	cin >> ch;
	cout << endl;

	while (ch != 'e')
	{
		switch (ch)
		{
		case 'i':cout << "enter string: ";
			cin >> s;
			B.insert(s);
			break;

		case 's':cout << "enter word to search for: ";
			cin >> s;
			if (!B.search_tree(s))
				cout << s << "not in tree\n";
			else
				cout << s << " was found in the tree\n";
			break;
		case 'd':cout << "enter word to delete: ";
			cin >> s;
			B.del_name(s);
			break;
		case 'p':cout << "...printing tree...\n";
			B.print_tree();
			break;

		default:break;
		}
		cout << "enter command, i=insert item,s=search tree,d=delete item,p=print tree, e=exit: ";
		cin >> ch;
		cout << endl;
	}

	cout << endl << "no more binary tree.....\n";
	return 0;
}*/

