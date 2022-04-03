class Solution {
public:
   int romanToInt(std::string s) 
   {
      int prev_num = 0;
      int sum = 0;
      for (auto it = s.rbegin(); it != s.rend(); it++)
      {
         const char roman_num = *it;
         const int num = decode_v2(roman_num);

         sum += prev_num <= num ? num : -num;
         prev_num = num;
      }

      return sum;
   }
private:
   int decode_v1(const char roman_num) const
   {
      switch (roman_num)
      {
         case 'I':
            return 1;
         case 'V':
            return 5;
         case 'X':
            return 10;
         case 'L':
            return 50;
         case 'C':
            return 100;
         case 'D':
            return 500;
         case 'M':
            return 1000;
         default:
            return 0;
      }
   }

   int decode_v2(char roman_num)
   {
      return this->romanToIntMap[roman_num];
   }

   std::unordered_map<char, int> romanToIntMap
   {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}
   };
};