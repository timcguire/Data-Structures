#include "Solution.h"
#include <map>
#include <iterator>
#include <numeric>
#include <execution>

void example1()
{
	using namespace std;

	vector<int> v = { 1, 2, 3, 1, 2 };

	cout << count(v.begin(), v.end(), 1) << endl; // 2
	cout << count(v.begin(), v.end(), 3) << endl; // 1
}

void example2()
{
	using namespace std;

	vector<int> v = { 1, 2, 3, 1, 2 };

	auto is_odd = [](auto e) { return e % 2 == 1; };
	cout << count_if(v.begin(), v.end(), is_odd) << endl; // 3
}

namespace my {
	template<class InIt, class T>
	auto count(InIt first, InIt last, const T& val) {
		return std::reduce(first, last, 0, [val](auto i, auto e) { return i + (e == val); });
	}
}

void example3()
{
	std::vector<int> v = { 1, 2, 3, 1, 2 };

	std::cout << my::count(v.begin(), v.end(), 1) << std::endl; // 2
	std::cout << my::count(v.begin(), v.end(), 3) << std::endl; // 1
}

template <typename T>
void print(const T& a)
{
	for (const auto& e : a) cout << e << ' ';
	cout << endl;
}

template <typename T>
void print_map(const T& m) {
	for (const auto& e : m) cout << e.first << "," << e.second << ' ';
	cout << endl;
}

void example_map()
{
	map<int, int> m1 = { { 1, 1 }, { 2, 2 }, { 3, 3 } };
	map<int, int> m2 = { { 1, 2 }, { 2, 4 }, { 3, 3 } };

	map<int, int> m3, m4, m5, m6;

	set_union(m1.begin(), m1.end(), m2.begin(), m2.end(), inserter(m3, m3.end()));
	set_intersection(m1.begin(), m1.end(), m2.begin(), m2.end(), inserter(m4, m4.end()));
	set_difference(m1.begin(), m1.end(), m2.begin(), m2.end(), inserter(m5, m5.end()));
	set_symmetric_difference(m1.begin(), m1.end(), m2.begin(), m2.end(), inserter(m6, m6.end()));

	cout << "set_union:                "; print_map(m3);
	cout << "set_intersection:         "; print_map(m4);
	cout << "set_difference:           "; print_map(m5);
	cout << "set_symmetric_difference: "; print_map(m6);
	cout << endl;
}



int main()
{
	vi v1 = { 0, 1, 2, 3, 4, 5 };
	vi v2 = { 4, 5, 6, 7, 8, 9 };
	vi v3, v4, v5, v6;

	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));
	set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v5));
	set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v6));

	cout << "set_union:                       "; print(v3);
	cout << "set_intersection:                "; print(v4);
	cout << "set_difference:                  "; print(v5);
	cout << "set_symmetric_difference:        "; print(v6);

	example_map();

	//Testing Solution for leet code 109
	vvi test1 = { {0,1}, {1,0} };
	vvi test2 = { {0,1,0}, {0,0,0}, {0, 0, 1} };
	vvi test3 = { {1,1,1,1,1,}, {1,0,0,0,1}, {1,0,1,0,1}, {1,0,0,0,1}, {1,1,1,1,1} };

	int output1 = 0;
	int output2 = 0;
	int output3 = 0;

	Solution J;

	output1 = J.shortestBridge(test1);
	cout << output1;
	output2 = J.shortestBridge(test2);
	cout << output2;
	output3 = J.shortestBridge(test3);
	cout << output3;

	example1();
	example2();
	example3();

	return 0;
}