// NOTE: do not modify the contents of this file
#include "gtest/gtest.h"
#include "PA7.h"

#include "Stack.h"
#include "Calculator.h"

// NOTE: the order is expected/solution, actual/received student value
TEST(Test1, Stack) {
	Stack s;
	EXPECT_EQ(true, s.isEmpty()); 
	EXPECT_EQ("", s.peek()); 
	
	s.push("hello");
	EXPECT_EQ(false, s.isEmpty());
	EXPECT_EQ("hello", s.peek());
	
	s.push("goodbye");
	EXPECT_EQ(false, s.isEmpty());
	EXPECT_EQ("goodbye", s.peek());
	
	string value = s.pop();
	EXPECT_EQ("goodbye", value);
	EXPECT_EQ(false, s.isEmpty());
	EXPECT_EQ("hello", s.peek());
	
	value = s.pop();
	EXPECT_EQ("hello", value);
	EXPECT_EQ(true, s.isEmpty());
	EXPECT_EQ("", s.peek());
	
	int size = 10000; // test 10k
	for (int i = 0; i < size; i++) {
		s.push(to_string(i));
	}
	EXPECT_EQ(false, s.isEmpty());
	EXPECT_EQ(to_string(size - 1), s.peek());
	if (s.peek() == to_string(size - 1)) {
		// to prevent alot of output on failure
		for (int i = size - 1; i >= 0; i--) {
			EXPECT_EQ(to_string(i), s.pop());
		}
	}
	EXPECT_EQ(true, s.isEmpty());
	EXPECT_EQ("", s.peek());
}

TEST(Test2, checkOperatorOnStackPrecedence) {
	EXPECT_EQ(false, checkOperatorOnStackPrecedence("(", "("));
	EXPECT_EQ(false, checkOperatorOnStackPrecedence("(", "^"));
	EXPECT_EQ(false, checkOperatorOnStackPrecedence("(", "*"));
	EXPECT_EQ(false, checkOperatorOnStackPrecedence("(", "/"));
	EXPECT_EQ(false, checkOperatorOnStackPrecedence("(", "%"));
	EXPECT_EQ(false, checkOperatorOnStackPrecedence("(", "+"));
	EXPECT_EQ(false, checkOperatorOnStackPrecedence("(", "-"));
	
	// ")" right paren is never on the stack
	
	EXPECT_EQ(false, checkOperatorOnStackPrecedence("^", "("));
	EXPECT_EQ(true, checkOperatorOnStackPrecedence("^", ")"));
	EXPECT_EQ(false, checkOperatorOnStackPrecedence("^", "^"));
	EXPECT_EQ(true, checkOperatorOnStackPrecedence("^", "*"));
	EXPECT_EQ(true, checkOperatorOnStackPrecedence("^", "/"));
	EXPECT_EQ(true, checkOperatorOnStackPrecedence("^", "%"));
	EXPECT_EQ(true, checkOperatorOnStackPrecedence("^", "+"));
	EXPECT_EQ(true, checkOperatorOnStackPrecedence("^", "-"));
	
	string multOps[] = {"*", "/", "%"};
	for (string op: multOps) {
		EXPECT_EQ(false, checkOperatorOnStackPrecedence(op, "("));
		EXPECT_EQ(true, checkOperatorOnStackPrecedence(op, ")"));
		EXPECT_EQ(false, checkOperatorOnStackPrecedence(op, "^"));
		EXPECT_EQ(true, checkOperatorOnStackPrecedence(op, "*"));
		EXPECT_EQ(true, checkOperatorOnStackPrecedence(op, "/"));
		EXPECT_EQ(true, checkOperatorOnStackPrecedence(op, "%"));
		EXPECT_EQ(true, checkOperatorOnStackPrecedence(op, "+"));
		EXPECT_EQ(true, checkOperatorOnStackPrecedence(op, "-"));
	}
	
	string addOps[] = {"+", "-"};
	for (string op: addOps) {
		EXPECT_EQ(false, checkOperatorOnStackPrecedence(op, "("));
		EXPECT_EQ(true, checkOperatorOnStackPrecedence(op, ")"));
		EXPECT_EQ(false, checkOperatorOnStackPrecedence(op, "^"));
		EXPECT_EQ(false, checkOperatorOnStackPrecedence(op, "*"));
		EXPECT_EQ(false, checkOperatorOnStackPrecedence(op, "/"));
		EXPECT_EQ(false, checkOperatorOnStackPrecedence(op, "%"));
		EXPECT_EQ(true, checkOperatorOnStackPrecedence(op, "+"));
		EXPECT_EQ(true, checkOperatorOnStackPrecedence(op, "-"));
	}
}

