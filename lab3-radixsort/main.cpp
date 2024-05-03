#include "msd.h"

using namespace std;

int main() {
    cout << "Processing sorted...\n";
	sortArq("inputs/frankestein.txt", "outputs/frankestein_sorted.txt");
	sortArq("inputs/war_and_peace.txt", "outputs/war_and_peace_sorted.txt");
	
    cout << "Processing counted...\n";
	sortCount("outputs/frankestein_sorted.txt", "outputs/frankestein_counted.txt");
	sortCount("outputs/war_and_peace_sorted.txt", "outputs/war_and_peace_counted.txt");

    cout << "Processing ranked...\n";
    sortFrq("outputs/frankestein_counted.txt", "outputs/frankestein_ranked.txt");
    sortFrq("outputs/war_and_peace_counted.txt", "outputs/war_and_peace_ranked.txt");
	
	return 0;
}