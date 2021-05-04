// // #include <iostream>
// // using namespace std;
// // int main()
// // {
// //     int t;
// //     cin >> t;
// //     while (t--)
// //     {
// //         int n;
// //         cin >> n;
// //         int arr[n][n] = {0};
// //         if (n & 1)
// //         {
// //             for (int i = 0; i < n; i++)
// //                 for (int j = 0; j < n; j++)
// //                     arr[i][j] = ((i * n) + (j + 1));
// //         }
// //         else
// //         {
// //             for (int i = 0; i < n; i++)
// //                 for (int j = 0; j < n; j++)
// //                     if (i & 1)
// //                         if (j & 1)
// //                             arr[i][j] = ((i * n) + (j));
// //                         else
// //                             arr[i][j] = ((i * n) + (j + 2));
// //                     else
// //                         arr[i][j] = ((i * n) + (j + 1));
// //         }

// //         for (int i = 0; i < n; i++)
// //         {
// //             for (int j = 0; j < n; j++)
// //                 cout<<arr[i][j]<<" ";
// //             cout<<endl;
// //         }
// //     }
// // }

// // #include <iostream>
// // #include<vector>
// // using namespace std;

// // int main() {
// // 	// your code goes here
// // 	int t;
// //     cin>>t;
// //     for(int i=0;i<t;i++)
// //     {
// //         int r=0,c=0;
// //         int n;
// //         cin>>n;
// //         int m=n;
// //         vector<vector<int>>arr(n,vector<int>(n,0));
// //         for(int r=0;r<n;r++)
// //         {
// //             if(r%2==0)
// //             {
// //                 for(c=0;c<n;c++)
// //                 {
// //                     arr[r][c]=r*m+c+1;
// //                 }
// //             }
// //             else
// //             {
// //                 for(c=n-1;c>=0;c--)
// //                 {
// //                     arr[r][c]=(r)*m+(n-c);
// //                 }
// //             }
// //         }
// //         for(int r=0;r<n;r++)
// //         {
// //             for(int c=0;c<n;c++)
// //             {
// //                 cout<<arr[r][c]<<" ";
// //             }
// //             cout<<endl;
// //         }
        
// //     }
// // 	return 0;
// // }

#include <iostream>
#include<vector>
using namespace std;

int main() {
    bool b;
    cout<<b;
// 	// your code goes here
// 	int t;
//     cin>>t;
//     for(int i=0;i<t;i++)
//     {
//         int r=0,c=0;
//         int n;
//         cin>>n;
//         int m=n;
//         vector<vector<int>>arr(n,vector<int>(n,0));
//         for(int r=0;r<n;r++)
//         {
//             if(r%2==0)
//             {
//                 for(c=0;c<n;c++)
//                 {
//                     arr[r][c]=r*m+c+1;
//                     cout<<arr[r][c]<<" ";
//                 }
//                 cout<<endl;
//             }
//             else
//             {
//                 for(c=n-1;c>=0;c--)
//                 {
//                     arr[r][c]=r*m+c+1;
//                     cout<<arr[r][c]<<" ";
//                 }
//                 cout<<endl;
//             }
//         }
//     }
	return 0;
}

