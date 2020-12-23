#include <bits/stdc++.h>
using namespace std;

int predict(int page[], vector<int>& fr, int pn, int index) {

   int res = -1, farthest = index;
   for (int i = 0; i < fr.size(); i++) 
   {
      int j;
      for (j = index; j < pn; j++) 
      {
         if (fr[i] == page[j]) 
         {
            if (j > farthest) 
            {
               farthest = j;
               res = i;
            }
            break;
         }
      }
   
      if (j == pn)
         return i;
   }  
   return (res == -1) ? 0 : res;
}

bool search(int key, vector<int>& fr) 
{
   for (int i = 0; i < fr.size(); i++)
   if (fr[i] == key)
      return true;

   return false;
}

void opr(int page[], int pn, int fn) 
{
   vector<int> fr;
   int hit = 0;
   for (int i = 0; i < pn; i++) 
   {
      
      if (search(page[i], fr)) 
      {
         hit++;
         continue;
      }

      if (fr.size() < fn)
         fr.push_back(page[i]);
      else 
      {
         int j = predict(page, fr, pn, i + 1);
         fr[j] = page[i];
      }
   }

   cout << "Hits = " << hit << endl;
   cout << "Misses = " << pn - hit << endl;
}

int main() 
{
   int page[] = { 1, 7, 8, 3, 0, 2, 0, 3, 5, 4, 0, 6, 1 };
   int pn = sizeof(page) / sizeof(page[0]);
   int fn = 3;
   opr(page, pn, fn);
   return 0;
}