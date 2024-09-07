#include <iostream>
using namespace std;

void Say(string arr[],int size,int num) {

    if(num == 0) return ;

    int store = num % 10;
    num /=10;
    
    Say(arr,size,num);

    cout << "Say : " << arr[store] << endl;

}

int main() {

    string arr [10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

    Say(arr,9,890);
   
}