#include <iostream>
#include <string>
#define MAX 3
using namespace std;

void hoanvi(string st) {
	if (st.size() == MAX)
		cout << st << '\n';
	else {
		for (int i = 1; i <= MAX; i++) {
			if (st.find(to_string(i), 0) >= st.size()) {
				st = st + to_string(i);
				hoanvi(st);
				st.pop_back();
			}
		}
	}
}

int main() {
	
	hoanvi("");
	return 0;
}