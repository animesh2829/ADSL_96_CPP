/// Assignment No.03

#include <iostream>
using namespace std ;

int main()  {
    int n ;
    cout <<"Enter The Numbers Of The Days ";
    cin >> n;

int arr [1000];
cout << "Enter The Stock Prices ";
for (int i=0;i<n;i++) {

 cin >> arr [i];
} 
    int profit =0;
    for (int i=1;i<n;i++) {
        if (arr[i]> arr[i-1]) {
            profit +=arr[i] - arr[i-1];
        }
    }
cout << "Total Profit Is : " << profit << endl;
return 0;
}
