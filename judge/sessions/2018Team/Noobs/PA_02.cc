#include <iostream>

int main() {
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    int cases = 0;
    std::cin >> cases;
    for (int i = 0; i < cases; ++i) {
        int shots = 0;
        std::cin >> shots;
        int k = 0;
        std::cin >> k;
        std::cin.ignore(1000, '\n');
        
        int chars_read = 0;
        int result = 0;
        int count = 1;
        char c, previous;
        previous = '\0';
        while (chars_read++ != shots) {
            std::cin >> c;
            if (c == previous) {
                ++count;
            } else {
                count = 1;
            }
            
            if (count == k) {
                if (c == 'R') --result;
                if (c == 'L') ++result;
                count = 0;
            }

            previous = c;
        }
        std::cout << result << '\n';
    }
}
