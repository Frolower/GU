// NOTE: do not modify the contents of this file
#include "gtest/gtest.h"
#include "PA3.h"

// NOTE: the order is expected/solution, actual/received student value
TEST(Test1_Task1, Computations) {
	bool isMultiple, isSumEven, isPrime;
	int num = 77;
	answerIntegerQuestions(num, &isMultiple, &isSumEven, &isPrime);
	EXPECT_EQ(true, isMultiple);
	EXPECT_EQ(true, isSumEven);
	EXPECT_EQ(false, isPrime);
	
	num = 16;
	answerIntegerQuestions(num, &isMultiple, &isSumEven, &isPrime);
	EXPECT_EQ(false, isMultiple);
	EXPECT_EQ(false, isSumEven);
	EXPECT_EQ(false, isPrime);
	
	num = 13;
	answerIntegerQuestions(num, &isMultiple, &isSumEven, &isPrime);
	EXPECT_EQ(true, isMultiple);
	EXPECT_EQ(true, isSumEven);
	EXPECT_EQ(true, isPrime);
	
	num = 7;
	answerIntegerQuestions(num, &isMultiple, &isSumEven, &isPrime);
	EXPECT_EQ(true, isMultiple);
	EXPECT_EQ(false, isSumEven);
	EXPECT_EQ(true, isPrime);
}

TEST(Test2_Task2, FindLotteryTicket) {
  	int arr[] = {13579, 26791,  26792,  33445,  55555, 62483,  77777,  79422,  85647,  93121};
	int size = 10;
  
	int arr2[] = {13579,  11111, 22222, 26791,  26792,  33445,  55555, 62483,  77777,  79422,  85647,  93121};
	int size2 = 12;
	
	bool found = false;

	found = findWinningLotteryTicket(13579, arr, size);
	EXPECT_EQ(true, found);
	found = findWinningLotteryTicket(93121, arr, size);
	EXPECT_EQ(true, found);
	found = findWinningLotteryTicket(11111, arr, size);
	EXPECT_EQ(false, found);
	found = findWinningLotteryTicket(55556, arr, size);
	EXPECT_EQ(false, found);

  	found = findWinningLotteryTicket(13579, arr2, size2);
	EXPECT_EQ(true, found);
	found = findWinningLotteryTicket(93121, arr2, size2);
	EXPECT_EQ(true, found);
	found = findWinningLotteryTicket(11111, arr2, size2);
	EXPECT_EQ(true, found);
	found = findWinningLotteryTicket(55556, arr2, size2);
	EXPECT_EQ(false, found);
}

TEST(Test3_Task3, CreateWordsArray) {
	ifstream inFile("../test/verbs.txt");
	string * verbsArr, verbsSolutionArr[] = {"drove", "jumped", "ran", "skipped", "walked"};
	int size = 5;
	
	verbsArr = createWordsArray(inFile, size);
	EXPECT_TRUE(verbsArr != NULL);
	if (verbsArr != NULL) {
		for (int i = 0; i < size; i++) {
			EXPECT_EQ(verbsSolutionArr[i], verbsArr[i]);
		}
		
		delete [] verbsArr;
	}
	inFile.close();
}

TEST(Test4_Task3, GenerateRandomSentence) {
	string sentence;
	string articles[] = {"a"};
	string nouns[] = {"car"};
	string verbs[] = {"drove"};
	string preps[] = {"from"};
	
	generateSentence(&sentence, articles, 1, nouns, 1, verbs, 1, preps, 1);
	EXPECT_EQ("A car drove from a car!", sentence);
}

