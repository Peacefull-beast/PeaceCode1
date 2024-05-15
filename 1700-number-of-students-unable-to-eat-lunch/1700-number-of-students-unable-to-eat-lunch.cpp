class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {

        int squaresanwich = 0;
        int circlesanwich = 0;
        int n = students.size();
        for(int i=0; i<n; i++)
        {
            if(students[i] == 1)
                squaresanwich+=1;
            else   
                circlesanwich+=1;
        }
        
        for(int  i =0 ;i<n; i++)
        {
            if(sandwiches[i] == 0 && circlesanwich == 0)
                return squaresanwich;
            if(sandwiches[i] == 1 && squaresanwich == 0)
                return circlesanwich;
            if(sandwiches[i] == 0)
                circlesanwich--;
            else
                squaresanwich--;
                
        }
        return 0;
        
        
        
    }
};