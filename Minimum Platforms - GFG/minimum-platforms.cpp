//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        //   vector<pair<int,int>>platform;
        //   platform.push_back(make_pair(dep[0],1));
        //   bool flag=false;
        //   for(int i=1;i<n;i++)
        //   {
        //       flag=false;
        //       for(int j=0;j<platform.size();j++)
        //       {
        //           if(arr[i]>platform[j].first)
        //           {
        //               platform[j].first=dep[i];
        //               flag=true;
        //               break;
        //           }
        //       }
        //         if(flag!=true)
        //         {
        //                 int x=(platform.size()+1);
        //                 platform.push_back(make_pair(dep[i],x));
        //         }
        //   }
        //   return platform.size();
        int platforms = 1;  // Minimum number of platforms required
        sort(arr,arr+n);
        sort(dep,dep+n);
    int currentPlatforms = 1;
    int i = 1;  // Index for arrivals
    int j = 0;  // Index for departures

    // Similar to merge operation in merge sort
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            currentPlatforms++;
            i++;
            platforms = std::max(platforms, currentPlatforms);
        } else {
            currentPlatforms--;
            j++;
        }
    }

    return platforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends