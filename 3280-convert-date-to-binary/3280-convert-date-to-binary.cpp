class Solution {
public:
    string calculate_binary(int num) {
        string binary = "";
        while (num) {
            int digit = num & 1;
            binary += to_string(digit);
            num = num >> 1;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    string convertDateToBinary(string date) {
        int first = stoi(date.substr(0, 4));
        int second = stoi(date.substr(5, 2));
        int third = stoi(date.substr(8, 2));
        return calculate_binary(first) + "-" + calculate_binary(second) + "-" +
               calculate_binary(third);
    }
};