#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

time_t current_time = time(0);

class Create_distance {
    public:
  void start_time() {
    ofstream write("start_time.txt");
    write << current_time;
    write.close();
  }

  void distance (){
      time_t buff;
      ifstream read("start_time.txt");
      read >> buff;
      read.close();
      time_t dist = current_time - buff;
     cout<< dist<<endl; 
  }
};

int main() {
Create_distance create1;
int enter1;
cout<< "1) Create new distance"<<endl;
cout <<"Enter num:"<<endl;
cin >> enter1;
if (enter1==1) 
    create1.start_time();
else
    
create1.distance();
        

}
