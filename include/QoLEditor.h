#pragma once
#include <vector>
#include <string>
using namespace std;

class QL
{
public:
    static int CheckInversion(int x);
    static int digit_sum(int n);
    static int sumofvec(vector<int> vecs);
    static bool Xor(bool a, bool b);
    static int reversin(int n);
    static void readDVector(vector<vector<int>> dvector);
    static void readVector(vector<int> dvector);
    static void readVector(vector<string> dvector);
    static vector<int> writeVector(int size1);
    static vector<string> writeSVector(int size1);
    static vector<int> diagonalVector(vector<vector<int>> dvector);
    static vector<int> maxVect(vector<vector<int>> vec);
    static vector<int> minVect(vector<vector<int>> vec);
    static bool have(char n);
    static bool isOdd(int x);
    static bool isOdd(string a);
    static int fact(int a);
    static int randInt(int range1, int range2);
    static vector<int> bubblei(vector<int> a); 
    static vector<int> selecti(vector<int> a);
    static vector<int> inserti(vector<int> a);
};

