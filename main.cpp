#include <iostream>
#include<string.h>
using namespace std;

//used templates to make class generic
template<class T>

class vector{
    
    public:
    int index=0,count=0,total_count=0,flag=0,size_of_vector=0,free_flag=0;
    T* vect,*vect2;
    
    //paramterized constructor if size of vector is provided
    
    vector(int sizee)
    {
         vect = (T*)calloc(sizee,sizeof(T));
         size_of_vector = sizee;
         total_count = sizee;
         flag=1;
    }
    
    //default constructor if size is not provided
    
    vector()
    {
        
        //first allocate memory
        
        if(total_count==0 && flag==0)
        {
           vect = (T*)calloc(total_count+1,sizeof(T));
           count++;
           total_count = count*2;
        }
    }
    
    //function to push values into vector
    
    void push_back(T data)
    {
       //cout<<count<<endl;
       
       if(count>0 && flag==0)
       {
            //cout<<"count flag : "<<count<<endl;
            if(count==total_count)
            {
                vect = (T*)realloc(vect,( (count*2) * sizeof(T*) ));
                total_count = count*2;
            }
            vect[index] = data;
            index++;
            count++;
            return;
       }    
        
       //if size is provided for vector
       
       
       if(count==size_of_vector)
       {
            //if size is reached it's maximum limit then the size of vector should increase.    
            free_flag = 1;
            vect = (T*)realloc(vect,( (count*2) * sizeof(T*) ));
            
            //adding values in vect array(dynamically created)
            
            vect[index] = data;
            index++;
            total_count = count*2;
            count++;
            flag=0;
            return;
       }
       
       vect[index] = data;
       index++;
       count++;
    }
    
    //to find size of vector
    
    int size()
    {
        if(free_flag)
        {
            return size_of_vector+index;
        }
        return index;
    }
    //pop_back element from vector
    void pop_back()
    {
        index--;
    }
    //for printing all values in vector
    void print()
    {
        //free_flag is 1 means if size of vector has reached it's max limit and vector has to dynamically 
        //allocate extra memory then vector frees previous memory and allocates new 
        if(free_flag)
        {
            for(int i=0;i<size_of_vector;i++)
            {
                cout<<0<<" ";
            }
        }
        for(int i=0;i<index;i++)
        {
            cout<<vect[i]<<" ";
        }
    }
};

int main()
{
    vector<float> vt(3);
    
    vt.push_back(5.4);
    vt.push_back(6.2);
    vt.push_back(7.8);
    vt.push_back(8.1);
    vt.push_back(1.3);
    vt.push_back(7.3);
    vt.push_back(6.9);

    vt.pop_back();
    vt.pop_back();
    
    cout<<"size of vector : "<<vt.size()<<endl;
    cout<<"actual size allocated : "<<vt.total_count<<endl;
    vt.print();

    return 0;
}


