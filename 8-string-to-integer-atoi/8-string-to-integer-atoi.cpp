class Solution 
{
public:
	int myAtoi(std::string s) 
	{
		bool positive = true;
		double long result = 0;
		int i = 0;

		while (s[i] == ' ')
			i++;

		if (s[i] == '-' || s[i] == '+')
		{
			positive = s[i] == '-' ? false : true;
			i++;
		}

		while (s[i] - '0' >= 0 && s[i] - '0' <= 9)
		{
			result += (int)s[i] - '0';
			result *= 10;
			i++;
		}

		result /= 10;

		if (!positive)
			result = -result;
		if (result < std::pow(-2, 31))
			return pow(-2, 31);
		else if (result > std::pow(2, 31) - 1)
			return pow(2, 31) - 1;

		return result;
	}
};