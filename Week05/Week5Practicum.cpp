// Week5practicum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Task1
char changeCase(char symbol) {
	if (symbol >= 'A' && symbol <= 'Z') {
		return symbol + ' ';
	}
	else if (symbol >= 'a' && symbol <= 'z') {
		return symbol - ' ';
	}
	else {
		return '$';
	}
}


//Task2
char intFromChar(char symbol) {
	if (symbol >= '0' && symbol <= '9') {
		int num = symbol - '0';
		return num;
	}
	else {
		return -1;
	}
}

char digitToChar(char number) {
	if (number >= '0' && number <= '9') {
		return number;
	}
	else {
		return '#';
	}

}

//Task3
long long pow(int n, int k) {
	long long res = 1;
	for (int i = 1;i <= k;i++) {
		res = res * n;
	}
	return res;
}

//Task4
int getRemainder(int a, int b) {
	int remainder = a - (a / b) * b;
	return remainder;
}


//Task5
int isTriangle(int a, int b, int c) {
	return a > 0 && b > 0 && c > 0 && a + b > c && a + c >= b && b + c >= a;

}

//Task6
int arithmeticProgression(int a, int d, int n) {
	int ntiChlen = a + (n - 1) * d;
	return ntiChlen;
}

double geometricProgression(double a, double q, int n) {
	int qNaNta = 1;
	for (int i = 1;i <= n;i++) {
		qNaNta = qNaNta * q;

	}
	return a * (qNaNta - 1) / (q - 1);

}

//Task7
int reverse(int num) {
	int result = 0;

	while (num != 0) {
		int remainder = num % 10;
		result = result * 10 + remainder;
		num /= 10;
	}
	return result;

}

//Task8
long long concat(int first, int second) {
	int concator = 1;
	int result;
	if (second == 0) {
		concator = 10;//ако е 0 умнож по 10 за да залепи 0
	}
	int temp = second;
	while (temp != 0) {

		concator = concator * 10;
		temp = temp / 10;

	}
	return first * concator + second;
}



//Task9
int countDigits(int num) {
	int digitCounter = 0;
	do {
		num /= 10;
		digitCounter++;
	} while (num != 0);

	return digitCounter;

}

//Task10
long long countPermutations(int n) {
	long long factorial = 1;
	for (int i = 1; i <= n; i++) {
		factorial = factorial * i;
	}
	return factorial;
}
long long countVariations(int n, int k) {
	return countPermutations(n) / countPermutations(n - k);
}
long long countCombinations(int n, int k) {
	return countPermutations(n) / (countPermutations(n - k) * countPermutations(k));
}


//Task11
int isSuffix(int first, int second) {
	int divisor = 1;
	int suffix = second;

	while (suffix != 0) {
		suffix = suffix / 10;
		divisor = divisor * 10;
	}
	return first % divisor == second; //nqma da vurne nishto ako ne e ravno

}

//Task12
int isPrefix(int first, int second) {
	int divisor = 1;
	int prefix = second;
	do {
		prefix /= 10;
		divisor *= 10;
	} while (prefix != 0);

	while (first >= divisor) {
		first = first / 10;
	}
	return first == second;
}

//Task13
bool isInfix(int first, int second) {
	int divisor = 1;
	int infix = second;
	while (infix != 0) {
		infix /= 10;
		divisor *= 10;
	}
	while (first > 0) {
		if (first % divisor == second) {
			return true;
		}
		first /= 10;
	}
	return false;
}


//Task14

void cipher(int n) {
	int specialCount = 0;
	int prevDigit = 1;

	for (int i = 0; i < n; i++) {
		char ch;
		std::cin >> ch;
		//char ch = _getch();

		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
			std::cout << changeCase(ch);
		}
		else if (ch >= '0' && ch <= '9') {
			int currentDigit = ch - '0';
			std::cout << concat(prevDigit, currentDigit);
			prevDigit = currentDigit;
		}
		else if (ch == '@' || ch == '!' || ch == '#') {
			specialCount++;
		}
		else {
			std::cout << ch;
		}
	}
	std::cout << "\nSpecial characters count: " << specialCount;
}


