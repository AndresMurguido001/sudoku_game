#include <vector>
#include <string>

using namespace std;
class Possible {
   vector<bool> _b;
public:
   Possible() : _b(9, true) {}
   bool   is_on(int i) const { return _b[i-1]; }
   int    count()      const { return std::count(_b.begin(), _b.end(), true); }
   void   eliminate(int i)   { _b[i-1] = false; }
   int    val()        const {
      auto it = find(_b.begin(), _b.end(), true);
      return (it != _b.end() ? 1 + (it - _b.begin()) : -1);
   }
   string str(int wth) const;
};

string Possible::str(int width) const {
   string s(width, ' ');
   int k = 0;
   for (int i = 1; i <= 9; i++) {
      if (is_on(i)) s[k++] = '0' + i;
   }
   return s;
} 

class Sudoku {
   vector<Possible> _cells;
   static vector< vector<int> > _group, _neighbors, _groups_of;

   bool     eliminate(int k, int val);
public:
   Sudoku(string s);
   static void init();

   Possible possible(int k) const { return _cells[k]; }
   bool     is_solved() const;
   bool     assign(int k, int val);
   int      least_count() const;
   void     write(ostream& o) const;
};
