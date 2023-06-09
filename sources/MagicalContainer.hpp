#include <vector>
#include <iostream>
using namespace std;

namespace ariel {
    class MagicalContainer{
        vector<int> elements;
        vector<size_t> iPrimes; 
        public:
         void setPrimeN(size_t number);
         void addElement(int element);
         size_t size();
         void removeElement(int element);

    
            class AscendingIterator{
                MagicalContainer& container;
                size_t iPosition;

                public:
                    AscendingIterator(AscendingIterator&&container) = default; 
                    AscendingIterator& operator=(AscendingIterator&&container) = delete;
                    
                    AscendingIterator(MagicalContainer&container);
                    AscendingIterator(const AscendingIterator& other);
                    ~AscendingIterator(){}

                   
                   

                    // operators
                    AscendingIterator& operator=(AscendingIterator other);
                    bool operator==( AscendingIterator other);
                    bool operator!=( AscendingIterator other);
                    bool operator<( AscendingIterator other);
                    bool operator>( AscendingIterator other);
                    int operator*()const;
                    AscendingIterator& operator++();


                    //end & begin
                    AscendingIterator begin();
                    AscendingIterator end();

                  //gettets & setters
                  size_t getPosition() const{return this->iPosition;}
                  MagicalContainer& getContianer(){return this->container;}
                    
            };

            class SideCrossIterator{
                MagicalContainer& container;
                size_t iPosition;

                public:
                    SideCrossIterator(SideCrossIterator&&container) = default; 
                    SideCrossIterator& operator=(SideCrossIterator&&container) = delete; 

                    SideCrossIterator(MagicalContainer&container);
                    SideCrossIterator(const SideCrossIterator& other);
                    ~SideCrossIterator(){}

                   

                    // operators
                    SideCrossIterator& operator=(SideCrossIterator other);
                    bool operator==( SideCrossIterator other);
                    bool operator!=( SideCrossIterator other);
                    bool operator<( SideCrossIterator other);
                    bool operator>( SideCrossIterator other);
                    int operator*()const;
                    SideCrossIterator& operator++();


                     //end & begin
                    SideCrossIterator begin();
                    SideCrossIterator end();
                   


                    //gettets & setters
                    size_t getPosition() const{return this->iPosition;}
                    MagicalContainer& getContianer(){return this->container;}
            };

            class PrimeIterator{
                MagicalContainer& container;
                size_t iPosition;
                size_t p_Position;

                public:
                    PrimeIterator(PrimeIterator&&container) = default; 
                    PrimeIterator& operator=(PrimeIterator&&container) = delete; 

                    PrimeIterator(MagicalContainer&container);
                    PrimeIterator(const PrimeIterator& other);
                    ~PrimeIterator(){}

                   
                   
                    // operators
                    PrimeIterator& operator=(PrimeIterator other);
                    bool operator==( PrimeIterator other);
                    bool operator!=( PrimeIterator other);
                    bool operator<( PrimeIterator other);
                    bool operator>( PrimeIterator other);
                    int operator*()const;
                    PrimeIterator& operator++();
                      bool static isPrime(int number){
                        if(number < 2){
                            return false;
                        }

                        for(int i = 2; i <= number/2; i++){
                            if(number%i == 0){
                                return false;
                            }
                        }
                        return true;
                    }


                        //end & begin
                    PrimeIterator begin();
                    PrimeIterator end();
                   


                    //gettets & setters
                    size_t getPosition() const{return this->iPosition;}
                    MagicalContainer& getContianer(){return this->container;}


            };
    };
}