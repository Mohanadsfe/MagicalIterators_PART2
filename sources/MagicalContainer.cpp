#include <iostream>
#include "MagicalContainer.hpp"

using namespace std;
namespace ariel{

   
    //AddElement number to the contianer , but in the Ascending order
    //first insert, if the contianer empty ,then add the element to the first regular.
    //second, if not, then check how's bigger, then add the number in the pos by Ascending order.
    //third (final), if the last index, then add the element regular.
    void MagicalContainer::addElement(int element) {
         if((this)->elements.size() == 0){
            (this)->elements.insert((this)->elements.begin(), element);
            return;
        }
        size_t pos = 0;
        for(; pos < (this)->elements.size(); pos++){
            if((this)->elements[pos] > element){
                (this)->elements.insert((this)->elements.begin() + (int(pos)), element);
                break;
            }
            else if(pos == (this)->elements.size()-1){
                (this)->elements.emplace_back(element);
                break;
            }
        }
         if(PrimeIterator::isPrime(element)){ // if the number prime ,then add th position(index) of them to another vetor for MagicalContainer
            setPrimeN(pos);
        }  
    }

    // RemoveElement
    // if the contianer emepy,then nothing to remove.
    // if not, go over the container and search of the element ,if exsit then remove it(by checking that there no prob with positon) ,else thrwo runtimeerror.
    void MagicalContainer::removeElement(int element){
        if((this->size() == 0)){
            return;
        }
        size_t pos = 0;
        for(; pos < this->elements.size(); pos++){
            if(this->elements[pos] == element){
                break;
            }
        }
        if(pos < elements.size()){
            elements.erase(elements.begin()+int(pos));
        }
        else{
            throw std::runtime_error("Trying to remove element is not exitng in the contianer!!");
        }
    }

    //return the number of the elements in the container.
    size_t MagicalContainer::size(){
            return this->elements.size();
        }
        
     // check if the number is prime
    void MagicalContainer::setPrimeN(size_t number){

         (this)->iPrimes.clear();
        for(size_t i = 0; i < (this)->elements.size(); i++){
            if(PrimeIterator::isPrime((this)->elements[i])){
                (this)->iPrimes.emplace_back(i);
            }
        }
    }

    //////////////////    //////////////////  //////////////////

//AscendingIterator Constructor
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : container(container),iPosition(0){}

//AscendingIterator Copy Constructor
ariel::MagicalContainer::AscendingIterator::AscendingIterator(const ariel::MagicalContainer::AscendingIterator &other)
:container(other.container),iPosition(other.iPosition){}



// operators for AscendingIterator

//Move Assignment Operator
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(AscendingIterator other){
        if(&(this)->container != &other.container){
            throw runtime_error(" different containers");
        }
        (this)->container = other.container;
        (this)->iPosition = other.iPosition;
        return *(this);
    }

// CheckEqual operator
bool ariel::MagicalContainer::AscendingIterator::operator==( ariel::MagicalContainer::AscendingIterator other){         
       bool res = true;
            if(&(this)->container != &other.container){
                res = false;
            }
            if((this)->iPosition != other.iPosition){
                res = false;
            }
            return res;
        }

// CheckNEqual operator
bool ariel::MagicalContainer::AscendingIterator::operator!=( ariel::MagicalContainer::AscendingIterator other){           
         return !(*(this) == other);
        }
// LT operator
bool ariel::MagicalContainer::AscendingIterator::operator<( ariel::MagicalContainer::AscendingIterator other){         
       return (this)->iPosition < other.iPosition;
        }
// GT operator
bool ariel::MagicalContainer::AscendingIterator::operator>( ariel::MagicalContainer::AscendingIterator other){           
         return (this)->iPosition > other.iPosition;
        }

// this operator will return the value in the poss from the contianer.
int ariel::MagicalContainer::AscendingIterator::operator*()const{
            return (this)->container.elements[iPosition];
        }

// one new pos on the container operator
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
            if(iPosition < (this)->end().iPosition){
                ++iPosition;
                return *this;
            }
            else{
                throw std::runtime_error("AscendingIterator , finito got the end of the contianer!!");
            }
    }

      
        /// @brief  begin 
        /// @return the index if the begin contianer
ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::begin(){
            AscendingIterator beginIter(this->container);
            beginIter.iPosition = 0;
            return beginIter;
    }
        /// @brief  end
        /// @return the index of last in the contianer
ariel::MagicalContainer::AscendingIterator ariel::MagicalContainer::AscendingIterator::end(){      
           AscendingIterator endIter(this->container);
            endIter.iPosition = container.size();
            return endIter;
        }


////////////////////////////////////////////////////////// //////////////////////////////// ////////////////////////////////////////////////////////////
 //SideCrossIterator Constructor

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container):container(container),iPosition(0) {}

//SideCrossIterator Copy Constructor
ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const ariel::MagicalContainer::SideCrossIterator &other)
:container(other.container),iPosition(other.iPosition){}


// operators for SideCrossIterator


// this operator will return the value in the poss from the contianer.
int ariel::MagicalContainer::SideCrossIterator::operator*() const{
            return (this)->container.elements[iPosition];
        }

// one new pos on the container operator
ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator++(){   
         if(iPosition < container.size()){
            size_t size = container.size();
            if(iPosition == size/2){
                iPosition = size;
            }
            else if(iPosition < size/2){
                iPosition = size-1-iPosition;
            }
            else{
                iPosition = size-iPosition;
            }
            return *this;
        }
        else{
            throw std::runtime_error("finito got the end of the container (sideCrossIterator)");
        }

    }

 // CheckEqual operator     
