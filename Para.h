#pragma once

struct Para {
	int x, y;
	friend bool operator==(Para par1, Para par2);
	friend bool operator!=(Para par1, Para par2);
};
