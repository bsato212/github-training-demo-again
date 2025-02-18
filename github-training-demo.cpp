#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

uint64_t defaultArgument = 5000;

uint64_t calculatePiDigit(uint64_t position) {
    vector<uint64_t> pi((position + 1) * 10 / 3);
    uint64_t carry = 0;
    uint64_t targetDigit = -1;

    for (uint64_t i = 0; i < pi.size(); i++) {
        pi[i] = 2;
    }

    for (uint64_t i = pi.size() - 1; i > 0; i--) {
        uint64_t sum = 0;
        for (uint64_t j = i; j > 0; j--) {
            sum = sum * j + pi[j] * 10;
            pi[j] = sum % (j * 2 - 1);
            sum /= (j * 2 - 1);
        }
        if (position == 1) {
            targetDigit = carry + sum / 10;
            break;
        }
        carry = sum % 10;
        position--;
    }
    return targetDigit;
}

void runTests() {
    // Test known digits of pi
    assert(calculatePiDigit(1) == 1); // First digit after decimal
    assert(calculatePiDigit(2) == 4); // Second digit after decimal
    assert(calculatePiDigit(3) == 1); // Third digit after decimal
    assert(calculatePiDigit(4) == 5); // Fourth digit after decimal
    assert(calculatePiDigit(5) == 9); // Fifth digit after decimal

    // Test default argument
    uint64_t defaultDigit = calculatePiDigit(defaultArgument);
    assert(defaultDigit >= 0 && defaultDigit <= 9);

    // Test invalid position
    assert(calculatePiDigit(0) == -1);

    std::cout << "All tests passed!" << std::endl;
}

int main(int argc, char* argv[]) {
    uint64_t position = defaultArgument;

    if (argc > 1) {
        position = atoll(argv[1]);
    }

    cout << calculatePiDigit(position) << endl;
    return 0;
}
