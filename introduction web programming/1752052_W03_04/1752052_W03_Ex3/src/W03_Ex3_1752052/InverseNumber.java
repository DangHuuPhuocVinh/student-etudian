package W03_Ex3_1752052;

class InverseNumber {
	int Inverse(int number) {
		int inverse = 0;
    while(number != 0) {
        int digit = number % 10;
        inverse = inverse * 10 + digit;
        number /= 10;
    }
    return inverse;
	}
}
