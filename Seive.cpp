#include <vector>
#include <iostream>
#include <string>


int main(int argc, char **argv) {
	// Find all prime numbers under n
	double n; // <- CHANGE ME!
	std::cout << "What is n? So that I may find the primes under it.\n" << std::endl;
	std::cin >> n;
	// All composites will have factors < x
	double x = std::ceil(std::sqrt(n));

	// Vector holds property of primality for each int
	// Composite: FALSE
	// Prime:     TRUE (default)
	
	std::vector<bool> seive(n,true);
	
	for (int i=2; i<x; i++) {
		// Check to see if integer is composite.
		if (seive.at(i) == true) {
			// Integer is a prime. Find multiples < n
			for (int j=i; j<(n/i); j++) {
				seive.at(j*i) = false;
			}
		}
	}
	// Print integers marked as primes > 2
	for (int k = 2; k<n; k++) {
		if (seive.at(k) == true) {
			std::cout << k << std::endl;
		}
	}
	system("PAUSE");
	return 0;
}
