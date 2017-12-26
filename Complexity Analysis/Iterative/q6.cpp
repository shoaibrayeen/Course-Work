//What is time complexity of following code :
// time complexity : O(N)

int main() {
        int count = 0;
        for (int i = N; i > 0; i /= 2) {
            for (int j = 0; j < i; j++) {
                count += 1;
            }
        }
}