int main()
{

	//task1
	std::cout << "Task 1\n";
	std::cout << "Enter a character: ";
	char ch1;
	std::cin >> ch1;
	ch1 = changeCase(ch1);
	std::cout << ch1;

	//task2
	std::cout << "Task 2 \n";
	std::cout << "Enter a character: ";
	char ch2;
	std::cin >> ch2;
	int n2 = intFromChar(ch2);
	std::cout << n2;
	std::cout << "Enter a character: ";
	char ch3;
	std::cin >> ch3;
	std::cout << digitToChar(ch3);


	std::cout << "Task 3 \n";
	std::cout << "Enter two numbers: ";
	int n3, n4;
	std::cin >> n3 >> n4;
	std::cout << pow(n3, n4);

	//task3
	std::cout << "Task 3 pow\n";
	std::cout << "Enter two numbers: ";
	int n, k;
	std::cin >> n >> k;
	std::cout << "Result: " << pow(n, k) << "\n";


	//task4
	std::cout << "Task 4 (getRemainder)\n";
	std::cout << "Enter two numbers: ";
	int a, b;
	std::cin >> a >> b;
	std::cout << getRemainder(a, b) << "\n";

	// task5
	std::cout << "Task 5 (isTriangle)\n";
	std::cout << "Enter three numbers: ";
	int a5, b5, c5;
	std::cin >> a5 >> b5 >> c5;
	std::cout << "Result: " << (isTriangle(a5, b5, c5) ? "true" : "false") << "\n";



	//task6
	std::cout << "Task 6 progressions\n";
	std::cout << "Enter a, d, and n for arithmetic progression: ";
	int a6, d6, n6;
	std::cin >> a6 >> d6 >> n6;
	int nthTermArithmetic = arithmeticProgression(a6, d6, n6);
	std::cout << nthTermArithmetic << "\n";

	std::cout << "Enter a, q, and n for geometric progression: ";
	int a6g, q6, n6g;
	std::cin >> a6g >> q6 >> n6g;
	int nthTermGeometric = geometricProgression(a6g, q6, n6g);
	std::cout << nthTermGeometric << "\n";



	// task7
	std::cout << "Task 7 (reverse)\n";
	std::cout << "Enter a number: ";
	int num7;
	std::cin >> num7;
	int reversedNum = reverse(num7);
	std::cout << reversedNum << "\n";



	//task8
	std::cout << "Enter two numbers: ";
	int first8, second8;
	std::cin >> first8 >> second8;
	int concatenatedNum = concat(first8, second8);
	std::cout << concatenatedNum << "\n";



	// task9
	std::cout << "Task 9 (countDigits)\n";
	std::cout << "Enter a number: ";
	int num9;
	std::cin >> num9;
	int digitCount = countDigits(num9);
	std::cout << digitCount << "\n";


	// //task10
	std::cout << " Task 10 (countPermutations, countVariations, countCombinations)\n";
	std::cout << "Enter n for permutations: ";
	int n10p;
	std::cin >> n10p;
	int permutations = countPermutations(n10p);
	std::cout << permutations << "\n";

	std::cout << "Enter n and k for variations: ";
	int n10v, k10v;
	std::cin >> n10v >> k10v;
	int variations = countVariations(n10v, k10v);
	std::cout << variations << "\n";

	std::cout << "Enter n and k for combinations: ";
	int n10c, k10c;
	std::cin >> n10c >> k10c;
	int combinations = countCombinations(n10c, k10c);
	std::cout << combinations << "\n";


	//task11
	std::cout << "Task 11 (isSuffix)\n";
	std::cout << "Enter two numbers: ";
	int first11, second11;
	std::cin >> first11 >> second11;
	int suffixResult = isSuffix(first11, second11);
	if (suffixResult == 1) {
		std::cout << "true\n";
	}
	else {
		std::cout << "false\n";
	}

	// task12
	std::cout << "Task 12 (isPrefix)\n";
	std::cout << "Enter two numbers: ";
	int first12, second12;
	std::cin >> first12 >> second12;
	int prefixResult = isPrefix(first12, second12);
	if (prefixResult == 1) {
		std::cout << "true\n";
	}
	else {
		std::cout << "false\n";
	}



	//task13
	std::cout << "Task 13 (isInfix)\n";
	std::cout << "Enter two numbers: ";
	int first13, second13;
	std::cin >> first13 >> second13;
	bool infixResult = isInfix(first13, second13);
	if (infixResult) {
		std::cout << "true\n";
	}
	else {
		std::cout << "false\n";
	}


	//task14
	std::cout << "Task 14 (cipher)\n";
	std::cout << "Enter a number : ";
	int n;
	std::cin >> n;
	cipher(n);
}
