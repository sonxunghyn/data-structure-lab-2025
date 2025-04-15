#define _CRT_SECURE_NO_WARNINGS
#include "sparsepoly.hpp"

void SparsePoly::read() {
    printf("항의 개수 입력: ");
    scanf("%d", &numTerms);

    for (int i = 0; i < numTerms; ++i) {
        float coef;
        int exp;
        printf("%d번째 항의 계수와 차수 입력 (예: 10 5): ", i + 1);
        scanf("%f %d", &coef, &exp);

        if (coef != 0) {
            coefficients.push_back(coef);
            exponents.push_back(exp);
        }
    }
}

void SparsePoly::display(const char* str) {
    printf("%s", str);
    for (size_t i = 0; i < coefficients.size(); ++i) {
        printf("%.1fx^%d", coefficients[i], exponents[i]);
        if (i != coefficients.size() - 1) printf(" + ");
    }
    printf("\n");
}

void SparsePoly::add(SparsePoly a, SparsePoly b) {
    int i = 0, j = 0;

    while (i < a.coefficients.size() && j < b.coefficients.size()) {
        if (a.exponents[i] == b.exponents[j]) {
            float sum = a.coefficients[i] + b.coefficients[j];
            if (sum != 0) {
                coefficients.push_back(sum);
                exponents.push_back(a.exponents[i]);
            }
            ++i; ++j;
        }
        else if (a.exponents[i] > b.exponents[j]) {
            coefficients.push_back(a.coefficients[i]);
            exponents.push_back(a.exponents[i]);
            ++i;
        }
        else {
            coefficients.push_back(b.coefficients[j]);
            exponents.push_back(b.exponents[j]);
            ++j;
        }
    }

    while (i < a.coefficients.size()) {
        coefficients.push_back(a.coefficients[i]);
        exponents.push_back(a.exponents[i]);
        ++i;
    }
    while (j < b.coefficients.size()) {
        coefficients.push_back(b.coefficients[j]);
        exponents.push_back(b.exponents[j]);
        ++j;
    }
}

int main() {
	SparsePoly A, B;
	A.read();
	A.display("Poly A: ");

	B.read();
	B.display("Poly B: ");

	SparsePoly C;
	C.add(A, B);
	C.display("Poly C : ");
}