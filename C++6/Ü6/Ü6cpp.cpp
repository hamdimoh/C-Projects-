#include <iostream>
#include <excpt.h>
#include <exception>
#include <stdexcept>
#include <memory>


using namespace std;


float addFloats(float a, float b);
float subtractFloats(float a, float b);
float multiplyFloats(float a, float b);
float divideFloats(float a, float b);
bool smartPointer(int Val, weak_ptr<int> weakPtr);
bool smartPointer(int Val, shared_ptr<int> sharedPtr);
bool smartPointer(int Val, unique_ptr<int> uniquePtr);
void smartPointerWeak(int Val, weak_ptr<int> weakPtr);

int main()
{
	
	float a, b;
	cout << "Choose one of the conditions: \n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
	char selected;
	cin >> selected;
	
	float(*operation)(float x, float y) = nullptr;
	cout << " Value for a & b: ";
	cin >> a;
	cin >> b;
	switch (selected)
	{
	case '1':
		operation = addFloats;
		cout << "a+b= ";
		break;
	case '2':
		operation = subtractFloats;
		cout << "a-b= ";
		break;
	case '3':
		operation = multiplyFloats;
		cout << "a*b= ";
		break;
	case '4':
		operation = divideFloats;
		cout << "a/b= ";
		break;
	default:
		cout << "unvalid entry!\n";
		break;
	}
	if (operation != nullptr) {
		cout << operation(a, b) << endl;
	}

	
	weak_ptr<int> weakPtr;
	int Val = 0;
	bool result = smartPointer(Val, weakPtr);
	cout << "smartPointer() with weak_ptr returned: " << (result ? "true" : "false") << endl;

	
	shared_ptr<int> sharedPtr = make_shared<int>(56);
	Val = 0;
	result = smartPointer(Val, sharedPtr);
	cout << "smartPointer() with shared_ptr returned: " << (result ? "true" : "false") << endl;

	
	unique_ptr<int> uniquePtr = make_unique<int>(77);
	Val = 0;
	result = smartPointer(Val, move(uniquePtr));
	cout << "smartPointer() with unique_ptr returned: " << (result ? "true" : "false") << endl;

	
	weakPtr = sharedPtr;
	try {
		smartPointerWeak(Val, weakPtr);
	}
	catch (const string& errorMessage) {
		cout << "smartPointerWeak() threw an exception: " << errorMessage << endl;
	}

	return 0;
}





float addFloats(float a, float b) {
	return a + b;
}

float subtractFloats(float a, float b) {
	return a - b;
}

float multiplyFloats(float a, float b) {
	return a * b;
}

float divideFloats(float a, float b) {
	return a / b;
}


bool smartPointer(int Val, weak_ptr<int> weakPt) {
	try {
		cout << "The function with a weak pointer is called!\n";
		if (!weakPt.lock()) {
			cout << "The weak pointer that is used is unvalid\n";
			return false;
		}
		else {
			try {
				Val = weakPt.lock().use_count();
				cout << "weak pointer count: " << Val << endl;
				cout << "weak_ptr: " << *weakPt.lock() << endl;
			}
			catch (const exception e) {
				cout << "Exception: " << e.what() << endl;
				return false;
			}
		}
	}
	catch (const exception e) {
		cout << "Exception: " << e.what() << endl;
		return false;
	}
	return true;
}


bool smartPointer(int Val, shared_ptr<int> sharedPt) {
	try {
		cout << "The function with a shared pointer is called!\n";
		if (!sharedPt) {
			cout << "The shared pointer that is used is unvalid\n";
			return false;
		}
		else {
			Val = sharedPt.use_count();
			cout << "shared pointer count: " << Val << endl;
			cout << "shared_ptr: " << *sharedPt << endl;
		}
	}
	catch (const exception e) {
		cout << "Exception: " << e.what() << endl;
		return false;
	}
	return true;
}


bool smartPointer(int Val, unique_ptr<int> uniquePt) {
	try {
		cout << "The function with a shared pointer is called!\n";
		if (!uniquePt) {
			cout << "The shared pointer that is used is unvalid\n";
			return false;
		}
		else {
			Val = 1;
			cout << "shared pointer count: " << Val << endl;
			cout << "shared_ptr: " << *uniquePt << endl;
			cout << "shared_ptr: " << uniquePt.get() << endl;
		}
	}
	catch (const exception e) {
		cout << "Exception: " << e.what() << endl;
		return false;
	}
	return true;
}



void smartPointerWeak(int Val, weak_ptr<int> weakPt) {
	cout << "The function with a weak pointer is called!\n";
	if (weakPt.expired()) {
		cout << "The weak pointer that is used is invalid\n";
		throw "The weak pointer that is used is invalid\n";
	}
	else {
		Val = weakPt.lock().use_count();
		cout << "weak pointer count: " << Val << endl;
		cout << "weak_ptr: " << *weakPt.lock() << endl;
	}
}
