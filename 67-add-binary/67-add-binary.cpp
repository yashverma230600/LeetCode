class Solution {
public:
    string addBinary(string first, string second) {
        int sizeFirst = first.size();
        int sizeSecond = second.size();

        int sizeMax = std::max(sizeFirst, sizeSecond);

        first.resize(sizeMax, '0');
        second.resize(sizeMax, '0');
        
        std::rotate(first.begin(), first.begin() + sizeFirst, first.end());
        std::rotate(second.begin(), second.begin() + sizeSecond, second.end());

        string result;
        result.resize(sizeMax + 1);

        char isNotZero = 0;
        char overflow = 0;
        for (int i = 0; i < sizeMax; i++)
        {
            const auto a = first[sizeMax - i - 1] - '0';
            const auto b = second[sizeMax - i - 1] - '0';
            
            isNotZero |= a | b | overflow;
            result[sizeMax - i] = (a ^ b ^ overflow) + '0';
            overflow = (a + b + overflow > 1);
        }

        result.front() = overflow + '0';
        if (isNotZero)
        {
            const char* str = result.data();
            while (*str != '1')
            {
                ++str;
            }

            return str;
        }
        
        return "0";
    }   
};