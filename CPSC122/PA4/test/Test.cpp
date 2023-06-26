// NOTE: do not modify the contents of this file
#include "gtest/gtest.h"
#include "PA4.h"

// NOTE: the order is expected/solution, actual/received student value
TEST(Test1, loadPackages) {
	Package * packages;
	string driverName;
	int numPackages, id, width, length, height;
	ifstream fin;
	double weight;
	
	fin.open("../test/truckloadtest1.txt");
	packages = loadPackages(fin, &driverName, &numPackages);
	EXPECT_EQ("Test 1", driverName);
	EXPECT_EQ(3, numPackages);
	EXPECT_TRUE(packages != NULL);
	if (packages != NULL) {
		for (int i = 0; i < numPackages; i++) {
			id = 1000 * (i + 1);
			EXPECT_EQ(id, packages[i].id);
			weight = 1000 * (i + 1) + (i + 1) / 10.0;
			EXPECT_EQ(weight, packages[i].weight);
			width = 1000 * (i + 1) + (i + 1);
			EXPECT_EQ(width, packages[i].width);
			length = 1000 * (i + 1) + 2 * (i + 1);
			EXPECT_EQ(length, packages[i].length);
			height = 1000 * (i + 1) + 3 * (i + 1);
			EXPECT_EQ(height, packages[i].height);
		}
	}
	
	fin.close();
	
	fin.open("../test/truckloadtest2.txt");
	packages = loadPackages(fin, &driverName, &numPackages);
	EXPECT_EQ("Test Number 2", driverName);
	EXPECT_EQ(1, numPackages);
	EXPECT_TRUE(packages != NULL);
	if (packages != NULL) {
		EXPECT_EQ(1, packages[0].id);
		EXPECT_EQ(2, packages[0].weight);
		EXPECT_EQ(3, packages[0].width);
		EXPECT_EQ(4, packages[0].length);
		EXPECT_EQ(5, packages[0].height);
	}
	
	fin.close();
}

TEST(Test2, computePackageStats) {
	Package packages1[] = {
		{1, 2, 3, 4, 5}
	};
	int numPackages = 1;
	int heaviestId;
	double heaviestWeight;
	double avgWeight;

	computePackageStats(packages1, numPackages, &heaviestId, &heaviestWeight, &avgWeight);
	EXPECT_EQ(1, heaviestId);
	EXPECT_EQ(2, heaviestWeight);
	EXPECT_EQ(2, avgWeight);
	
	Package packages2[] = {
		{7529, 7.8, 10, 4, 5},
		{1234, 2.23, 3, 2, 5},
		{5595, 5.01, 1, 2, 1},
		{9824, 16.254, 7, 6, 2},
		{4927, 1.2, 6, 2, 8}
	};
	numPackages = sizeof(packages2) / sizeof(Package);
	computePackageStats(packages2, numPackages, &heaviestId, &heaviestWeight, &avgWeight);
	EXPECT_EQ(9824, heaviestId);
	EXPECT_DOUBLE_EQ(16.254, heaviestWeight);
	EXPECT_DOUBLE_EQ(6.4988, avgWeight);
}
