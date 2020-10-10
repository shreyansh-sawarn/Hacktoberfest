#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::max;

int64_t MaxPairwiseProductNaive(const std::vector<int64_t>& numbers) {
    int64_t max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
               (int64_t)( numbers[first] * numbers[second]));
        }
    }

    return max_product;
}

int64_t MaxPairwiseProduct(std::vector<int64_t>& numbers) {
    int n = numbers.size();
    sort(numbers.begin(), numbers.end());
    return numbers[n - 1] * numbers[n - 2];
}

void stressTest(int64_t N, int64_t M) {
    while(true) {
        int64_t n = rand() % (N - 1) + 2;
	std::cout << "\n"  << n << "\n";	
	vector<int64_t> A(n);
       	for (int64_t i = 0; i < n; i++) {	
	    A[i] = rand() % (M + 1);
	}	
	for (int64_t i = 0; i < n; i++) {
	    cout << A[i] << " ";
	}
	int64_t result1 = MaxPairwiseProductNaive(A);
	int64_t result2 = MaxPairwiseProduct(A);
	if (result1 == result2) {
	    cout << "\nOK" << "\n";
	} else {
	    cout << "\nWrong Answer: " << result1 << " " << result2 << "\n";
	    return;  
	}
    }
}

int main() {
    // stressTest(1000, 200000);
    int n;
    std::cin >> n;
    std::vector<int64_t> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}