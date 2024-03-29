class Solution {
public:
    
    /*
        we have 3 cases here
        1.our value is 1234
        if last digit is less than 9, we simply add 1 to last digit and return whole number
        return whole digits vector
        size of vector is  not changed
        
        
        2.we have value 1299
        if last digit is 9, we substitute that value with 0 and decrement our index, till we reach
        a value that is not 9, say less than 9, and in that case we simply increment that digit by 1
        and return whole digits vector
        size of vector is  not changed
    
    
        3.we have value 999
        in this case last digit is 9, we replace its value with 0, decrement our index till we reach a value < 9
        we dont get such value and whole vector is traversed, then we simply add 1 in front of our vector
        we simply push 1 in front of our vector and return it
        
        this we get to know if whole loop is traversed and havent returned anything
    */
    
    
    vector<int> plusOne(vector<int>& digits) {
        
        //index will track (move) from last digit to first digit
        int index = digits.size()-1;
        
        //till all elements are checked
        //if all 9's are there in number, loop will run till all elements get its proper value
        while(index >= 0)
        {
            //last digit strictly 9
            if(digits[index] == 9)
            {
                //replace it with 0
                digits[index] = 0;
            }
            else
            {
                //last digit less than 9 (not equals to 9)
                //increment last digit with 1 and return last digit
                digits[index] = digits[index] + 1;
                return digits;
            }
            //this part will be into use when last digit is 9
            //else if less than 9, ans will be returned
            index--;
        }
        //if above loop is executed fully, and no value is thrown , means all digits where 9
        //so all 9's have its updated value after execution of this loop
        //now we need to add 1 at front of our ans, to fulfill correct solution 
        
        
        digits.insert(digits.begin(),1);
        
        
        return digits;
    }
};