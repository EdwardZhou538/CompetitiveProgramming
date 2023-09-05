#include <iostream>
#include <fstream>
using namespace std;

int main () {
ifstream fin ("milkorder.in");
ofstream fout ("milkorder.out");

int n, m, k;

fin >> n >> m >> k;

bool cow1 = false, cow1hierarchy = false;;

int order[n];

for (int i = 0; i < n; i++)
order[i] = 0;

int hierarchy[m];
bool exists[m];

for (int i = 0; i < m; i++)
exists[i] = false;

for (int i = 0; i < m; i++) {
fin >> hierarchy[i];
if (hierarchy[i] == 1) {
cow1hierarchy = true;
}
}

int spot[k][2];

for (int i = 0; i < k; i++) {
fin >> spot[i][0] >> spot[i][1];
order[spot[i][1]-1] = spot[i][0];
}

for (int i = 0; i < n; i++) {
for (int j = 0; j < m; j++) {
if (hierarchy[j] == order[i]) {
exists[j] = true;
}
}
}

if (!cow1hierarchy) {
int real = m-1;
for (int i = n-1; i >= 0; i--) {
if (!exists[real] && order[i] == 0) {
order[i] = hierarchy[real];
real--;
}
if (exists[real] && order[i] == hierarchy[real])
real--;

}

}

else {

int real = 0;

for (int i = 0; i < n; i++) {
if(!exists[real] && order[i] == 0) {
order[i] = hierarchy[real];
real++;
}
if (exists[real] && order[i] == hierarchy[real])
real++;
}
}

int position;

for (int i = 0; i < n; i++) {
if (order[i] == 0 || order[i] == 1) {
position = i+1;
break;
}
}
fout << position;

return 0;
}
