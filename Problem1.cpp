#include <iostream>
#include <fstream>
using namespace std;
int main() {
	setlocale(LC_ALL, "rus");
	const int n = 400;
	int matrix[n][n], x, y, xS = 0, yS = 0, m = 0, x0 = 0, y0 = 0, x1, y1;
	double r;
	ifstream in("input3.dat");
	if (!in.is_open()) {
		cout << "Файл не открыается";
		return -1;
	}
	for (y = 0;y < n;y++)
		for (x = 0;x < n;x++) {
			in >> matrix[x][y];
			if (matrix[x][y] == 1) {
				if (matrix[x + 1][y] == matrix[x][y] || matrix[x - 1][y] == matrix[x][y] ||
					matrix[x][y + 1] == matrix[x][y] || matrix[x][y - 1] == matrix[x][y] ||
					matrix[x + 1][y + 1] == matrix[x][y] || matrix[x + 1][y - 1] == matrix[x][y] ||
					matrix[x - 1][y + 1] == matrix[x][y] || matrix[x - 1][y - 1] == matrix[x][y]) {
					xS = xS + x;
					yS = yS + y;
					m = m + 1;
					x1 = x;
					y1 = y;
				}
			}
		}
	x0 = xS / m;
	y0 = yS / m;
	if (xS % m > 0)
		x0 = x0 + 1;
	if (yS % m > 0)
		y0 = y0 + 1;
	r = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
	r = ceil(sqrt(r));
	ofstream out("output.dat");
	out << x0 << " " << y0 << " " << r;
	out.close();
	cout << "x0=" << x0 << " y0=" << y0 << " r=" << r << endl;
	return 0;
}