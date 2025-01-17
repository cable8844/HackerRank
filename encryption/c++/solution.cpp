#include <bits/stdc++.h>
#include <cmath>
using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string s) {
    double s_sqrt = sqrt(s.length());
    int num_rows = floor(s_sqrt);
    int num_columns = ceil(s_sqrt);
    if (num_rows * num_columns != s.length()) {
        num_rows++;
    }
    
    string result = "";
    
    for (int c = 0; c < num_columns; c++) {
        for (int r = 0; r < num_rows; r++) {
            int index = c + num_columns * r;
            if (index >= s.length()) {
                break;
            }
            
            result += s[index];
        }
        
        result += " ";
        
    }
    
    if (result.back() == ' ') {
        result.pop_back(); // Remove trailing space
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

