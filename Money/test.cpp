#include "./Money.h"

int main()
{
	using cur = CURRENCY;
	using std::cout;
	using std::endl;
	using std::boolalpha;

	Money k1(cur::KRW, 500);
	Money k2(cur::KRW, 1500);
	Money k3(cur::KRW, 13234);
	Money k4(k1);
	Money u1(cur::USD, 1.3);
	Money u2(cur::USD, 110);
	Money u3(cur::USD, 1400);

	double c1 = 0.456;
	double c2 = 14.23;
	double c3 = 152;

	cout << "k1 = " << k1 << endl;
	cout << "k2 = " << k2 << endl;
	cout << "k3 = " << k3 << endl;
	cout << "k4 = " << k4 << endl << endl;
	cout << "u1 = " << u1 << endl;
	cout << "u2 = " << u2 << endl;
	cout << "u3 = " << u3 << endl << endl;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;

	// operator==
	{
		cout << boolalpha;
		cout << "\n*** operator== test ***\n";
		cout << "k1 == k2 -> " << (k1 == k2) << endl;
		cout << "k1 == k4 -> " << (k1 == k4) << endl;
		cout << "k1 == u2 -> " << (k1 == u2) << endl;
		cout << "k3 == c3 -> " << (k3 == c3) << endl;
	}
	// operator<=
	{
		cout << boolalpha;
		cout << "\n*** operator<= test ***\n";
		cout << "k1 <= k2 -> " << (k1 <= k2) << endl;
		cout << "k1 <= k4 -> " << (k1 <= k4) << endl;
		cout << "k1 <= u2 -> " << (k1 <= u2) << endl;
		cout << "k3 <= c3 -> " << (k3 <= c3) << endl;
	}
	// operator>=
	{
		cout << boolalpha;
		cout << "\n*** operator>= test ***\n";
		cout << "k1 >= k2 -> " << (k1 >= k2) << endl;
		cout << "k1 >= k4 -> " << (k1 >= k4) << endl;
		cout << "k1 >= u2 -> " << (k1 >= u2) << endl;
		cout << "k3 >= c3 -> " << (k3 >= c3) << endl;
	}
	// operator>
	{
		cout << boolalpha;
		cout << "\n*** operator> test ***\n";
		cout << "k1 > k2 -> " << (k1 > k2) << endl;
		cout << "k1 > k4 -> " << (k1 > k4) << endl;
		cout << "k1 > u2 -> " << (k1 > u2) << endl;
		cout << "k3 > c3 -> " << (k3 > c3) << endl;
	}
	// operator+
	{
		cout << "\n*** operator+ test ***\n";
		cout << "k1 + k2 -> " << k1 + k2 << endl;
		cout << "k1 + c2 -> " << k1 + c2 << endl;
		cout << "u1 + c2 -> " << u1 + c2 << endl; // this will return u1. due to u1 - c2 < 0
		cout << "c2 + u1 -> " << c2 + u1 << endl;
	}
	// operator-
	{
		cout << "\n*** operator- test ***\n";
		cout << "k1 - k2 -> " << k1 - k2 << endl;
		cout << "k1 - c2 -> " << k1 - c2 << endl;
		cout << "u1 - c2 -> " << u1 - c2 << endl; // this will return u1. due to u1 - c2 < 0
		cout << "c2 - u1 -> " << c2 - u1 << endl;
	}
}
