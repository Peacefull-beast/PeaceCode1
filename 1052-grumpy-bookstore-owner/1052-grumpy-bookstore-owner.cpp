class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int normal_satisfied = 0;

        for (int i = 0; i < n; i++) 
        {
            if (grumpy[i] == 0) 
                normal_satisfied += customers[i];
        }


        int max_extra_satisfied = 0;
        int current_extra_satisfied = 0;
            int ces = 0;
            int mes = 0;
        for (int i = 0; i < n; i++) 
        {

//             if (grumpy[i] == 1) 
//                 current_extra_satisfied += customers[i];
            

//             if (i >= minutes && grumpy[i - minutes] == 1) 
//                 current_extra_satisfied -= customers[i - minutes];
            

//             max_extra_satisfied = max(max_extra_satisfied, current_extra_satisfied);

            if(grumpy[i] == 1)
            {
                ces = 0;
                int m = minutes;
                for(int j = i; j<n && m>0; j++)
                {
                    if(grumpy[j] == 1)
                        ces += customers[j];
                    m--;
                }
                
                mes = max(mes,ces);
            }
        }

        return normal_satisfied + mes;
    }
};
