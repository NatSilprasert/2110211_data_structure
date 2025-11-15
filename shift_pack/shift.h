void shift(int k) {
	if (size() <= 1) return;

	int int_mSize = (int) mSize;
	k = ((k % int_mSize) + int_mSize) % int_mSize;

	while (k--) {
		mHeader->data = mHeader->next->data;
		mHeader = mHeader->next;
	}
}