bool ariel::MagicalContainer::SideCrossIterator::operator==( ariel::MagicalContainer::SideCrossIterator other){       
        bool res = true;
        if(&(this)->container != &other.container){
            res = false;
        }
        if((this)->iPosition != other.iPosition){
            res = false;
        }
        return res;
        }
      
// CheckNEqual operator
bool ariel::MagicalContainer::SideCrossIterator::operator!=( ariel::MagicalContainer::SideCrossIterator other){
                    return !(*(this) == other);
        }
// Lt operator
bool ariel::MagicalContainer::SideCrossIterator::operator<( ariel::MagicalContainer::SideCrossIterator other){            
       return this->iPosition < other.iPosition;
        }

// Gt operator
bool ariel::MagicalContainer::SideCrossIterator::operator>( ariel::MagicalContainer::SideCrossIterator other){         
       return this->iPosition > other.iPosition;
        }

 //Move Assignment Operator  
ariel::MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator=(ariel::MagicalContainer::SideCrossIterator other){     
           if(&(this)->container != &other.container){
            throw runtime_error("different containers");
        }
        (this)->container = other.container;
        (this)->iPosition = other.iPosition;
        return *(this);
        }

        /// @brief  begin 
        /// @return the index if the begin contianer
ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::end(){       
         SideCrossIterator endIter(this->container);
            endIter.iPosition = container.size();
            return endIter;
        }
        /// @brief  end
        /// @return the index of last in the contianer
ariel::MagicalContainer::SideCrossIterator ariel::MagicalContainer::SideCrossIterator::begin(){      
          SideCrossIterator beginIter(this->container);
            beginIter.iPosition = 0; 
            return beginIter; 
        }
   






  ////////////////////////////////     ////////////////////////////////       ////////////////////////////////

      
//PrimeIterator Constructor
    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container):container(container) {
            if(container.size() == 0){
            (this)->iPosition = 0;
        }
        else{
            if(container.iPrimes.size() > 0){
                (this)->iPosition = container.iPrimes[0];
            }
            else{
                (this)->iPosition = container.size();
            }

        }
        (this)->p_Position = 0;
        }

//PrimeIterator Copy Constructor
    ariel::MagicalContainer::PrimeIterator::PrimeIterator(const ariel::MagicalContainer::PrimeIterator &other)
    :container(other.container),iPosition(other.iPosition),p_Position(other.p_Position){}

// get the value from this containe with specifec position ( only prime numbers )
int ariel::MagicalContainer::PrimeIterator::operator*()const{
            return (this)->container.elements[iPosition];
        }


// one new pos on the container operator
ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator++(){           
     if((this)->iPosition == (this)->end().iPosition){
                throw std::runtime_error("there no more prime numbers");
            }

            if((this)->p_Position+1 == container.iPrimes.size()){
                iPosition = end().iPosition;
                return *this;
            }        
            if((this)->p_Position < container.iPrimes.size()){
                (this)->p_Position++;
                (this)->iPosition = container.iPrimes[(this)->p_Position];
                return (*this);
            }
            else{
                throw std::runtime_error("there no more prime numbers");
            }
        }
    
    

// CheckEqual operator 
bool ariel::MagicalContainer::PrimeIterator::operator==( ariel::MagicalContainer::PrimeIterator other){
            bool res = true;
            if(&(this)->container != &other.container){
                res = false;
            }
            if((this)->iPosition != other.iPosition){
                res = false;
            }
            return res;
        }

// CheckNEqual operator    
bool ariel::MagicalContainer::PrimeIterator::operator!=( ariel::MagicalContainer::PrimeIterator other){
                return !(*(this) == other);
                }

// Lt operator
bool ariel::MagicalContainer::PrimeIterator::operator<( ariel::MagicalContainer::PrimeIterator other){
       return this->iPosition < other.iPosition;
        }

// Gt operator
bool ariel::MagicalContainer::PrimeIterator::operator>( ariel::MagicalContainer::PrimeIterator other){          
       return this->iPosition > other.iPosition;
        }

 //Move Assignment Operator  
ariel::MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator=(ariel::MagicalContainer::PrimeIterator other){    
               if(&(this)->container != &other.container){
                    throw runtime_error("Prineiterator:= throws when iterators are pointing at different containers");
                }
                (this)->container = other.container;
                (this)->iPosition = other.iPosition;
                (this)->p_Position = other.p_Position;
                return *(this);
            }

        /// @brief  end
        /// @return the index of last in the contianer 
        ariel::MagicalContainer::PrimeIterator ariel::MagicalContainer::PrimeIterator::end(){
                if(container.size() == 0){
                PrimeIterator iteratorP(this->container);
                iteratorP.iPosition = 0;
                return iteratorP;
                }

            if(container.iPrimes.size() > 0 || (this)->p_Position == container.iPrimes.size()){
                PrimeIterator iteratorP(this->container);
                iteratorP.iPosition = container.size();
                return iteratorP;
            }

            size_t l_ind = container.iPrimes.back();
            if(container.elements[l_ind]){ 
                PrimeIterator iteratorP(this->container);
                iteratorP.iPosition = l_ind+1;
                return iteratorP;
            }

            else{
                throw std::runtime_error("There no prime numbers in the container");
            }

        }

        /// @brief  begin 
        /// @return the index if the begin contianer
        MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
             if(container.iPrimes.size() > 0){
                PrimeIterator beginIter(this->container);
                beginIter.iPosition = container.iPrimes[0];
                return beginIter;
            }
            else{
                throw std::runtime_error("There no prime numbers in the container");
            }
        }


    };