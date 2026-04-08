// 4-2.cpp

#include <Iostream>
#include <iomanip>

using namespace std;

int main(void) {
	for (int i = 1; i <= 100; i++) {
		cout << setw(3) << i << ": " << setw(6) << i * i << endl;
	}
	return 0;
}
