//�Ƚϸ������Ƿ����
int is_float_equal(float a, float b) {
	if (a - b >= -1e-7 && a - b <= 1e-7) {
		return 1;
	}
	else {
		return 0;
	}
}