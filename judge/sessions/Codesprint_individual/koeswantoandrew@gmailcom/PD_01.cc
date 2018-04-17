#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <stdlib.h>
#include <cassert>
#include <algorithm>
using namespace std;

//codesprint A //remember to cout << newline
struct Instruction {
	Instruction(int begin, int end, char value) {
		m_begin = begin;
		m_end = end;
		m_value = value;
	}

	int m_begin;
	int m_end;
	char m_value;
};

int main() {
	int x;
	cin >> x;
	vector<Instruction> instructions;
	instructions.push_back(Instruction(0, 1000000, 'a'));

	for (int i = 0; i < x; i++) {
		int begin, end;
		char value;
		cin >> begin >> end;
		cin >> value;
		instructions.push_back(Instruction(begin, end, value));
	}

	for (int i = 0; i < instructions.size(); i++) {
		int begin = instructions[i].m_begin;
		int end = instructions[i].m_end;

		for (int j = 0; j < i; j++) {
			if (instructions[j].m_begin > begin && instructions[j].m_begin < end) {
				instructions[j].m_begin = end+1;
			}
			if (instructions[j].m_end < end && instructions[j].m_end > begin) {
				instructions[j].m_end = begin-1;
			}
			if (instructions[j].m_begin > instructions[j].m_end) {
				instructions.erase(instructions.begin() + j);
				i--;
				j--;
			}
			if (instructions[j].m_begin < begin && instructions[j].m_end > end) {
				int temp = instructions[j].m_end;
				instructions[j].m_end = begin-1;
				instructions.insert(instructions.begin(), Instruction(end+1, temp, instructions[j].m_value));
				i++;
				j++;
			}
		}
	}

	int request[4];
	for (int i = 0; i < 4; i++) {
		cin >> request[i];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < instructions.size(); j++) {
			if (instructions[j].m_begin <= request[i] && instructions[j].m_end >= request[i]) {
				cout << instructions[j].m_value << ' ';
			}
		}
	}
}