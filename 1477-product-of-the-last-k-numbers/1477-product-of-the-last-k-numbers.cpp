class ProductOfNumbers {
public:
    vector<int> v;
    // int prod=1;
    // bool flag;
    ProductOfNumbers() {
    
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        //if(flag)
        int prod=1;
        if(v.size() <= k) {
            for(auto a: v) prod*=a;
        }
        else if(v.size() > k) {
            for(int i=v.size()-1; i>= v.size()-k;i--) prod*=v[i];
            //flag=true;
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */