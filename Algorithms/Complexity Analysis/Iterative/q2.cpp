//What is the time complexity of the following code :
//Ans :  O(n) time
 
int main() {

        int j = 0;
        for(int i = 0; i < n; ++i) {
            while(j < n && arr[i] < arr[j]) {
                j++;
            }
        }
}