TEST(Test3, convertInfixToPostfix) {
	Calculator calc;
	string symbolTable['Z' + 1];
	
	// incomplete symbol table
	symbolTable['A'] = "77";
	symbolTable['B'] = "55";
	symbolTable['C'] = "40";
	symbolTable['D'] = "15";
	symbolTable['E'] = "7";
	symbolTable['F'] = "1";
	symbolTable['G'] = "5";
	symbolTable['H'] = "-10";
	symbolTable['I'] = "-69";
	symbolTable['J'] = "33";
	symbolTable['K'] = "125";
	symbolTable['M'] = "9";
	symbolTable['N'] = "222";
	symbolTable['P'] = "33";
	symbolTable['Q'] = "2";
	symbolTable['R'] = "-1";
	symbolTable['X'] = "2";
	symbolTable['W'] = "20";
	symbolTable['Z'] = "500";
	
	calc.setSymbolTable(symbolTable);
	
	EXPECT_EQ("AB-", calc.convertInfixToPostfix("A-B"));	
	EXPECT_EQ("AB+", calc.convertInfixToPostfix("A+B"));
	EXPECT_EQ("ABC+-", calc.convertInfixToPostfix("A-(B+C)"));
	EXPECT_EQ("RPH-*", calc.convertInfixToPostfix("R*(P-H)"));
	// note removed C^(D-E/G)^X because it overflowed long
	EXPECT_EQ("DCD+G-H-F+-", calc.convertInfixToPostfix("D-(((C+D-G)-H)+F)"));
	EXPECT_EQ("JK-XIG^-F+*Z/", calc.convertInfixToPostfix("(J-K)*(X-I^G+F)/Z"));
	EXPECT_EQ("XZ+H-I-X*WZX+/ZX^/+", calc.convertInfixToPostfix("(((X+Z-H-I)*X)+W/(Z+X)/(Z^X))"));
	// extras beyond original input file
	EXPECT_EQ("QX*", calc.convertInfixToPostfix("Q*X"));
	EXPECT_EQ("XBC*G/+XX*Z/-", calc.convertInfixToPostfix("X+B*C/G-X*X/Z"));
	EXPECT_EQ("XQ+R-XZ-+", calc.convertInfixToPostfix("(X)+Q-R+(X-Z)"));
	EXPECT_EQ("XBC*G/+XZ*-XQ+^R-XZ-+", calc.convertInfixToPostfix("(X+B*C/G-X*Z)^(X+Q)-R+(X-Z)"));
	
	// new almost full symbol table
	symbolTable['A'] = "-8";
	symbolTable['B'] = "14";
	symbolTable['C'] = "10";
	symbolTable['D'] = "5";
	symbolTable['E'] = "-7";
	symbolTable['F'] = "66";
	symbolTable['G'] = "0";
	symbolTable['H'] = "-11";
	symbolTable['I'] = "5";
	symbolTable['J'] = "32";
	symbolTable['K'] = "10";
	symbolTable['L'] = "-98";
	symbolTable['M'] = "6";
	symbolTable['N'] = "9";
	symbolTable['O'] = "778";
	symbolTable['P'] = "65";
	symbolTable['Q'] = "32";
	symbolTable['R'] = "-3";
	symbolTable['S'] = "0";
	symbolTable['T'] = "-7";
	// missing U in symbol table on purpose
	symbolTable['V'] = "-32";
	symbolTable['W'] = "3";
	symbolTable['X'] = "41";
	symbolTable['Y'] = "1";
	symbolTable['Z'] = "-1";
	
	calc.setSymbolTable(symbolTable);
	
	EXPECT_EQ("AC+D*", calc.convertInfixToPostfix("(A+C)*D"));
	EXPECT_EQ("ACD*+", calc.convertInfixToPostfix("A+C*D"));
	EXPECT_EQ("YZ-CW^+WQ*G/-", calc.convertInfixToPostfix("(Y-Z)+(C^W)-W*Q/G"));
	EXPECT_EQ("HN%M%D%H%I%", calc.convertInfixToPostfix("H%N%M%D%H%I"));
	EXPECT_EQ("PS/X/G/W/G/", calc.convertInfixToPostfix("P/S/X/G/W/G"));
	EXPECT_EQ("NT*L*L*L*", calc.convertInfixToPostfix("N*T*L*L*L"));
	EXPECT_EQ("FHM-L-J-C-FB^/+", calc.convertInfixToPostfix("F+((H-M-L-J-C)/(F^B))"));
	EXPECT_EQ("HY^YH^-", calc.convertInfixToPostfix("H^Y-Y^H"));
	EXPECT_EQ("MN^NM^-", calc.convertInfixToPostfix("M^N-N^M"));
	EXPECT_EQ("MN^NM^-", calc.convertInfixToPostfix("(M^N)-(N^M)"));
	EXPECT_EQ("UB-", calc.convertInfixToPostfix("U-B"));
	EXPECT_EQ("AB*CD^/GG^-", calc.convertInfixToPostfix("A*B/C^D-G^G"));
	EXPECT_EQ("A", calc.convertInfixToPostfix("A"));
	EXPECT_EQ("B", calc.convertInfixToPostfix("(B)"));
	EXPECT_EQ("C", calc.convertInfixToPostfix("(((C)))"));
}

