class Solution {
public:
    int strStr(string haystack, string needle) {
        
	int h_len = haystack.length();
	int n_len = needle.length();

	if(n_len > h_len) return -1;

	for(int i=0;i<=h_len-n_len;i++) {
		if(needle[0] == haystack[i]) {
			for(int j=0;j<n_len;j++) {
				if(needle[j] != haystack[i+j])
					break;
				else if(j == (n_len-1))
					return i;
			}
		}
	}

	return -1;
}
        
    
};