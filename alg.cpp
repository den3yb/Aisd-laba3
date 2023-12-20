#pragma once
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <stdexcept>

using namespace std;

namespace algoritms {
    struct stats {
        size_t comparison_count = 0;
        size_t copy_count = 0;
    };


    void bubble(vector<int>& list, stats& s) {
        int len = list.size();
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (list[j] > list[j + 1]) {
                    int t = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = t;
                    s.copy_count++;
                }
                s.comparison_count++;
            }
        }
    }

    void quick(vector<int>& list, int left, int right, stats& s) {
        if (left > right) { return; }
        int p = list[(left + right) / 2];
        int i = left;
        int j = right;
        while (i <= j) {
            while (list[i] < p) { i++; s.comparison_count++; }
            while (list[j] > p) { j--; s.comparison_count++; }
            if (i <= j) {
                int t = list[i];
                list[i] = list[j];
                list[j] = t;
                s.copy_count++;
                i++;
                j--;
            }

        }
        quick(list, left, j, s);
        quick(list, i, right, s);
    }

    void pyramid(vector<int>& list, int n, int i, stats& s) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && list[left] > list[largest]) { largest = left; }
        s.comparison_count++;
        if (right < n && list[right] > list[largest]) { largest = right; }
        s.comparison_count++;
        if (largest != i) {
            int t = list[i];
            list[i] = list[largest];
            list[largest] = t;
            s.copy_count++;
            pyramid(list, n, largest, s);
        }
        s.comparison_count++;
    }

    void pyramid_sort(vector<int>& list, stats& s) {
        int n = list.size();
        for (int i = n / 2 - 1; i >= 0; --i)
            pyramid(list, n, i, s);
        for (int i = n - 1; i >= 0; --i) {
            int t = list[i];
            list[i] = list[0];
            list[0] = t;
            s.copy_count++;
            pyramid(list, i, 0, s);
        }
    }

    
    stats one_random_quick(int size, int seed) {
        stats s;
        vector<int> temp;
        mt19937 generator(seed);
        uniform_int_distribution<> distribution(0, 10000);
        for (int i = 0; i < size; i++) { temp.push_back(distribution(generator)); }
        quick(temp, 0, temp.size() - 1, s);
        return s;
    }

    void cycle_random_quick() {
        int lenght[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Proganiy\\Aisd-laba3\\quick_rand.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats temp;
                temp = one_random_quick(lenght[i], j * 10 + i);
                s.comparison_count += temp.comparison_count;
                s.copy_count += temp.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << lenght[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }

    stats one_order_quick(int size) {
        stats s;
        vector<int> temp;
        for (int i = 0; i < size; i++) { temp.push_back(i);}
        quick(temp, 0, temp.size() - 1, s);
        return s;
    }

    void cycle_order_quick() {
        int lenght[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Proganiy\\Aisd-laba3\\quick_order.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats temp;
                temp = one_order_quick(lenght[i]);
                s.comparison_count += temp.comparison_count;
                s.copy_count += temp.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << lenght[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }

    stats one_reverse_quick(int size) {
        stats s;
        vector<int> temp;
        for (int i = size; i > 0; i--) { temp.push_back(i); }
        quick(temp, 0, temp.size() - 1, s);
        return s;
    }

    void cycle_reverse_quick() {
        int lenght[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Proganiy\\Aisd-laba3\\quick_reverse.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats temp;
                temp = one_reverse_quick(lenght[i]);
                s.comparison_count += temp.comparison_count;
                s.copy_count += temp.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << lenght[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }











    stats one_random_bubble(int size, int seed) {
        stats s;
        vector<int> temp;
        mt19937 generator(seed);
        uniform_int_distribution<> distribution(0, 10000);
        for (int i = 0; i < size; i++) { temp.push_back(distribution(generator)); }
        bubble(temp, s);
        return s;
    }

    void cycle_random_bubble() {
        int lenght[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Proganiy\\Aisd-laba3\\bubble_rand.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats temp;
                temp = one_random_bubble(lenght[i], j * 10 + i);
                s.comparison_count += temp.comparison_count;
                s.copy_count += temp.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << lenght[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }

    stats one_order_bubble(int size) {
        stats s;
        vector<int> temp;
        for (int i = 0; i < size; i++) { temp.push_back(i); }
        bubble(temp, s);
        return s;
    }

    void cycle_order_bubble() {
        int lenght[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Proganiy\\Aisd-laba3\\bubble_order.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats temp;
                temp = one_order_bubble(lenght[i]);
                s.comparison_count += temp.comparison_count;
                s.copy_count += temp.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << lenght[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }

    stats one_reverse_bubble(int size) {
        stats s;
        vector<int> temp;
        for (int i = size; i > 0; i--) { temp.push_back(i); }
        bubble(temp, s);
        return s;
    }

    void cycle_reverse_bubble() {
        int lenght[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Proganiy\\Aisd-laba3\\bubble_reverse.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats temp;
                temp = one_reverse_bubble(lenght[i]);
                s.comparison_count += temp.comparison_count;
                s.copy_count += temp.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << lenght[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }







    stats one_random_pyramid(int size, int seed) {
        stats s;
        vector<int> temp;
        mt19937 generator(seed);
        uniform_int_distribution<> distribution(0, 10000);
        for (int i = 0; i < size; i++) { temp.push_back(distribution(generator)); }
        pyramid_sort(temp, s);
        return s;
    }

    void cycle_random_pyramid() {
        int lenght[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Proganiy\\Aisd-laba3\\pyramid_rand.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats temp;
                temp = one_random_pyramid(lenght[i], j * 10 + i);
                s.comparison_count += temp.comparison_count;
                s.copy_count += temp.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << lenght[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }

    stats one_order_pyramid(int size) {
        stats s;
        vector<int> temp;
        for (int i = 0; i < size; i++) { temp.push_back(i); }
        pyramid_sort(temp, s);
        return s;
    }

    void cycle_order_pyramid() {
        int lenght[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Proganiy\\Aisd-laba3\\pyramid_order.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats temp;
                temp = one_order_pyramid(lenght[i]);
                s.comparison_count += temp.comparison_count;
                s.copy_count += temp.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << lenght[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }

    stats one_reverse_pyramid(int size) {
        stats s;
        vector<int> temp;
        for (int i = size; i > 0; i--) { temp.push_back(i); }
        pyramid_sort(temp, s);
        return s;
    }

    void cycle_reverse_pyramid() {
        int lenght[] = { 1000,3000,5000,10000,25000,50000,100000 };
        ofstream fout;
        fout.open("C:\\Proganiy\\Aisd-laba3\\pyramid_reverse.txt");
        for (int i = 0; i < 7; i++) {
            stats s;
            for (int j = 0; j < 100; j++) {
                stats temp;
                temp = one_reverse_pyramid(lenght[i]);
                s.comparison_count += temp.comparison_count;
                s.copy_count += temp.copy_count;
            }
            s.comparison_count /= 100;
            s.copy_count /= 100;
            if (fout.is_open()) { fout << lenght[i] << " " << s.comparison_count << " " << s.copy_count << endl; }
        }
        fout.close();
    }
}