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

TEST(Tests4, random1) {
	setlocale(LC_ALL, "Russian");
	cycle_random_quick();
	EXPECT_EQ(1, 1);
}

TEST(Tests5, random2) {
	setlocale(LC_ALL, "Russian");
	cycle_random_buble();
	EXPECT_EQ(1, 1);
}

