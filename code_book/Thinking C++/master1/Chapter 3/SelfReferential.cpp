//: C03:SelfReferential.cpp
// ��������� ����� ��������� ���� �� ����

typedef struct SelfReferential {
	int i;
	SelfReferential* sr;	// ������ ��� �� ��������?
} SelfReferential1;

int main() {
	SelfReferential sr1, sr2;
	sr1.sr = &sr2;
	sr2.sr = &sr1;
	sr1.i = 47;
	sr2.i = 1024;
} ///:~