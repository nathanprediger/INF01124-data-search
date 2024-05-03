#include "msd.h"

using namespace std;

int main() {
    cout << "Processing sorted...\n";
	sortArq("inputs/frankestein.txt", "frankestein_sorted.txt");
	sortArq("inputs/war_and_peace.txt", "war_and_peace_sorted.txt");
	
    cout << "Processing counted...\n";
	sortCount("frankestein_sorted.txt", "frankestein_counted.txt");
	sortCount("war_and_peace_sorted.txt", "war_and_peace_counted.txt");

    cout << "Processing ranked...\n";
    sortFrq("frankestein_counted.txt", "frankestein_ranked.txt");
    sortFrq("war_and_peace_counted.txt", "war_and_peace_ranked.txt");
	
	return 0;
}
