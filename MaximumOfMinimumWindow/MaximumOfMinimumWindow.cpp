//https://www.codingninjas.com/codestudio/problems/max-of-min_982935?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// Brute Force - Use 3 loops.
// TC : O(N*3)
// SC : O(1)

//Efficient Approach using NSL and NSR
// This function will return an array.
// Each ith position contains the index of previous smaller elements in the original array.
vector<int> previousSmaller(vector<int> &arr, int n) 
{
    vector<int> prev(n);
    stack<int> s;

    for (int i = 0; i < n; i++) 
    {
        while (!s.empty() && arr[s.top()] >= arr[i]) 
        {
            s.pop();
        }
        
        if (s.empty()) 
        {
            prev[i] = -1;
        } 
        else 
        {
            prev[i] = s.top();
        }

        s.push(i);
    }
    
    return prev;
}

// This function will return an array.
// Each ith position contains the index of next smaller elements in the original array.
vector<int> nextSmaller(vector<int> &arr, int n) 
{
    stack<int> s;
    vector<int> next(n);

    for (int i = n - 1; i >= 0; i--) 
    {
        while (!s.empty() && arr[s.top()] >= arr[i]) 
        {
            s.pop();
        }
        
        if (s.empty()) 
        {
            next[i] = n;
        } 
        else 
        {
            next[i] = s.top();
        }
    
        s.push(i);
    }
    
    return next;
}

vector<int> maxMinWindow(vector<int> &arr, int n) 
{
    // Definition: answer[i] will store the maximum of minimum of every window of size 'i'.
    vector<int> answer(n, INT_MIN);

    // Definition: next[i] will store the index of next smaller element which lie on the right hand side of 'i'.
    vector<int> next = nextSmaller(arr, n);

    // Definition: prev[i] will store the index of previous smaller element which lie on the left hand side of 'i'.
    vector<int> prev = previousSmaller(arr, n);

    for (int i = 0; i < n; i++) 
    {
        // Length of the window in which a[i] is minimum
        int length = next[i] - prev[i] - 1;

        // Update the answer[length-1] ( 0 based indexing )  with a[i]
        answer[length - 1] = max(answer[length - 1], arr[i]);
    }

	// Some entries in answer[] may not be filled yet.
	// We fill them by taking maximum element from suffix starting from 'i'.
    for (int i = n - 2; i >= 0; i--) 
    {
        answer[i] = max(answer[i], answer[i + 1]);
    }

    return answer;
}

// TC : O(N)
// SC : O(N)