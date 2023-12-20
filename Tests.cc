#include "alg.cpp"
#include <gtest/gtest.h>
#include <iostream>


using namespace std;
using namespace algoritms;

TEST(Tests1, bubble) {
	vector<int>a = { 1,5,7,9,2,6,1,10,3,20,8,9 };
	vector<int>b = { 1,1,2,3,5,6,7,8,9,9,10,20 };
	stats s;
	bubble(a,s);
	EXPECT_EQ(a,b);
}

TEST(Tests2, quick) {
	vector<int>a = { 1,5,7,9,2,6,1,10,3,20,8,9};
	vector<int>b = { 1,1,2,3,5,6,7,8,9,9,10,20};
	stats s;
	quick(a, 0, a.size()-1,s);
	EXPECT_EQ(a, b);
}

TEST(Tests3, pyromid) {
	vector<int>a = { 1,5,7,9,2,6,1,10,3,20,8,9 };
	vector<int>b = { 1,1,2,3,5,6,7,8,9,9,10,20 };
	stats s;
	pyramid_sort(a,s);
	EXPECT_EQ(a, b);
}


TEST(Tests4, quick_test) {
	cycle_random_quick();
	cycle_order_quick();
	cycle_reverse_quick();
	EXPECT_EQ(1, 1);
}

TEST(Tests5, bubble_test) {
	cycle_random_bubble();
	cycle_order_bubble();
	cycle_reverse_bubble();
	EXPECT_EQ(1, 1);
}

TEST(Tests5, pyramid_test) {
	cycle_random_pyramid();
	cycle_order_pyramid();
	cycle_reverse_pyramid();
	EXPECT_EQ(1, 1);
}



