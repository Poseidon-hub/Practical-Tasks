#include <iostream>
#include <string>


using namespace std;

class sumirovanie {
public:

	string slochit(string A, string B) {

		int C[1000], f = 0;
		int as = size(A), ab = size(B);

		if (size(A) > size(B)) {
			for (int i = 0; i < ((as - ab)); i++) {
				B = "0" + B;
			}
		}

		else if (size(A) < size(B)) {
			for (int i = 0; i < (ab - as); i++) {
				A = "0" + A;
			}
		}

		for (int i = 0; i < (size(A)); i++) {
			string ai, bi;
			ai = A[size(A) - i - 1];
			bi = B[size(B) - i - 1];

			if (f == 1) {
				C[i] = (((stoi(ai) + stoi(bi) + 1) % 10));
				f = 0;

				if ((stoi(ai) + stoi(bi) + 1) >= 10) {
					f = 1;
				}

			}

			else {
				C[i] = ((stoi(ai) + stoi(bi)) % 10);

				if ((stoi(ai) + stoi(bi)) >= 10) {
					f = 1;
				}

			}
		}

		int g = size(A);

		if (f == 1) {
			C[size(A)] = 1;
			g = g + 1;

		}

		string str;
		for (int i = 0; i < g; i++) {
			str += to_string(C[g - i - 1]);
		}

		return str;

	}
};

int main() {
	string A, B, C, D;

	cin >> A >> B;
	C = A;
	D = "1";

	sumirovanie sumirovanie;

	cout << "A + B: " << sumirovanie.slochit(A, B) << endl;

	while (D != B) {
		C = sumirovanie.slochit(C, A);
		D = sumirovanie.slochit(D, "1");
	}
	

	cout << "A * B: " << C;



	return 0;

}