class ProductOfNumbers {
public:
    vector<int>products = {1};
    int last;
    ProductOfNumbers() 
    {
        last = -1;
    }
    
    void add(int num) 
    {
        if(num == 0)
        {
            last = products.size();
            products.push_back(1);
        }
        else
            products.push_back(num*products.back());
    }
    
    int getProduct(int k) 
    {
        int n = products.size();
        if (n - k <= last) return 0;
        return products.back() / products[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */