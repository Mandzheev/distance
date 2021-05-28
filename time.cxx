#include <ctime>
#include <fstream>
#include <iostream>
#include <new>
#include <string>
using namespace std;

time_t current_time = time(0);

class Set_distance {
public:
  void write_time() {
    ofstream wr_t("start_time.txt", ios::app);
    wr_t << current_time << endl;
    wr_t.close();
  }

  void write_name() {
    ofstream wr_n("name_distance.txt", ios::app);
    cout << "enter name distance: ";
    string wn;
    getline(cin, wn);
    wr_n << wn << endl;
    wr_n.close();
  }
};

class Get_distance {
public:
  void num_line() {
    char *str = new char[1024];
    int i = 0;
    ifstream base("start_time.txt");
    while (!base.eof()) {
      base.getline(str, 1024, '\n');
      i++;
    }
    base.close();
    delete[] str;
    cout << i << '\n';
  }

  void to_dhms() {
string bu;
    time_t buff;
    ifstream rd_t("start_time.txt");
    ifstream rd_n("name_distance.txt");
    for (int i = 0; i < 10; i++) {
          rd_t >> buff;
          getline(rd_n,bu);
cout<< bu<<" ";
      time_t dist = current_time - buff;
      time_t day = dist / 86400;
      time_t hour = (dist - day * 86400) / 3600;
      time_t min = (dist - ((hour * 3600) + (day * 86400))) / 60;
      time_t sec = (dist - ((hour * 3600) + (min * 60) + (day * 86400)));
      cout << "D:" << day << " H:" << hour << " M:" << min << " S:" << sec
           << endl;
    }

    rd_t.close();
  }
};
int main() {
  Set_distance *create1;
  Get_distance *create2;
  try {
    create1 = new Set_distance();
  } catch (bad_alloc ba) {
    cout << "memory not alloc" << endl;
    cout << ba.what() << endl;
    return -1;
  }

  cout << "1) Create new distance" << endl;
  create1->write_name();
  create1->write_time();
  create2->to_dhms();
  delete create1;
}
