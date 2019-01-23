#include <iostream>

int main() {
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    int cases = 0;
    std::cin >> cases;
    int shots = 0;
    std::cin >> shots;
    int k = 0;
    std::cin >> k;
    
    int result = 0;
    int count = 1;
    char c, previous;
    previous = '\0';
    while (std::cin >> c) {
        if (c == previous) {
            ++count;
            if (count == k) {
                if (c == 'R') --result;
                if (c == 'L') ++result;
                count = 0;
            }
        } else {
            count = 1;
        }
        previous = c;
    }
    std::cout << result << '\n';
}
