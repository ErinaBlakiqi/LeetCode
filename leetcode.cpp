#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

struct LeetCode {

    //Arrays
    //Detyra 1 Plus One:
    vector<int> plusOne(vector<int>& digits);

    //Detyra 2 Single Numbers:
    int singleNumber(vector<int>& nums);

    //Detyra 3 Contains Duplicate:
    bool containsDuplicate(vector<int>& nums);

    //Detyra 4 Pascals triangle I:
    vector<vector<int>> generate(int numRows);

    //Detyra 5 Missing number:
    int missingNumber(vector<int>& nums);

    //Detyra 6 Intersection of two arrays:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

    //Detyra 7 Matrix diagonal sum:
    int diagonalSum(vector<vector<int>>& mat);

    //Detyra 8 Two sum:
    vector<int> twoSum(vector<int>& nums, int target);

    //Detyra 9 Move zeroes:
    void moveZeroes(vector<int>& nums);
     
    //String
    //Detyra 1 Length of last word:
    int lengthOfLastWord(string s);

    //Detyra 2 Roman to integer:
    int romanToInt(string s);

    //Detyra 3 Integer to Roman:
    string intToRoman(int num);

    //Detyra 4 First unique character:
    int firstUniqChar(string s);

    //Detyra 5 Shuffle String:
    string restoreString(string s, vector<int>& indices);

    //Detyra 6 Strong password:
    bool strongPasswordCheckerII(string password);

    //Detyra 7 Final value after operations:
    int finalValueAfterOperations(vector<string>& operations);

    //Detyra 8 Reverse String:
    void reverseString(vector<char>& s);

    //Detyra 9 To lower case
    string toLowerCase(string s);
};

int main() {
    LeetCode detyra;
    
    vector<int> v1 = { 1, 2, 3 };
    vector<int> r1 = detyra.plusOne(v1);
    cout << "Plus one: ";
    for (int i = 0; i < r1.size(); i++) {
        cout << r1[i] << " ";
    }
    cout << endl;

    vector<int> v2 = { 1, 2, 1 };
    int r2 = detyra.singleNumber(v2);
    cout << "Single number: " << r2 << endl;
    bool r3 = detyra.containsDuplicate(v2);
    cout << "Duplicates: " << r3 << endl;
    
    int rows = 4;
    vector<vector<int>> r4 = detyra.generate(rows);
    cout << "Pascals's triangle: " << endl;
    for (int i = 0; i < r4.size(); i++) {
        for (int j = 0; j < r4[i].size(); j++) {
            cout << r4[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> v3 = { 0, 1 };
    int r5 = detyra.missingNumber(v3);
    cout << "Missing number: " << r5 << endl;

    vector<int> r6 = detyra.intersection(v1, v2);
    cout << "Intersection: ";
    for (int i = 0; i < r6.size(); i++) {
        cout << r6[i] << " ";
    }
    cout << endl;

    vector<vector<int>> m1 = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int r7 = detyra.diagonalSum(m1);
    cout << "Diagonal sum: " << r7 << endl;

    vector<int> r8 = detyra.twoSum(v1, rows);
    cout << "Two sum: ";
    for (int i = 0; i < r8.size(); i++) {
        cout << r8[i] << " ";
    }
    cout << endl;

    vector<int> v4 = { 0, 1, 0, 5, 2 };
    detyra.moveZeroes(v4);
    cout << "Move zeroes: ";
    for (int i = 0; i < v4.size(); i++) {
        cout << v4[i] << " ";
    }
    cout << endl;

   //string

    string s1 = "Prishtina is A Big City";
    int d9 = detyra.lengthOfLastWord(s1);
    cout << "Length of last word: " << d9 << endl;

    string s2 = "MCVI";
    int d10 = detyra.romanToInt(s2);
    cout << "Roman to int: " << d10 << endl;

    int nr = 5357;
    string d11 = detyra.intToRoman(nr);
    cout << "Int to roman: " << d11 << endl;

    int d12 = detyra.firstUniqChar(s1);
    cout << "First unique character: " << d12 << endl;

    string s3 = "Hello";
    vector<int> vs = { 2, 3, 1, 0, 4 };
    string d13 = detyra.restoreString(s3, vs);
    cout << "Shuffled string: " << d13 << endl;

    string password = "Elsfdjksvb45?";
    bool d14 = detyra.strongPasswordCheckerII(password);
    cout << "Strong password checker: " << d14 << endl;

    vector<string> op = { "++X", "X++", "X++", "--X" };
    int d15 = detyra.finalValueAfterOperations(op);
    cout << "Final value after operations: " << d15 << endl;

    vector<char> s4 = { 'e', 'r', 'i', 'n', 'a' };
    detyra.reverseString(s4);
    cout << "Reverse string: ";
    for (int i = 0; i < s4.size(); i++) {
        cout << s4[i] << " ";
    }
    cout << endl;

    string d16 = detyra.toLowerCase(s1);
    cout << "To lower case: " << d16 << endl;
    
    return 0;
}

//Arrays
//1
vector<int> LeetCode::plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {

        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }

        digits[i] = 0;
    }

    digits.insert(digits.begin(), 1);

    return digits;
}
//2
int LeetCode::singleNumber(vector<int>& nums) {
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }

    int sum2 = 0;

    for (int i = 0; i < nums.size(); i++) {
        bool found = false;
        for (int j = 0; j < nums.size(); j++) {
            if (i != j && nums[i] == nums[j]) {
                found = true;
                break;
            }
        }

        if (found) {
            sum2 += nums[i];
        }
    }

    return sum - sum2;
}
//3
bool LeetCode::containsDuplicate(vector<int>& nums) {
    int temp;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[i]) {
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }

    return false;
}
//4
vector<vector<int>> LeetCode::generate(int numRows) {

    vector<vector<int>> result;

    if (numRows == 0) {
        return result;
    }

    result.push_back({ 1 });

    for (int i = 1; i < numRows; i++) {
        vector<int> row;

        row.push_back(1);

        for (int j = 1; j < i; j++) {
            row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
        }

        row.push_back(1);

        result.push_back(row);
    }

    return result;
}
//5
int LeetCode::missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum1 = n * (n + 1) / 2;
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += nums[i];
    }
    return sum1 - sum2;
}
//6
vector<int> LeetCode::intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;

    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[i] == nums2[j]) {

                bool exists = false;
                for (int k = 0; k < result.size(); k++) {
                    if (result[k] == nums1[i]) {
                        exists = true;
                        break;
                    }
                }
                if (!exists) {
                    result.push_back(nums1[i]);
                }
            }
        }
    }

    return result;
}
//7
int LeetCode::diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {

            if (i == j)
                sum += mat[i][j];

            else if (i == mat.size() - 1 - j)
                sum += mat[i][j];

        }
    }

    return sum;
}
//8
vector<int> LeetCode::twoSum(vector<int>& nums, int target) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                a = i;
                b = j;
            }
        }
    }
    return { a,b };
}
//9

