
int which_box(int value) {

	if (value <= 0)
		return -1;
	else if (value >= 1 && value <= 5)
		return 1;
	else if (value >= 6 && value <= 10)
		return 2;
	else 
		return 3;

}