TEST(Test4, evaluatePostfix) {
	Calculator calc;
	string symbolTable['Z' + 1];
	
	// incomplete symbol table
	symbolTable['A'] = "77";
	symbolTable['B'] = "55";
	symbolTable['C'] = "40";
	symbolTable['D'] = "15";
	symbolTable['E'] = "7";
	symbolTable['F'] = "1";
	symbolTable['G'] = "5";
	symbolTable['H'] = "-10";
	symbolTable['I'] = "-69";
	symbolTable['J'] = "33";
	symbolTable['K'] = "125";
	symbolTable['M'] = "9";
	symbolTable['N'] = "222";
	symbolTable['P'] = "33";
	symbolTable['Q'] = "2";
	symbolTable['R'] = "-1";
	symbolTable['X'] = "2";
	symbolTable['W'] = "20";
	symbolTable['Z'] = "500";
	
	calc.setSymbolTable(symbolTable);
	EXPECT_EQ("22", calc.evaluatePostfix("AB-"));	
	EXPECT_EQ("132", calc.evaluatePostfix("AB+"));	
	EXPECT_EQ("-18", calc.evaluatePostfix("ABC+-"));	
	EXPECT_EQ("-43", calc.evaluatePostfix("RPH-*"));	
	// note removed C^(D-E/G)^X because it overflowed long
	EXPECT_EQ("-46", calc.evaluatePostfix("DCD+G-H-F+-"));	
	EXPECT_EQ("-287781768", calc.evaluatePostfix("JK-XIG^-F+*Z/"));	
	EXPECT_EQ("1162", calc.evaluatePostfix("XZ+H-I-X*WZX+/ZX^/+"));	
	// extras beyond original input file
	EXPECT_EQ("4", calc.evaluatePostfix("QX*"));	
	EXPECT_EQ("442", calc.evaluatePostfix("XBC*G/+XX*Z/-"));
	EXPECT_EQ("-493", calc.evaluatePostfix("XQ+R-XZ-+"));	
	EXPECT_EQ("96947539999", calc.evaluatePostfix("XBC*G/+XZ*-XQ+^R-XZ-+"));
	
	// new full symbol table
	symbolTable['A'] = "-8";
	symbolTable['B'] = "14";
	symbolTable['C'] = "10";
	symbolTable['D'] = "5";
	symbolTable['E'] = "-7";
	symbolTable['F'] = "66";
	symbolTable['G'] = "0";
	symbolTable['H'] = "-11";
	symbolTable['I'] = "5";
	symbolTable['J'] = "32";
	symbolTable['K'] = "10";
	symbolTable['L'] = "-98";
	symbolTable['M'] = "6";
	symbolTable['N'] = "9";
	symbolTable['O'] = "778";
	symbolTable['P'] = "65";
	symbolTable['Q'] = "32";
	symbolTable['R'] = "-3";
	symbolTable['S'] = "0";
	symbolTable['T'] = "-7";
	symbolTable['U'] = "-32";
	symbolTable['V'] = "-32";
	symbolTable['W'] = "3";
	symbolTable['X'] = "41";
	symbolTable['Y'] = "1";
	symbolTable['Z'] = "-1";
	
	calc.setSymbolTable(symbolTable);
	
	EXPECT_EQ("10", calc.evaluatePostfix("AC+D*"));
	EXPECT_EQ("42", calc.evaluatePostfix("ACD*+"));
	EXPECT_EQ("59295096", calc.evaluatePostfix("NT*L*L*L*"));
	EXPECT_EQ("66", calc.evaluatePostfix("FHM-L-J-C-FB^/+"));
	EXPECT_EQ("9546255", calc.evaluatePostfix("MN^NM^-"));
	EXPECT_EQ("-1", calc.evaluatePostfix("AB*CD^/GG^-"));
	EXPECT_EQ("-8", calc.evaluatePostfix("A"));
	EXPECT_EQ("14", calc.evaluatePostfix("B"));
	EXPECT_EQ("10", calc.evaluatePostfix("C"));
}

