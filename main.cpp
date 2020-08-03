/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

#include <iostream>
#include <string>

struct T
{
    T(int v, const char* s) :  //1
    value(v),
    name(s)
    {
        
    }
    int value;//2
    std::string name;//3
};

struct Comparison                                //4
{
    T* compare(T* a, T* b) //5
    {
         if (a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float f1 { 0 }, f2 { 0 };
    float equalizeAndMultiply(float* newValue)      //12
    {
        if (newValue != nullptr)
        {
            this->f1 = *newValue;
            while( std::abs(this->f2 - this->f1) > 0.001f )
            {
                this->f2 += 0.1f;
            }
            return this->f1 * this->f2;
        }
       return -1;
    }
};

struct S
{
    static float equalizeAndMultiply(U* that, float* newValue)        //10
    {
        if(that != nullptr && newValue != nullptr)
        {
            std::cout << "U's f1 value: " << that->f1 << std::endl;
            that->f1 = *newValue;
            std::cout << "U's f1 updated value: " << that->f1 << std::endl;
            while( std::abs(that->f2 - that->f1) > 0.001f )
            {
            /*
             write something that makes the distance between that->f2 and that->f1 get smaller
             */
                that->f2 += 0.1f;
            }
            std::cout << "U's f2 updated value: " << that->f2 << std::endl;
            return that->f2 * that->f1;
        }
        return -1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(10, "T1!");                                             //6
    T t2(5, "T2!");                                             //6
    
    Comparison f;                                            //7
    auto* smaller = f.compare(&t1, &t2);                              //8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "both values are equal! recieved " <<  t1.value << " and " << t2.value << std::endl; //9
    }

    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << S::equalizeAndMultiply(&u1 , &updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.equalizeAndMultiply(&updatedValue) << std::endl;
}
