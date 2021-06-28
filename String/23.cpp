#include <bits/stdc++.h>
using namespace std;
int utilitySearch(string word, int r, int c, string arr[], int maxR, int maxC, int index) {
   int count = 0;
   if (r >= 0 && r <= maxR && c >= 0) {
      if (c <= maxC && word[index] == arr[r][c]) {
         char res = word[index];
         index = index + 1;
         arr[r][c] = 0;
         if (word[index] == 0) {
            count = 1;
         } else {
            count = count + utilitySearch(word, r, c + 1, arr, maxR, maxC, index);
            count = count + utilitySearch(word, r, c - 1, arr, maxR, maxC, index);
            count = count + utilitySearch(word, r + 1, c, arr, maxR, maxC, index);
            count = count + utilitySearch(word, r - 1, c, arr, maxR, maxC, index);
         }
         arr[r][c] = res;
      }
   }
   return count;
}

int findString(string word, int r, int c, string str[], int countR, int countC) {
   int count = 0;
   for (int i = 0; i < countR; ++i) {
      for (int j = 0; j < countC; ++j) {
         count = count + utilitySearch(word, i, j, str, countR - 1, countC - 1, 0);
      }
   }
   return count;
}

int main() {
      string word = "FLOOD";
      string inp[] = {"FPLIOKOD",
                      "FLOODYUT", 
                      "YFLOODPU",
                      "FMLOSODT",
                      "FILPOYOD",
                      "FLOOOODE "
                     };
         string str[(sizeof(inp) / sizeof( * inp))];
         for (int i = 0; i < (sizeof(inp) / sizeof( * inp)); ++i) {
            str[i] = inp[i];
         }
         cout << "Count: " << findString(word, 0, 0, str, (sizeof(inp) / sizeof( * inp)), str[0].size());
         return 0;
}