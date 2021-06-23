#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class treenode
{
public:
	string county_name;
	double population_size;
	treenode* lchild, * rchild;
};

class bst
{
public:
	bst(); //store the data file ("county_data.txt) into initial bst
	~bst(); //de-allocates dynamic memory allocate for tree bool empty(); //checks to see if the tree is empty
	bool empty(); //return true if bst is null; otherwise false is returned.
	void insert(const string& item, const double& population); //auxillary function.
	void insert(treenode*& loc_ptr, const string& name, const double& population); //inserts an item into the bst; this function is invoked, in main, by the auxiliary finction described above
	void del_name(string item); //auxilliary function
	void del_name(treenode*& loc_ptr, string item); //function deletes an item from the bst; this function is invoked in main, by the auxiliary function describes above
	treenode* search_tree(treenode* loc_ptr, string item); //returns a pointer to the node in bst with a county name county name that matches item; this function ins invoked, in main by the auxiliary function describes above
	treenode* search_tree(string item);//auxilliary function
	treenode* inorder_succ(treenode* loc_ptr);
	void county_ranges(const string& min_name, const string& max_name);//auxilliary function
	void county_ranges(treenode*& loc_ptr, const string& min_name, const string& max_name);//prints all the county names to the screen that lie between min_name and max_name inclusive
	void print_tree(); //auxilliary function
	void print_tree(treenode* loc_ptr); //prints each count record to the screen sorted by county name
	void sorted_info(); //auxilliary function
	void sorted_info(ostream& out, treenode*& loc_ptr);//prints each county record to a file called count_info.txt sorted by county name.
	void empty_tree();//deallocates all nodes that were allocated to the bst

private:
	treenode* root;

};