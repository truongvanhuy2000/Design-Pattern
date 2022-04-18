#include <iostream>
#include <string>
using namespace std;
class Singleton2
{
    private:
        int x;
        int y;
        int z;
        static Singleton2 *ptr;
        Singleton2 (int x, int y, int z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
    public:
        int chuVi ()
        {
            return (x + y + z);
        }
        int dienTich ()
        {
            return (x * y * z);
        }
        static Singleton2 *getInstance(int x, int y, int z)
        {
            if(!ptr)
            {
                ptr = new Singleton2(x, y, z);
            }
            return ptr;
        }
};
Singleton2 *Singleton2 :: ptr = nullptr;
int main()
{
    Singleton2 *sing1 = sing1 -> getInstance(1, 2, 3);
    cout<< sing1 -> chuVi() << endl;
    sing1 = sing1 -> getInstance(2, 3, 5);
    cout<< sing1 -> chuVi() << endl;  
}