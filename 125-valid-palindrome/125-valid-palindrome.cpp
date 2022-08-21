class Solution {
public:
bool isPalindrome(string s) {
string a;
for(int i=0;i<s.length();i++)
{
if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>='0'&&s[i]<='9'))
{
a.push_back(tolower(s[i]));
}
}
int p,q;
p=0;
q=a.length()-1;
while(p<q)
{
if(a[p]!=a[q])
{
return false;
}
else
{
p++;
q--;
}
}
return true;
}
};