// BONUS: this last test is for the BONUS task
// which is error checking for operands
TEST(BONUSTest5, BONUSevaluatePostfix) {
	Calculator calc;
	string symbolTable['Z' + 1];
	
	// new almost full symbol table
	symbolTable['A'] = "-8";
	symbolTable['B'] = "14";
	symbolTable['C'] = "10";
	symbolTable['D'] = "5";
	symbolTable['E'] = "-7";
	symbolTable['F'] = "66";
	symbolTable['G'] = "0";
	symbolTable['H'] = "-11";
	symbolTable['I'] = "5";
	symbolTable['J'] = "32";
	symbolTable['K'] = "10";
	symbolTable['L'] = "-98";
	symbolTable['M'] = "6";
	symbolTable['N'] = "9";
	symbolTable['O'] = "778";
	symbolTable['P'] = "65";
	symbolTable['Q'] = "32";
	symbolTable['R'] = "-3";
	symbolTable['S'] = "0";
	symbolTable['T'] = "-7";
	// missing U in symbol table on purpose
	symbolTable['V'] = "-32";
	symbolTable['W'] = "3";
	symbolTable['X'] = "41";
	symbolTable['Y'] = "1";
	symbolTable['Z'] = "-1";
	
	calc.setSymbolTable(symbolTable);
	
	EXPECT_EQ("ERROR", calc.evaluatePostfix("YZ-CW^+WQ*G/-")); // error cannot divide by zero
	EXPECT_EQ("ERROR", calc.evaluatePostfix("HN%M%D%H%I%")); // error cannot have negative mod
	EXPECT_EQ("ERROR", calc.evaluatePostfix("PS/X/G/W/G/")); // error cannot divide by zero
	EXPECT_EQ("ERROR", calc.evaluatePostfix("HY^YH^-")); // error cannot have negative exponents
	EXPECT_EQ("ERROR", calc.evaluatePostfix("UB-")); // error value does not exist
}