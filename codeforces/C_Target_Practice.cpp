#include <bits/stdc++.h>
using namespace std;
const int score[10][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,5,5,4,3,2,1},
	{1,2,3,4,4,4,4,3,2,1},
	{1,2,3,3,3,3,3,3,2,1},
	{1,2,2,2,2,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1}
};
int main()
{
    int t; 
    cin >> t;
    while (t--)
    {
        char a[10][10];
        for (int i = 0; i < 10; i++) 
        {
            string s;
            cin >> s; 
            for (int j = 0; j < 10; j++) // Loop through each column of the grid
            {
                a[i][j] = s[j]; // Store each character in the grid
            }
        }
        // Input for the current test case is now stored in 'a'

        int total_score = 0; // Variable to accumulate the total score for the current test case
        for (int i = 0; i < 10; i++) // Loop through each row of the grid
        {
            for (int j = 0; j < 10; j++) // Loop through each column of the grid
            {
                if (a[i][j] == 'X') // Check if there is an arrow at this position
                {
                    total_score += score[i][j]; // Add the score for this position to the total score
                }
            }
        }
        cout << total_score << endl; // Output the total score for the current test case
    }
    return 0;
}

// Time Complexity (TC): O(n^2) = O(100)
// Space Complexity (SC): O(10*10) = O(100)