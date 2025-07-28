#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers
{
    int PreMulti[10000];
    int n = 0;

public:
    ProductOfNumbers()
    {
        PreMulti[0] = 1;
    }

    void add(int num)
    {
        PreMulti[n] = PreMulti[n - 1] * num;
        n++;
    }

    int getProduct(int k)
    {
        return PreMulti[n] - PreMulti[n - k];
    }
};

int main()
{
    ProductOfNumbers product;

    // 測試用例
    product.add(3);
    product.add(0);
    product.add(2);
    product.add(5);
    product.add(4);

    cout << "getProduct(2) = " << product.getProduct(2) << endl; // 應該輸出 20
    cout << "getProduct(3) = " << product.getProduct(3) << endl; // 應該輸出 40
    cout << "getProduct(4) = " << product.getProduct(4) << endl; // 應該輸出 0，因為 0 影響了乘積
    product.add(8);
    cout << "getProduct(2) = " << product.getProduct(2) << endl; // 應該輸出 32 (4*8)

    return 0;
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */