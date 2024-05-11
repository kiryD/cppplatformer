#include "QoLEditor.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int QL::CheckInversion(int x)
{
	if (x < 0 || x == 0) {
		return 1;
	}
	else {
		return x;
	}
}
int QL::digit_sum(int n) {
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}
int QL::sumofvec(vector<int> vecs) {
    int cc;
    cc = 0;
    for (int i = 0; i < vecs.size(); i++) {
        cc + vecs.at(i);
    }
    return cc / vecs.size();
}
bool QL::Xor(bool a, bool b) {
    if (a == b) {
        return false;
    }
    if (a != b) {
        return true;
    }
}
int QL::fact(int a) {
    if (a == 0) return 1;
    if (a == 1) return a;
    return a * fact(a - 1);
}
int QL::reversin(int n) {
    if (n <= 0) {
        return n;
    }
    n = (n * 10) + n % 10;
    n /= 10;
    reversin(n);
}
void QL::readDVector(vector<vector<int>> dvector) {
    for (int i = 0; i < dvector.size(); i++) {
        for (int j = 0; j < dvector[i].size(); j++) {
            std::cout << dvector[i][j];
        }
        std::cout << endl;
    }
    std::cout << endl;
}
void QL::readVector(vector<int> dvector) {
    for (int i = 0; i < dvector.size(); i++) {
        std::cout << dvector[i];
    }
    std::cout << endl;
}
void QL::readVector(vector<string> dvector) {
    for (int i = 0; i < dvector.size(); i++) {
        std::cout << dvector[i] << ", ";
    }
    std::cout << endl;
}
vector<int> QL::writeVector(int size1) {
    vector<int> dvector;
    for (int i = 0; i < size1; i++) {
        cin >> dvector[i];
    }
    std::cout << "end" << endl;
    return dvector;
}
vector<string> QL::writeSVector(int size1) {
    vector<string> dvector;
    for (int i = 0; i < size1; i++) {
        cin >> dvector[i];
    }
    std::cout << "end" << endl;
    return dvector;
}
vector<int> QL::diagonalVector(vector<vector<int>> dvector) {
    vector<int> a;
    int i = 0, j = 0;
    a.resize(dvector[0].size() + 1);
    while (i < dvector[i].size() + dvector.size()) {
        a[i] = dvector[i][i];
        i++;
    }
    return a;
}
vector<int> QL::maxVect(vector<vector<int>> vec) {
    vector<int> k{ 0,0,0 };

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (k[0] > vec[i][j]) {
                k[0] = vec[i][j];
                k[1] = i; k[2] = j;
            }
        }
    }
    return k;
}
vector<int> QL::minVect(vector<vector<int>> vec) {
    vector<int> k{ 0,0,0 };

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (k[0] < vec[i][j]) {
                k[0] = vec[i][j];
                k[1] = i; k[2] = j;
            }
        }
    }
    return k;
}
bool QL::have(char n) {
    vector<char> f{ ' ' };
    for (int i = 0; i < f.size(); i++) {
        return n == f[i];
    }
}
bool QL::isOdd(int x) {
    return x % 2 == 1;
}
bool QL::isOdd(string a) {
    return a.length() % 2 == 1;
}
int QL::randInt(int range1, int range2) {
    return rand() % (range2 - range1 + 1) - range1;
}
vector<int> QL::bubblei(vector<int> a) {
    vector<int> vec = a;
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = 0; j < vec.size() - 1 - i; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    return vec;
}
vector<int> QL::selecti(vector<int> a) {
    vector<int> vec = a;
    for (int i = 0; i < vec.size() - 1; i++) {
        auto i_mini = min_element(vec.begin() + i, vec.end());

        if (*i_mini != vec[i]) {
            swap(*i_mini, vec[i]);
        }
        return vec;
    }
}
vector<int> QL::inserti(vector<int> a) {
    int i, key, j;
    vector<int> vec = a;
    for (int i = 0; i < vec.size(); i++) {
        key = vec[i];
        j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
            
        }
        vec[j + 1] = key;
    }
    return vec;
}