void LeetCode::moveZeroes(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }
    for (int i = j; i < nums.size(); i++) {
        nums[i] = 0;
    }
}
//String
//1
int LeetCode::lengthOfLastWord(string s) {
    int lastWordLength = 0;

    for (int i = s.length() - 1; i >= 0; i--) {

        if (s[i] != ' ') {
            lastWordLength++;
        }
        else if (lastWordLength > 0) {
            return lastWordLength;
        }

    }

    return lastWordLength;
}
//2
int LeetCode::romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {

        int curr;
        switch (s[i]) {
        case 'I': curr = 1; break;
        case 'V': curr = 5; break;
        case 'X': curr = 10; break;
        case 'L': curr = 50; break;
        case 'C': curr = 100; break;
        case 'D': curr = 500; break;
        case 'M': curr = 1000; break;
        }
        if (i == s.length() - 1) {
            result += curr;
        }
        else {
            int next;
            switch (s[i + 1]) {
            case 'I': next = 1; break;
            case 'V': next = 5; break;
            case 'X': next = 10; break;
            case 'L': next = 50; break;
            case 'C': next = 100; break;
            case 'D': next = 500; break;
            case 'M': next = 1000; break;
            }
            if (next > curr) {
                result -= curr;
            }
            else {
                result += curr;
            }
        }
    }
    return result;
}
//3
string LeetCode::intToRoman(int num) {

    string result = "";

    string roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    int integers[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    for (int i = 0; i < 13; i++) {
        while (integers[i] <= num) {
            result += roman[i];
            num -= integers[i];
        }
    }
    return result;
}
//4
int LeetCode::firstUniqChar(string s) {
    for (int i = 0; i < s.length(); i++) {
        bool Unique = true;

        for (int j = 0; j < s.length(); j++) {

            if (i == j) {
                continue;
            }

            if (s[i] == s[j]) {
                Unique = false;
                break;
            }
        }
        if (Unique) {
            return i;
        }
    }
    return -1;
}
//5
string LeetCode::restoreString(string s, vector<int>& indices) {
    string result(s.size(), '_');

    for (int i = 0; i < indices.size(); i++) {
        int index = indices[i];
        char c = s[i];


        result[index] = c;
    }
    return result;
}
//6
bool LeetCode::strongPasswordCheckerII(string password) {
    if (password.length() < 8) {
        return false;
    }

    bool hasLower = false;
    bool hasUpper = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    for (int i = 0; i < password.length(); ++i) {
        char c = password[i];
        if (islower(c)) {
            hasLower = true;
        }
        else if (isupper(c)) {
            hasUpper = true;
        }
        else if (isdigit(c)) {
            hasDigit = true;
        }
        else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '+' || c == '-') {
            hasSpecial = true;
        }
        if (hasLower && hasUpper && hasDigit && hasSpecial) {
            break;
        }
    }
    if (!hasLower || !hasUpper || !hasDigit || !hasSpecial) {
        return false;
    }
    int repeatCount = 0;
    for (int i = 0; i < password.length() - 2; ++i) {
        if (password[i] == password[i + 1] || password[i + 1] == password[i + 2]) {
            ++repeatCount;
        }
    }
    if (repeatCount > 0) {
        return false;
    }
    return true;
}
//7
int LeetCode::finalValueAfterOperations(vector<string>& operations) {
    int finalValue = 0;

    for (int i = 0; i < operations.size(); i++) {
        string operation = operations[i];
        if (operation == "++X" || operation == "X++") {
            finalValue++;
        }
        else if (operation == "--X" || operation == "X--") {
            finalValue--;
        }
    }

    return finalValue;
}
//8
void LeetCode::reverseString(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; i++) {
        char temp = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = temp;
    }
}
//9
string LeetCode::toLowerCase(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}
